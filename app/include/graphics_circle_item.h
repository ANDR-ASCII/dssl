#pragma once

namespace Calculation
{

class CircleData;

}

namespace DSSL
{

class GraphicsCircleItem : public QGraphicsItem
{
public:
    GraphicsCircleItem(const QPointF& position, QGraphicsItem* parent = nullptr);

    ~GraphicsCircleItem();

    Calculation::CircleData* associatedData() const noexcept;

    virtual QPainterPath shape() const override;

    virtual QRectF boundingRect() const override;

protected:
    virtual void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;

private:
    Calculation::CircleData* m_associatedData;

    QColor m_color;

    QColor m_borderColor;
};

}