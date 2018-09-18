#include <QString>
#include <QtTest>

#include <derived.h>

class testClass : public QObject
{
    Q_OBJECT

public:
    testClass();

private Q_SLOTS:
    void testCase1();
};

testClass::testClass()
{
}

void testClass::testCase1()
{
    Base* handle;
    Base base;
    Derived derived;

    //! Upcasting
    handle = &(derived);
    handle->method();

    //! Down casting forbidden , raise exception
    handle = &(base);
    handle->method();

    Derived* derivedHandle =  qobject_cast<Derived*>(handle);
    qDebug() << derivedHandle;//! Cannot be casting
    derivedHandle =  dynamic_cast<Derived*>(handle);
    qDebug() << derivedHandle;
    derivedHandle =  static_cast<Derived*>(handle);
    qDebug() << derivedHandle;



    QVERIFY2(true, "Failure");
}

QTEST_APPLESS_MAIN(testClass)

#include "tst_testclass.moc"
