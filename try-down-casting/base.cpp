#include "base.h"

Base::Base(QObject *parent) : QObject(parent)
{
    reserved = new quint16[32];
}

Base::~Base()
{
    delete reserved;
}

void Base::method()
{
    qDebug() << "Base";
}
