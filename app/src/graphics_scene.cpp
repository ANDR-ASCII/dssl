#include "graphics_scene.h"
#include "graphics_circle_item.h"
#include "circle_data.h"

namespace DSSL
{

void GraphicsScene::dragEnterEvent(QGraphicsSceneDragDropEvent* event)
{
    QGraphicsScene::dragEnterEvent(event);
}

void GraphicsScene::dragMoveEvent(QGraphicsSceneDragDropEvent* event)
{
    QGraphicsScene::dragMoveEvent(event);
}

void GraphicsScene::dragLeaveEvent(QGraphicsSceneDragDropEvent* event)
{
    QGraphicsScene::dragLeaveEvent(event);
}

void GraphicsScene::mouseMoveEvent(QGraphicsSceneMouseEvent* event)
{
    QGraphicsScene::mouseMoveEvent(event);
}

void GraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
    QGraphicsScene::mousePressEvent(event);
}

void GraphicsScene::mouseReleaseEvent(QGraphicsSceneMouseEvent* event)
{
    QPointF position = event->scenePos();

    QGraphicsItem* item = new GraphicsCircleItem(
        position.x() - Calculation::CircleData::radius() / 2,
        position.y() - Calculation::CircleData::radius() / 2,
        Calculation::CircleData::radius(),
        Calculation::CircleData::radius()
    );

    addItem(item);
}

}