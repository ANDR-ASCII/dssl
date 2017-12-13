#pragma once

#include "main_window.h"

namespace DSSL
{

class MainWindow;

class Application : public QApplication
{
    Q_OBJECT

public:
    Application(int& argc, char** argv);

private:
    void initialize();

private:
    std::unique_ptr<MainWindow> m_mainWindow;
};

}