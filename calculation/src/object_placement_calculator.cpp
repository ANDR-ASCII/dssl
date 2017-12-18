#include "object_placement_calculator.h"

namespace
{

struct Point
{
    double x;
    double y;

    friend Point operator-(const Point& lhs, const Point& rhs)
    {
        return Point{ lhs.x - rhs.x, lhs.y - rhs.y };
    }

    friend double distance(const Point& lhs, const Point& rhs)
    {
        return std::sqrt(std::pow(lhs.x - rhs.x, 2) + std::pow(lhs.y - rhs.y, 2));
    }
};

}

namespace Calculation
{

ObjectPlacementCalculator& ObjectPlacementCalculator::instance()
{
    static std::unique_ptr<ObjectPlacementCalculator> s_instance(new ObjectPlacementCalculator);

    return *s_instance.get();
}

CircleData* ObjectPlacementCalculator::addNewObject(int x, int y)
{
    std::lock_guard<std::mutex> locker(m_mutex);

#ifdef HAS_CPP17

    return m_objects.emplace_back(new CircleData(x, y)).get();

#else

    m_objects.emplace_back(new CircleData(x, y));

    return m_objects.back().get();

#endif
}

void ObjectPlacementCalculator::calculateCycle()
{
    using namespace std::literals::chrono_literals;

    const auto force = [](const double distance)
    {
        return 1 / distance - 1 / std::pow(distance, 2);
    };

    while (m_needToCalculate.load())
    {
        while(!m_mutex.try_lock());

        for (std::unique_ptr<CircleData>& object : m_objects)
        {
            Point objectCoords{ static_cast<double>(object->x()), static_cast<double>(object->y()) };

            double accelerationByX = 0.0;
            double accelerationByY = 0.0;

            for (std::unique_ptr<CircleData>& object : m_objects)
            {
                Point relativeObjectCoords{ static_cast<double>(object->x()), static_cast<double>(object->y()) };

                const double distanceValue = distance(relativeObjectCoords, objectCoords);

                const double forceValue = distanceValue <= CircleData::radius() * 2 ? 0 : force(distanceValue);

                Point deltaPoint = relativeObjectCoords - objectCoords;

                const double alpha = std::atan2(deltaPoint.y, deltaPoint.x);

                accelerationByX += forceValue * std::cos(alpha);
                accelerationByY += forceValue * std::sin(alpha);
            }

            const auto timeDifference = 1000 / 60;

            const int newXCoord = static_cast<int>(object->x() + object->velocityByX() * timeDifference + accelerationByX * std::pow(timeDifference, 2) / 2);
            const int newYCoord = static_cast<int>(object->y() + object->velocityByY() * timeDifference + accelerationByY * std::pow(timeDifference, 2) / 2);

            object->setX(newXCoord);
            object->setY(newYCoord);

            object->setVelocityByX(object->velocityByX() + accelerationByX * timeDifference);
            object->setVelocityByY(object->velocityByY() + accelerationByY * timeDifference);
        }

        m_mutex.unlock();

        std::this_thread::sleep_for(30ms);
    }
}

void ObjectPlacementCalculator::start()
{
    if (m_needToCalculate.load())
    {
        return;
    }

    m_needToCalculate.store(true);

    m_calculateThread = std::thread(&ObjectPlacementCalculator::calculateCycle, this);
}

void ObjectPlacementCalculator::stop()
{
    m_needToCalculate.store(false);

    if (!m_calculateThread.joinable())
    {
        return;
    }

    m_calculateThread.join();
}

ObjectPlacementCalculator::ObjectPlacementCalculator()
    : m_needToCalculate(false)
{
}

ObjectPlacementCalculator::~ObjectPlacementCalculator()
{
    stop();
}

void ObjectPlacementCalculator::removeObject(CircleData* object)
{
    std::lock_guard<std::mutex> locker(m_mutex);

    auto newContainerEnd = std::remove_if(std::begin(m_objects), std::end(m_objects), 
        [object](const auto& existingObject) { return existingObject.get() == object; });

    m_objects.erase(newContainerEnd, std::end(m_objects));
}

}