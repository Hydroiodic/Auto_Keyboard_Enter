#include "TestAutoClick.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TestAutoClick w;
    w.show();
    return a.exec();
}
