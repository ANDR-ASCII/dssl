#pragma once

namespace DSSL
{

class View : public QFrame
{
    Q_OBJECT

public:
    View(QWidget* parent = nullptr);

    QGraphicsView* view() const;

private:
    QGraphicsView* m_graphicsView;
};

}