#include "graphics_circle_item.h"
#include "circle_data.h"
#include "object_placement_calculator.h"
#include "helpers.h"

namespace DSSL
{

GraphicsCircleItem::GraphicsCircleItem(const QPointF& position, QGraphicsItem* parent)
    : QGraphicsItem(parent)
    , m_color(Helpers::randomColor())
    , m_borderColor(Helpers::randomColor())
{
    setPos(position);

    Calculation::ObjectPlacementCalculator& objectPlacementCalculator = Calculation::ObjectPlacementCalculator::instance();

    m_associatedData = objectPlacementCalculator.addNewObject(position.x(), position.y());
}

GraphicsCircleItem::~GraphicsCircleItem()
{
    Calculation::ObjectPlacementCalculator::instance().removeObject(m_associatedData);
}

Calculation::CircleData* GraphicsCircleItem::associatedData() const noexcept
{
    return m_associatedData;
}

QPainterPath GraphicsCircleItem::shape() const
{
    QPainterPath path;
    
    path.addEllipse(boundingRect());

    return path;
}

QRectF GraphicsCircleItem::boundingRect() const
{
    const int radius = static_cast<int>(Calculation::CircleData::radius());

    return QRectF(-radius, -radius, 2 * radius, 2 * radius);
}

void GraphicsCircleItem::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    const int radius = static_cast<int>(Calculation::CircleData::radius());

    painter->setPen(m_borderColor);
    painter->setBrush(m_color);
    painter->drawEllipse(-radius, -radius, 2 * radius, 2 * radius);
}

}