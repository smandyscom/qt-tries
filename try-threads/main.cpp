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
    a.thread()->setObjectName("main");

    MyInitiator* initiator = new MyInitiator();
    //!Set Thread affinity
    initiator->moveToThread(thread);
    //!Call in worker thread after it started
    QObject::connect(thread,&QThread::started,initiator,&MyInitiator::Initialize);

    //!Call in main thread
    QTimer::singleShot(100,[=](){
        initiator->Interconnect();
    });

    //!worker thread event loop start
    thread->start();
    //!main thread event loop start
    return a.exec();
}
