#include "myinitiator.h"

MyInitiator::MyInitiator(QObject *parent) : QObject(parent)
{

}

//!Called in worker thread
void MyInitiator::Initialize()
{
    workerObj = new MyObject();
}

//!Called in main thread
void MyInitiator::Interconnect()
{
    mainObj = new MyObject();

    //! Signal/Slot interconnect
    QObject::connect(workerObj,&MyObject::inform,mainObj,&MyObject::onInform);
    QObject::connect(mainObj,&MyObject::inform,workerObj,&MyObject::onInform);
}
