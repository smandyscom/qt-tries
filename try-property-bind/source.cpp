#include "source.h"
#include <QTime>
#include <QDebug>

Source::Source(QObject *parent) : QObject(parent)
{
    __timer = new QTimer(this);
    connect(__timer,SIGNAL(timeout()),this,SLOT(onTimerTimeout()));
    //__timer->setInterval(100);
    __timer->setProperty("singleShot",QVariant::fromValue(false));
    qDebug() << __timer->interval();
    __timer->start();

    qsrand(QTime::currentTime().msec());
}

void Source::onTimerTimeout()
{
    this->setProperty("Value",QVariant::fromValue(qrand()));
    this->setProperty("Value2",QVariant::fromValue(qrand()));

    parent()->setProperty("Value",QVariant::fromValue(qrand()));

    //qDebug() << "timeout";
}
