#include "circle_data.h"
#include "test_object_placement_calculator.h"

using namespace Calculation;
using namespace CalculationTests;
using namespace std::literals::chrono_literals;

TEST(CalculationTests, RepeatnessTest)
{
    //
    // All calculation results must be the same with the
    // the same source data and the same iterations
    //

    TestObjectPlacementCalculator objectPlacementCalculator(100);

    const auto calculate = [&objectPlacementCalculator]
    {
        std::vector<CircleData*> circleData;

        circleData.push_back(objectPlacementCalculator.addNewObject(-100, 100));
        circleData.push_back(objectPlacementCalculator.addNewObject(-100, -100));
        circleData.push_back(objectPlacementCalculator.addNewObject(100, -100));
        circleData.push_back(objectPlacementCalculator.addNewObject(100, 100));

        objectPlacementCalculator.start();

        objectPlacementCalculator.wait();

        std::vector<CircleData> result;

        for (std::size_t i = 0; i < circleData.size(); ++i)
        {
            result.push_back(*circleData[i]);
        }

        objectPlacementCalculator.removeObjects();

        return result;
    };

    const std::vector<CircleData> firstResult = calculate();
    const std::vector<CircleData> secondResult = calculate();

    EXPECT_EQ(firstResult, secondResult);
}

int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}