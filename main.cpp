#include "dialog.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w;
//    w.setWindowFlags( Qt::FramelessWindowHint );
    w.resize(1280,720);
    w.show();
    return a.exec();
}
