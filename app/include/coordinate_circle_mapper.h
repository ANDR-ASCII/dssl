#pragma once

#include "iobserver.h"

namespace Calculation
{

class CircleData;

}

namespace DSSL
{

class GraphicsCircleItem;

class CoordinateCircleMapper 
    : public QObject
    , public Calculation::IObserver
    , public std::enable_shared_from_this<CoordinateCircleMapper>
{
    Q_OBJECT

public:
    CoordinateCircleMapper(GraphicsCircleItem* item, Calculation::CircleData* associatedData);

    ~CoordinateCircleMapper();

    Calculation::CircleData* associatedData() const noexcept;

    virtual void onAboutNotifyObjectChanged() override;

signals:
    void coordinatesChanged();

private slots:
    void initialize();

private:
    GraphicsCircleItem* m_item;

    Calculation::CircleData* m_associatedData;
};

}