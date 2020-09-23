#include "notepad_tut.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Notepad_tut w;
    w.show();
    return a.exec();
}
