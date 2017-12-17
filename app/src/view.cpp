#include "view.h"

namespace DSSL
{

View::View(QWidget* parent)
    : QFrame(parent)
    , m_graphicsView(new QGraphicsView(this))
{
    m_graphicsView->setDragMode(QGraphicsView::RubberBandDrag);
    m_graphicsView->setOptimizationFlags(QGraphicsView::DontSavePainterState);
    m_graphicsView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    m_graphicsView->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    m_graphicsView->setRenderHint(QPainter::Antialiasing, true);
    m_graphicsView->setViewport(new QGLWidget(QGLFormat(QGL::SampleBuffers)));

    QVBoxLayout* layout = new QVBoxLayout(this);

    layout->setMargin(0);
    layout->setSpacing(0);
    layout->addWidget(m_graphicsView);
}

QGraphicsView* View::view() const
{
    return m_graphicsView;
}

}