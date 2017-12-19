#pragma once

#include "abstract_compound_observable.h"

namespace Calculation
{

class CircleData : public AbstractCompoundObservable
{
public:
    CircleData(int x, int y) noexcept;

    CircleData(const CircleData& other) noexcept;

    static int radius() noexcept;

    int x() const noexcept;
    void setX(int value) noexcept;

    int y() const noexcept;
    void setY(int value) noexcept;

    double velocityByX() const noexcept;
    void setVelocityByX(double value) noexcept;

    double velocityByY() const noexcept;
    void setVelocityByY(double value) noexcept;

    friend std::ostream& operator<<(std::ostream& out, const CircleData& circleData);

    friend bool operator==(const CircleData& lhs, const CircleData& rhs) noexcept;

private:
    std::atomic<int> m_x;

    std::atomic<int> m_y;

    std::atomic<double> m_velocityByX;

    std::atomic<double> m_velocityByY;
};

}