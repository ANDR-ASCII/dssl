#include "test_object_placement_calculator.h"

namespace CalculationTests
{

TestObjectPlacementCalculator::TestObjectPlacementCalculator(std::size_t maxLoopCount)
    : m_maxLoopCount(maxLoopCount)
    , m_loopCount(0)
{
}

bool TestObjectPlacementCalculator::canContinueCalculate() noexcept
{
    const bool result = m_loopCount++ < m_maxLoopCount;

    if (!result)
    {
        m_loopCount.store(0);
    }

    return result;
}

}