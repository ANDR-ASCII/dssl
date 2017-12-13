#pragma once

namespace DSSL
{

class Application : public QApplication
{
	Q_OBJECT

public:
	Application(int& argc, char** argv);
	~Application();

private:
	void initialize();
};

}