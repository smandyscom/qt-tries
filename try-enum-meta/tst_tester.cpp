#include <QString>
#include <QtTest>
#include <QDebug>

#include <myobject.h>
#include <myobject2.h>

class tester : public QObject
{
    Q_OBJECT

public:
    tester();

private Q_SLOTS:
    void testCase1();
};

tester::tester()
{
}

void tester::testCase1()
{
    int id = qRegisterMetaType<MyObject::MyEnum1>();
    id = qRegisterMetaType<MyObject::MyEnum2>();
    id = qRegisterMetaType<MyObject::MyEnum3>();
    id = qRegisterMetaType<MyObject2::MyEnum1>();
    //! Redundant call would not generate new id
    //!  Can be used as type key query function
    id = qRegisterMetaType<MyObject::MyEnum2>();
    id = qRegisterMetaType<MyObject::MyEnum3>();
    id = qRegisterMetaType<MyObject2::MyEnum1>();


    QVariant myEnum1Item1 = QVariant::fromValue(MyObject::MyEnum1_item_1);
    QVariant myEnum1Item2 = QVariant::fromValue(MyObject::MyEnum1_item_2);

    QVariant myEnum3Item1 = QVariant::fromValue(MyObject::MyEnum3_item_1);

    QVariant obj2myEnum1Item1 = QVariant::fromValue(MyObject2::MyEnum1_item_1);


    //! If call QVariant::Type() , would return 1024 for all custom type
    //! Use user type to distinguish
    qDebug() << static_cast<int>(myEnum1Item1.userType());
    qDebug() << static_cast<int>(myEnum1Item2.userType());

    qDebug() << static_cast<int>(myEnum3Item1.userType());

    qDebug() << static_cast<int>(obj2myEnum1Item1.userType());

    //! Casting to string
    //! MetaType induce to QString
    qDebug() << obj2myEnum1Item1.toString();
    //! Castring from string
    //! QString + Type induce to MetaType
    const char* m_cstr= "MyEnum3_item_2";
    auto var2 = QVariant::fromValue(QString(m_cstr)).value<MyObject::MyEnum3>();

    QVERIFY2(true, "Failure");
}

QTEST_APPLESS_MAIN(tester)

#include "tst_tester.moc"
