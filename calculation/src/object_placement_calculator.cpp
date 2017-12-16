#include "object_placement_calculator.h"

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
    while (m_needToCalculate.load())
    {

    }
}

void ObjectPlacementCalculator::start()
{
    m_needToCalculate.store(true);

    m_calculateThread = std::thread(&ObjectPlacementCalculator::calculateCycle, this);
}

void ObjectPlacementCalculator::stop()
{
    m_needToCalculate.store(true);

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

}