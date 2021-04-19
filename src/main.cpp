#include <QApplication>
#include "../src/include/window/Window.h"

int main(int ac, char** av)
{
	QApplication app(ac, av);
	WindowUI window(800, 600);
	window.show();
	
	return app.exec();
}