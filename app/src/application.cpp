#include "application.h"

namespace DSSL
{

Application::Application(int& argc, char** argv)
	: QApplication(argc, argv)
{
	initialize();
}

Application::~Application()
{
}

void Application::initialize()
{

}

}
