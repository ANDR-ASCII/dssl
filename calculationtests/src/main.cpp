#include "circle_data.h"
#include "test_object_placement_calculator.h"

using namespace Calculation;
using namespace CalculationTests;

TEST(CalculationTests, RepeatnessTest)
{
    using namespace std::literals::chrono_literals;

    TestObjectPlacementCalculator objectPlacementCalculator(100);

    const auto calculate = [&objectPlacementCalculator]
    {
        std::vector<CircleData*> circleData;

        circleData.push_back(objectPlacementCalculator.addNewObject(-100, 100));
        circleData.push_back(objectPlacementCalculator.addNewObject(-100, -100));
        circleData.push_back(objectPlacementCalculator.addNewObject(100, -100));
        circleData.push_back(objectPlacementCalculator.addNewObject(100, 100));

        objectPlacementCalculator.start();

        while (objectPlacementCalculator.isRunning())
        {
            std::this_thread::sleep_for(10ms);
        }

        std::vector<CircleData> result;

        for (std::size_t i = 0; i < circleData.size(); ++i)
        {
            result.push_back(*circleData[i]);
        }

        std::for_each(circleData.begin(), circleData.end(), [&objectPlacementCalculator](CircleData* data) 
        { 
            objectPlacementCalculator.removeObject(data); 
        });

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