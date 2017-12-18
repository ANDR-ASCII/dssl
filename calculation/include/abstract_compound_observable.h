#pragma once

#include "iobservable.h"

namespace Calculation
{

class AbstractCompoundObservable : public IObservable
{
public:
    virtual void attachObserver(const std::shared_ptr<IObserver>& observer) override;

    virtual void detachObserver(const std::shared_ptr<IObserver>& observer) override;

    virtual void notifyObjectChanged() override;

private:
    std::vector<std::shared_ptr<IObserver>> m_observers;
};

}