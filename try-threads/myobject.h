#ifndef MYOBJECT_H
#define MYOBJECT_H

#include <QObject>
#include <QTimer>
#include <QThread>

class MyObject : public QObject
{
    Q_OBJECT
public:
    explicit MyObject(QObject *parent = nullptr);

signals:
    void inform();
protected slots:
    void onTimeout();
public slots:
    void onInform();
protected:
    QTimer* timer;
};

#endif // MYOBJECT_H
