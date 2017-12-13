#include "main_window.h"
#include "helpers.h"
#include "view.h"

namespace DSSL
{

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
    , m_scene(new QGraphicsScene(this))
{
    QHBoxLayout* layout = new QHBoxLayout(this);

    setWindowTitle(tr("DSSL Example"));

    const QSize minimumSize(Helpers::pointsToPixels(400), Helpers::pointsToPixels(200));
    setMinimumSize(minimumSize);

    View* view = new View;
    view->view()->setScene(m_scene);

    layout->addWidget(view);
}

}