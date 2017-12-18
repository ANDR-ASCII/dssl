#include "coordinate_circle_mapper.h"
#include "circle_data.h"
#include "graphics_circle_item.h"

namespace DSSL
{

CoordinateCircleMapper::CoordinateCircleMapper(GraphicsCircleItem* item, Calculation::CircleData* associatedData)
    : m_item(item)
    , m_associatedData(associatedData)
{
    DEBUG_ASSERT(associatedData);

    VERIFY(QMetaObject::invokeMethod(this, "initialize", Qt::QueuedConnection));
}

Calculation::CircleData* CoordinateCircleMapper::associatedData() const noexcept
{
    return m_associatedData;
}

void CoordinateCircleMapper::onAboutNotifyObjectChanged()
{
    if (!m_item)
    {
        return;
    }

    //
    // TODO: At this stage m_item can be null
    //

    VERIFY(QMetaObject::invokeMethod(m_item, "onAboutCoordinatesChanged", Qt::QueuedConnection));
}

void CoordinateCircleMapper::initialize()
{
    m_associatedData->attachObserver(shared_from_this());
}

}