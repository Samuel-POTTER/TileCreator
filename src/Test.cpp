#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QWidget window;
    window.resize(320, 240);
    window.show();
    window.setWindowTitle(
        QApplication::translate("PREMAKE DE SES MORTS", "PREMAKE DE SES MORTS"));
    return app.exec();
}