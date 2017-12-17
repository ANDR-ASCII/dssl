#include "circle_data.h"

namespace
{

constexpr std::size_t s_radius = 20;

}

namespace Calculation
{

CircleData::CircleData(int x, int y)
    : m_x(x)
    , m_y(y)
{
}

std::size_t CircleData::radius() noexcept
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
}

int CircleData::y() const noexcept
{
    return m_y.load();
}

void CircleData::setY(int value) noexcept
{
    m_y.store(value);
}

}