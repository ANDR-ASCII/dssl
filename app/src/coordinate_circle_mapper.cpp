#include "coordinate_circle_mapper.h"
#include "circle_data.h"
#include "graphics_circle_item.h"

namespace DSSL
{

CoordinateCircleMapper::CoordinateCircleMapper(GraphicsCircleItem* item, Calculation::CircleData* associatedData)
    : m_item(item)
    , m_associatedData(associatedData)
{
    using namespace std::literals::chrono_literals;

    DEBUG_ASSERT(associatedData);

    VERIFY(QMetaObject::invokeMethod(this, "initialize", Qt::QueuedConnection));

    startTimer(21ms);
}

Calculation::CircleData* CoordinateCircleMapper::associatedData() const noexcept
{
    return m_associatedData;
}

void CoordinateCircleMapper::onAboutNotifyObjectChanged()
{
    ++m_updateNotificationCounter;
}

void CoordinateCircleMapper::timerEvent(QTimerEvent*)
{
    if (m_updateNotificationCounter.load() > 0)
    {
        VERIFY(QMetaObject::invokeMethod(m_item, "onAboutCoordinatesChanged", Qt::QueuedConnection));

        --m_updateNotificationCounter;
    }
}

void CoordinateCircleMapper::initialize()
{
    m_associatedData->attachObserver(shared_from_this());
}

}