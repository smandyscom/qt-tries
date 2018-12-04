#ifndef MYINITIATOR_H
#define MYINITIATOR_H

#include <QObject>
#include <myobject.h>

class MyInitiator : public QObject
{
    Q_OBJECT
public:
    explicit MyInitiator(QObject *parent = nullptr);

signals:

public slots:
    void Initialize();
    void Interconnect();
protected:

    MyObject* mainObj;
    MyObject* workerObj;
};

#endif // MYINITIATOR_H
