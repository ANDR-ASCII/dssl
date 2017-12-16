#include "graphics_circle_item.h"
#include "circle_data.h"
#include "object_placement_calculator.h"

namespace DSSL
{

GraphicsCircleItem::GraphicsCircleItem(QGraphicsItem* parent)
    : GraphicsCircleItem(QRectF(0, 0, 100, 100), parent)
{
}

GraphicsCircleItem::GraphicsCircleItem(const QRectF& rect, QGraphicsItem* parent)
    : QGraphicsEllipseItem(rect, parent)
{
    Calculation::ObjectPlacementCalculator& objectPlacementCalculator = Calculation::ObjectPlacementCalculator::instance();

    m_associatedData = objectPlacementCalculator.addNewObject(x(), y());
}

GraphicsCircleItem::GraphicsCircleItem(qreal x, qreal y, qreal width, qreal height, QGraphicsItem* parent)
    : GraphicsCircleItem(QRectF(QPointF(x, y), QSizeF(width, height)), parent)
{
}

const Calculation::CircleData* GraphicsCircleItem::associatedData() const noexcept
{
    return m_associatedData;
}

}