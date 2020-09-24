
#include <QApplication>

#include "MainWindow.hpp"


int main(int argc, char **argv)
{
    QApplication app (argc, argv);

    MainWindow mainwin;

    return app.exec();
}


