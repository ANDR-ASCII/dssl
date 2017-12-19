#pragma once

#include "object_placement_calculator.h"

using namespace Calculation;

namespace CalculationTests
{

class TestObjectPlacementCalculator : public ObjectPlacementCalculator
{
public:
    TestObjectPlacementCalculator(std::size_t maxLoopCount);

protected:
    virtual bool canContinueCalculate() noexcept override;

private:
    using ObjectPlacementCalculator::instance;

private:
    std::size_t m_maxLoopCount;

    std::atomic<std::size_t> m_loopCount;
};

}