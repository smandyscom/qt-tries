#include "mainwindow.h"
#include <QApplication>

#include <commonhelper.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // 加载QSS样式
    //CommonHelper::setStyle("/Users/Apple/Github/qt-tries/try-property-bind/style2.qss");

    MainWindow w;
    w.show();

    return a.exec();
}
