#ifndef MYOBJECT_H
#define MYOBJECT_H

#include <QObject>
#include <QTimer>
#include <QThread>

//!
//! \brief The MyObject class
//! Best practice : use signal/slot with connect to perform cross-thread communication
class MyObject : public QObject
{
    Q_OBJECT
public:
    explicit MyObject(QObject *parent = nullptr);

    QObject* receiver;

    bool event(QEvent *event) Q_DECL_OVERRIDE;

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
