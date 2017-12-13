#include "application.h"

int main(int argc, char** argv)
{
	DSSL::Application dsslApp(argc, argv);

	return dsslApp.exec();
}