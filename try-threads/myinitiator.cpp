#include "myinitiator.h"

MyInitiator::MyInitiator(QObject *parent) : QObject(parent)
{

}

void MyInitiator::Initialize()
{
    workerObj = new MyObject();
}

void MyInitiator::Interconnect()
{
    mainObj = new MyObject();

    //! Signal/Slot interconnect
    QObject::connect(workerObj,&MyObject::inform,mainObj,&MyObject::onInform);
    QObject::connect(mainObj,&MyObject::inform,workerObj,&MyObject::onInform);

//    mainObj->receiver = workerObj;
//    workerObj->receiver = mainObj;
}
