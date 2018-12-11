#include <QString>
#include <QtTest>

class stringManagementTest : public QObject
{
    Q_OBJECT

public:
    stringManagementTest();

private Q_SLOTS:
    void testCase1();
};

stringManagementTest::stringManagementTest()
{
}

void stringManagementTest::testCase1()
{
    QString str = "5.58.198.104.1.1";
    QStringList list = str.split(".");
    unsigned char values[6];
    int counter = 0;
    foreach (QString var, list) {
        values[counter] = var.toUInt();
        counter++;
    }

    QVERIFY2(true, "Failure");
}

QTEST_APPLESS_MAIN(stringManagementTest)

#include "tst_stringmanagementtest.moc"
