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

public:
    GraphicsCircleItem(const QPointF& position, QGraphicsItem* parent = nullptr);

    virtual QPainterPath shape() const override;

    virtual QRectF boundingRect() const override;

    Q_INVOKABLE void onAboutCoordinatesChanged();

protected:
    virtual void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;

private:
    std::shared_ptr<CoordinateCircleMapper> m_dataMapper;

    QColor m_color;

    QColor m_borderColor;
};

}