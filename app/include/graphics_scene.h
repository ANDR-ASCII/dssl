#pragma once

namespace DSSL
{

class GraphicsScene : public QGraphicsScene
{
    Q_OBJECT

    Q_PROPERTY(bool showItemInfo READ showItemInfo WRITE setShowItemInfo NOTIFY showItemInfoChanged);

public:
    GraphicsScene(QObject* parent = nullptr);

    GraphicsScene(const QRectF& sceneRect, QObject* parent = nullptr);

    GraphicsScene(qreal x, qreal y, qreal width, qreal height, QObject* parent = nullptr);

    bool showItemInfo() const;

    Q_SLOT void setShowItemInfo(bool value);

    Q_SIGNAL void showItemInfoChanged(bool value);

protected:
    virtual void mousePressEvent(QGraphicsSceneMouseEvent* event) override;

    //virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent* event) override;

    virtual void timerEvent(QTimerEvent* event) override;

private:
    void addCircle(const QPointF& position);

private:
    int m_timeId;

    bool m_showItemInfo;

    bool m_itemAquired;
};

}