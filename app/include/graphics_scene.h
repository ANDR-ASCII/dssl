#pragma once

namespace DSSL
{

class GraphicsScene : public QGraphicsScene
{
    Q_OBJECT

public:
    GraphicsScene(QObject* parent = nullptr);

    GraphicsScene(const QRectF& sceneRect, QObject* parent = nullptr);

    GraphicsScene(qreal x, qreal y, qreal width, qreal height, QObject* parent = nullptr);

protected:
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent* event) override;

    virtual void mousePressEvent(QGraphicsSceneMouseEvent* event) override;

    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent* event) override;

    virtual void timerEvent(QTimerEvent* event) override;

private:
    QGraphicsItem* m_aquiredItem;

    int m_timeId;
};

}