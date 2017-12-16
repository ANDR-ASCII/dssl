#pragma once

namespace Calculation
{

class CircleData
{
public:
    CircleData(int x, int y);

    static std::size_t radius() noexcept;

    int x() const noexcept;
    void setX(int value) noexcept;

    int y() const noexcept;
    void setY(int value) noexcept;

private:
    std::atomic_int m_x;

    std::atomic_int m_y;
};

}