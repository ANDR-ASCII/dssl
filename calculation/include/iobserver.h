#pragma once

namespace Calculation
{

class IObserver
{
public:
    virtual void onAboutNotifyObjectChanged() = 0;
};

}