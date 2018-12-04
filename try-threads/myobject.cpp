#include "myobject.h"
#include <QDebug>

MyObject::MyObject(QObject *parent) : QObject(parent)
{
    timer = new QTimer(this);
    connect(timer,&QTimer::timeout,this,&MyObject::onTimeout);
    timer->start(5000);
}

void MyObject::onTimeout()
{
    qDebug() << QString("%1,timeout").arg(thread()->objectName());
    emit inform();
}

void MyObject::onInform()
{
    qDebug() << QString("%1,inform").arg(sender()->thread()->objectName());
}
