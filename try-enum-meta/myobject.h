#ifndef MYOBJECT_H
#define MYOBJECT_H

#include <QObject>

class MyObject : public QObject
{
    Q_OBJECT
public:
    enum MyEnum1
    {
        MyEnum1_item_1,
        MyEnum1_item_2
    };
    Q_ENUM(MyEnum1)

    enum MyEnum2
    {
        MyEnum2_item_1,
        MyEnum2_item_2
    };
    Q_ENUM(MyEnum2)

    enum MyEnum3
    {
        MyEnum3_item_1=0xff,
        MyEnum3_item_2
    };
    Q_ENUM(MyEnum3)

    explicit MyObject(QObject *parent = nullptr);

signals:

public slots:
};

#endif // MYOBJECT_H
