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
    , m_timeId(0)
    , m_showItemInfo(true)
    , m_itemAquired(false)
{
    m_timeId = startTimer(50);
    DEBUG_ASSERT(m_timeId);
}

GraphicsScene::GraphicsScene(qreal x, qreal y, qreal width, qreal height, QObject* parent)
    : GraphicsScene(QRectF(QPointF(x, y), QSizeF(width, height)), parent)
{
}

bool GraphicsScene::showItemInfo() const
{
    return m_showItemInfo;
}

void GraphicsScene::setShowItemInfo(bool value)
{
    m_showItemInfo = value;

    update();

    emit showItemInfoChanged(m_showItemInfo);
}


void GraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
    QGraphicsItem* existingItem = itemAt(event->scenePos(), QTransform());

    if (event->button() == Qt::RightButton)
    {
        if (existingItem)
        {
            removeItem(existingItem);
        }
        else
        {
            const QPointF itemPosition(
                event->scenePos().x() - Calculation::CircleData::radius() / 2,
                event->scenePos().y() - Calculation::CircleData::radius() / 2
            );

            addCircle(itemPosition);
        }

        return;
    }

    QGraphicsScene::mousePressEvent(event);
}

void GraphicsScene::timerEvent(QTimerEvent* event)
{
    advance();
}

void GraphicsScene::addCircle(const QPointF& position)
{
    GraphicsCircleItem* item = new GraphicsCircleItem(position);

    item->setShowDetailedInfo(showItemInfo());

    VERIFY(connect(this, SIGNAL(showItemInfoChanged(bool)), item, SLOT(setShowDetailedInfo(bool))));

    addItem(item);
}

}