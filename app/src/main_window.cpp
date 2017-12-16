#include "main_window.h"
#include "helpers.h"
#include "view.h"
#include "graphics_scene.h"
#include "graphics_circle_item.h"

namespace DSSL
{

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
    , m_scene(new GraphicsScene(this))
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