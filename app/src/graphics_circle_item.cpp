#include "graphics_circle_item.h"
#include "circle_data.h"
#include "object_placement_calculator.h"
#include "helpers.h"
#include "coordinate_circle_mapper.h"

namespace DSSL
{

GraphicsCircleItem::GraphicsCircleItem(const QPointF& position, QGraphicsItem* parent)
    : QGraphicsItem(parent)
    , m_color(Helpers::randomColor())
    , m_borderColor(Helpers::randomColor())
	, m_showDetailedInfo(true)
{
    setPos(position);

    Calculation::ObjectPlacementCalculator& objectPlacementCalculator = Calculation::ObjectPlacementCalculator::instance();

    m_dataMapper = std::make_shared<CoordinateCircleMapper>(this, objectPlacementCalculator.addNewObject(position.x(), position.y()));
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

bool GraphicsCircleItem::showDetailedInfo() const
{
    return m_showDetailedInfo;
}

void GraphicsCircleItem::setShowDetailedInfo(bool value)
{
    m_showDetailedInfo = value;

    emit showDetailedInfoChanged(m_showDetailedInfo);
}

void GraphicsCircleItem::onAboutCoordinatesChanged()
{
    setX(m_dataMapper->associatedData()->x());

    setY(m_dataMapper->associatedData()->y());
}

void GraphicsCircleItem::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    const int radius = static_cast<int>(Calculation::CircleData::radius());

    painter->setPen(m_borderColor);

    painter->setBrush(m_color);

    painter->drawEllipse(-radius, -radius, 2 * radius, 2 * radius);

    if (!showDetailedInfo())
    {
        return;
    }

    const QBrush textBrush(QColor("#333333"));
    const QPen textPen(textBrush, 5, Qt::SolidLine, Qt::SquareCap, Qt::MiterJoin);

    painter->setPen(textPen);

    painter->drawText(0, -Calculation::CircleData::radius() - Helpers::pointsToPixels(5),
        tr("X = %1 Y = %2 VX = %3 VY = %4")
        .arg(m_dataMapper->associatedData()->x())
        .arg(m_dataMapper->associatedData()->y())
        .arg(m_dataMapper->associatedData()->velocityByX())
        .arg(m_dataMapper->associatedData()->velocityByY())
    );
}

}