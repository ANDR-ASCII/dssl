#pragma once

#include "circle_data.h"

namespace Calculation
{

class ObjectPlacementCalculator final
{
public:
    static ObjectPlacementCalculator& instance();

    ~ObjectPlacementCalculator();

    CircleData* addNewObject(int x, int y);

    void start();

    void stop();

private:
    ObjectPlacementCalculator();

    void calculateCycle();

private:
    std::vector<std::unique_ptr<CircleData>> m_objects;

    std::mutex m_mutex;

    std::atomic_bool m_needToCalculate;

    std::thread m_calculateThread;
};

}