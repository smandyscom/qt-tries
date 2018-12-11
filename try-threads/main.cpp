#include <QCoreApplication>
#include <QThread>
#include <myinitiator.h>
#include <QObject>
#include <QTimer>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QThread* thread = new QThread();
    thread->setObjectName("worker");

    MyInitiator* initiator = new MyInitiator();

    initiator->moveToThread(thread);
    QObject::connect(thread,&QThread::started,initiator,&MyInitiator::Initialize);

    QTimer::singleShot(100,[=](){
        initiator->Interconnect();
    });

    a.thread()->setObjectName("main");

    thread->start();
    return a.exec();
}
