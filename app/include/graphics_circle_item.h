#pragma once

namespace Calculation
{

class CircleData;

}

namespace DSSL
{

class CoordinateCircleMapper;

class GraphicsCircleItem : public QObject, public QGraphicsItem
{
    Q_OBJECT

    Q_PROPERTY(bool showDetailedInfo READ showDetailedInfo WRITE setShowDetailedInfo NOTIFY showDetailedInfoChanged);

public:
    GraphicsCircleItem(const QPointF& position, QGraphicsItem* parent = nullptr);

    virtual QPainterPath shape() const override;

    virtual QRectF boundingRect() const override;

    bool showDetailedInfo() const;

    Q_SLOT void setShowDetailedInfo(bool value);

    Q_SIGNAL void showDetailedInfoChanged(bool);

    Q_INVOKABLE void onAboutCoordinatesChanged();

protected:
    virtual void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;

    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent* event) override;

    virtual void mousePressEvent(QGraphicsSceneMouseEvent* event) override;

    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent* event) override;

private:
    void setPositionInternal(const QPointF& position);

private:
    std::shared_ptr<CoordinateCircleMapper> m_dataMapper;

    QColor m_color;

    QColor m_borderColor;

    bool m_showDetailedInfo;

    bool m_isMoving;
};

}