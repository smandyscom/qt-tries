#include "myobject.h"
#include <QDebug>

#include <QEvent>

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

    //!"Cannot send events to objects owned by a different thread
    //!receiver->setProperty("thread",thread()->objectName());
}

void MyObject::onInform()
{
    qDebug() << QString("sender thread %1,inform, on thread %2")
                .arg(sender()->thread()->objectName())
                .arg(thread()->objectName());
}

//bool MyObject::event(QEvent *event)
//{
//    switch (event->type()) {
//    case QEvent::DynamicPropertyChange:
//        qDebug() << QString("%1,property change").arg(property("thread").toString());
//        break;
//    default:
//        break;
//    }

//    return QObject::event(event);
//}
