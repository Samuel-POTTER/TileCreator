#include <QApplication>
#include "../src/include/window/Window.h"

int main(int ac, char** av)
{
	QApplication app(ac, av);
	WindowUI window;
	window.init();
	window.show();
	
	return app.exec();
}