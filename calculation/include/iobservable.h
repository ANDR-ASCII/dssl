#pragma once

namespace Calculation
{

class IObserver;

class IObservable
{
public:
    virtual ~IObservable() = default;

    virtual void attachObserver(const std::shared_ptr<IObserver>& observer) = 0;

    virtual void detachObserver(const std::shared_ptr<IObserver>& observer) = 0;

    virtual void notifyObjectChanged() = 0;
};

}