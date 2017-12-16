#pragma once

namespace DSSL
{

class GraphicsScene : public QGraphicsScene
{
    Q_OBJECT

public:
    using QGraphicsScene::QGraphicsScene;

protected:
    virtual void dragEnterEvent(QGraphicsSceneDragDropEvent* event) override;

    virtual void dragMoveEvent(QGraphicsSceneDragDropEvent* event) override;

    virtual void dragLeaveEvent(QGraphicsSceneDragDropEvent* event) override;

    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent* event) override;

    virtual void mousePressEvent(QGraphicsSceneMouseEvent* event) override;

    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent* event) override;
};

}