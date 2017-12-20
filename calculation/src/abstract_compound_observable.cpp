#include "abstract_compound_observable.h"
#include "iobserver.h"

namespace Calculation
{

void AbstractCompoundObservable::attachObserver(const std::shared_ptr<IObserver>& observer)
{
    auto findIterator = std::find(m_observers.begin(), m_observers.end(), observer);

    DEBUG_ASSERT(findIterator == m_observers.end());

    m_observers.push_back(observer);
}

void AbstractCompoundObservable::detachObserver(const std::shared_ptr<IObserver>& observer)
{
    auto findIterator = std::find(m_observers.begin(), m_observers.end(), observer);

    DEBUG_ASSERT(findIterator != m_observers.end());

    m_observers.erase(findIterator);
}

void AbstractCompoundObservable::notifyObjectChanged()
{
//     auto loopBody = [](const std::shared_ptr<IObserver>& observer) 
//     {
//         observer->onAboutNotifyObjectChanged();
//     };
// 
//     std::for_each(m_observers.begin(), m_observers.end(), loopBody);
}

}