#include "graphics_scene.h"
#include "graphics_circle_item.h"
#include "circle_data.h"
#include "helpers.h"

namespace DSSL
{

GraphicsScene::GraphicsScene(QObject* parent)
    : GraphicsScene(QRectF(QPointF(0, 0), QSizeF(0, 0)), parent)
{
}

GraphicsScene::GraphicsScene(const QRectF& sceneRect, QObject* parent)
    : QGraphicsScene(sceneRect, parent)
    , m_aquiredItem(nullptr)
    , m_timeId(0)
{
    m_timeId = startTimer(50);
    DEBUG_ASSERT(m_timeId);
}

GraphicsScene::GraphicsScene(qreal x, qreal y, qreal width, qreal height, QObject* parent)
    : GraphicsScene(QRectF(QPointF(x, y), QSizeF(width, height)), parent)
{
}

void GraphicsScene::mouseMoveEvent(QGraphicsSceneMouseEvent* event)
{
    if (m_aquiredItem)
    {
        GraphicsCircleItem* item = Helpers::fast_cast<GraphicsCircleItem*>(m_aquiredItem);

        item->setX(event->scenePos().x());
        item->setY(event->scenePos().y());

        return;
    }

    QGraphicsScene::mouseMoveEvent(event);
}

void GraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
    if (m_aquiredItem = itemAt(event->scenePos(), QTransform()); m_aquiredItem)
    {
        return;
    }

    QGraphicsScene::mousePressEvent(event);
}

void GraphicsScene::mouseReleaseEvent(QGraphicsSceneMouseEvent* event)
{
    if (m_aquiredItem)
    {
        m_aquiredItem = nullptr;

        return;
    }

    const QPointF centerPosition = event->scenePos();
    const QPointF leftRadiusPosition(centerPosition.x() - Calculation::CircleData::radius() / 2, centerPosition.y());
    const QPointF topRadiusPosition(centerPosition.x(), centerPosition.y() - Calculation::CircleData::radius() / 2);
    const QPointF rightRadiusPosition(centerPosition.x() + Calculation::CircleData::radius() / 2, centerPosition.y());
    const QPointF bottomRadiusPosition(centerPosition.x(), centerPosition.y() + Calculation::CircleData::radius() / 2);

    if (QGraphicsItem* existingItem = itemAt(centerPosition, QTransform()); existingItem)
    {
        removeItem(existingItem);

        return;
    }

    //
    // This is not the end of the correct solution of the problem
    // But for simplicity I omit these nuances
    //
    if (itemAt(leftRadiusPosition, QTransform()) ||
        itemAt(topRadiusPosition, QTransform()) ||
        itemAt(rightRadiusPosition, QTransform()) ||
        itemAt(bottomRadiusPosition, QTransform()))
    {
        return;
    }

    const QPointF itemPosition(
        event->scenePos().x() - Calculation::CircleData::radius() / 2,
        event->scenePos().y() - Calculation::CircleData::radius() / 2
    );

    QGraphicsItem* item = new GraphicsCircleItem(itemPosition);

    addItem(item);
}

void GraphicsScene::timerEvent(QTimerEvent* event)
{
    advance();
}

}