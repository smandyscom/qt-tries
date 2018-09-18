#ifndef BASE_H
#define BASE_H

#include <QObject>
#include <QDebug>

class Base : public QObject
{
    Q_OBJECT
public:
    explicit Base(QObject *parent = nullptr);
    ~Base();

    virtual void method();
signals:

public slots:


protected:
    quint16* reserved;
};

#endif // BASE_H
