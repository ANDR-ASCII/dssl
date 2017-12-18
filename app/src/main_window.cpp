#include "main_window.h"
#include "helpers.h"
#include "view.h"
#include "graphics_scene.h"
#include "graphics_circle_item.h"
#include "object_placement_calculator.h"

namespace DSSL
{

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
    , m_scene(new GraphicsScene(this))
{
    QVBoxLayout* layout = new QVBoxLayout(this);

    setWindowTitle(tr("DSSL Example"));

    const QSize minMaxSize(Helpers::pointsToPixels(600), Helpers::pointsToPixels(600));

    setMinimumSize(minMaxSize);

    View* view = new View;
    view->view()->setScene(m_scene);

    QPushButton* startCalculationButton = new QPushButton(tr("Start Calculation"), this);
    QPushButton* stopCalculationButton = new QPushButton(tr("Stop Calculation"), this);

    QHBoxLayout* buttonsLayout = new QHBoxLayout;
    buttonsLayout->addWidget(startCalculationButton);
    buttonsLayout->addWidget(stopCalculationButton);

    VERIFY(connect(startCalculationButton, &QPushButton::clicked, this, &MainWindow::onClickStartButton));
    VERIFY(connect(stopCalculationButton, &QPushButton::clicked, this, &MainWindow::onClickStopButton));

    layout->addLayout(buttonsLayout);
    layout->addWidget(view);
}

void MainWindow::onClickStartButton()
{
    Calculation::ObjectPlacementCalculator::instance().start();
}

void MainWindow::onClickStopButton()
{
    Calculation::ObjectPlacementCalculator::instance().stop();
}

}