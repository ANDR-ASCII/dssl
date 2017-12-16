#include "application.h"

namespace DSSL
{

Application::Application(int& argc, char** argv)
    : QApplication(argc, argv)
    , m_mainWindow(new MainWindow)
{
    m_mainWindow->show();
}

}
