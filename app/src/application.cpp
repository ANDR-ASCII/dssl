#include "application.h"

namespace DSSL
{

Application::Application(int& argc, char** argv)
    : QApplication(argc, argv)
    , m_mainWindow(new MainWindow)
{
    qsrand(QDateTime::currentMSecsSinceEpoch() / 1000);

    m_mainWindow->show();
}

}
