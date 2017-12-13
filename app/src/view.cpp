#include "view.h"

namespace DSSL
{

View::View(QWidget* parent)
    : QFrame(parent)
    , m_graphicsView(new QGraphicsView(this))
{
    setFrameStyle(Sunken | StyledPanel);
    m_graphicsView->setRenderHint(QPainter::Antialiasing, false);
    m_graphicsView->setDragMode(QGraphicsView::RubberBandDrag);
    m_graphicsView->setOptimizationFlags(QGraphicsView::DontSavePainterState);
    m_graphicsView->setViewportUpdateMode(QGraphicsView::SmartViewportUpdate);
    m_graphicsView->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    m_graphicsView->setRenderHint(QPainter::Antialiasing, true);
}

QGraphicsView* View::view() const
{
    return m_graphicsView;
}

}