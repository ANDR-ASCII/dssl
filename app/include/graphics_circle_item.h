#pragma once

namespace Calculation
{

class CircleData;

}

namespace DSSL
{

class GraphicsCircleItem : public QGraphicsEllipseItem
{
public:
    GraphicsCircleItem(QGraphicsItem* parent = nullptr);

    GraphicsCircleItem(const QRectF& rect, QGraphicsItem* parent = nullptr);

    GraphicsCircleItem(qreal x, qreal y, qreal width, qreal height, QGraphicsItem* parent = nullptr);

    const Calculation::CircleData* associatedData() const noexcept;

private:
    Calculation::CircleData* m_associatedData;
};

}