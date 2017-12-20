#include "circle_data.h"

namespace
{

constexpr int s_radius = 20;

}

namespace Calculation
{

CircleData::CircleData(int x, int y) noexcept
    : m_x(x)
    , m_y(y)
    , m_velocityByX(0)
    , m_velocityByY(0)
    , m_calculationBlocked(false)
{
}

CircleData::CircleData(const CircleData& other) noexcept
    : m_x(other.m_x.load())
    , m_y(other.m_y.load())
    , m_velocityByX(other.m_velocityByX.load())
    , m_velocityByY(other.m_velocityByY.load())
    , m_calculationBlocked(other.m_calculationBlocked.load())
{
}

int CircleData::radius() noexcept
{
    return s_radius;
}

int CircleData::x() const noexcept
{
    return m_x.load();
}

void CircleData::setX(int value) noexcept
{
    m_x.store(value);

    notifyObjectChanged();
}

int CircleData::y() const noexcept
{
    return m_y.load();
}

void CircleData::setY(int value) noexcept
{
    m_y.store(value);

    notifyObjectChanged();
}

double CircleData::velocityByX() const noexcept
{
    return m_velocityByX.load();
}

void CircleData::setVelocityByX(double value) noexcept
{
    m_velocityByX.store(value);

    notifyObjectChanged();
}

double CircleData::velocityByY() const noexcept
{
    return m_velocityByY.load();
}

void CircleData::setVelocityByY(double value) noexcept
{
    m_velocityByY.store(value);

    notifyObjectChanged();
}

void CircleData::setCalculationBlocked(bool value) noexcept
{
    m_calculationBlocked.store(value);
}

bool CircleData::isCalculationBlocked() const noexcept
{
    return m_calculationBlocked.load();
}

std::ostream& operator<<(std::ostream& out, const CircleData& circleData)
{
    out << "x: " << circleData.x() << std::endl;
    out << "y: " << circleData.y() << std::endl;
    out << "vx: " << circleData.velocityByX() << std::endl;
    out << "vy: " << circleData.velocityByY() << std::endl;

    return out;
}

bool operator==(const CircleData& lhs, const CircleData& rhs) noexcept
{
    const auto doubleComparison = [](double d1, double d2)
    {
        return std::fabs(d1 - d2) <= std::numeric_limits<double>::epsilon();
    };

    return
        lhs.x() == rhs.x() &&
        lhs.y() == rhs.y() &&
        doubleComparison(lhs.velocityByX(), rhs.velocityByX()) &&
        doubleComparison(lhs.velocityByY(), rhs.velocityByY());
}

}