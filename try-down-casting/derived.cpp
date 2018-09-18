#include "derived.h"

Derived::Derived(QObject *parent) : Base(parent)
{

}

void Derived::method()
{
    qDebug() << "Derived";
}
