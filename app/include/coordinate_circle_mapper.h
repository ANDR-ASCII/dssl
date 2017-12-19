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

    Calculation::CircleData* associatedData() const noexcept;

    virtual void onAboutNotifyObjectChanged() override;

signals:
    void coordinatesChanged();

protected:
    virtual void timerEvent(QTimerEvent* event) override;

private slots:
    void initialize();

private:
    QPointer<GraphicsCircleItem> m_item;

    Calculation::CircleData* m_associatedData;

    std::atomic<std::size_t> m_updateNotificationCounter;
};

}