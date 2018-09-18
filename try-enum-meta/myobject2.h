#ifndef MYOBJECT2_H
#define MYOBJECT2_H

#include <QObject>

class MyObject2 : public QObject
{
    Q_OBJECT
public:
    enum MyEnum1
    {
        MyEnum1_item_1,
        MyEnum1_item_2
    };
    Q_ENUM(MyEnum1)

    explicit MyObject2(QObject *parent = nullptr);

signals:

public slots:
};

#endif // MYOBJECT2_H
