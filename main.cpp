#include "ClassicCryptography.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ClassicCryptography w;
    w.show();
    return a.exec();
}
