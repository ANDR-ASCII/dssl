#pragma once

#include "circle_data.h"

namespace Calculation
{

class ObjectPlacementCalculator
{
public:
    static ObjectPlacementCalculator& instance();

    ~ObjectPlacementCalculator();

    CircleData* addNewObject(int x, int y);

    void removeObject(CircleData* object);

    void start() noexcept;

    void stop() noexcept;

    bool isRunning() const noexcept;

protected:
    ObjectPlacementCalculator();

    virtual bool canContinueCalculate() noexcept;

private:
    void calculateLoop();

private:
    std::vector<std::unique_ptr<CircleData>> m_objects;

    std::mutex m_mutex;

    std::atomic_bool m_needToCalculate;

    std::thread m_calculateThread;
};

}