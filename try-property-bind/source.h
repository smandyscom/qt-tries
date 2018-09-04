#ifndef SOURCE_H
#define SOURCE_H

#include <QObject>
#include <QTimer>
#include <QVariant>

class Source : public QObject
{
    Q_OBJECT

public:
    Q_PROPERTY(int Value READ getValue WRITE setValue NOTIFY valueChanged)
    Q_PROPERTY(int Value2 MEMBER __value NOTIFY value2Changed)
    explicit Source(QObject *parent = nullptr);

signals:
    void valueChanged(int);
    void value2Changed(int);
public slots:
protected slots:
    void onTimerTimeout();
protected:
    int getValue() const{return __value;}
    void setValue(int value)
    {
        __value = value;
        emit valueChanged(__value);
    }

    int __value;

    QTimer* __timer;
};

#endif // SOURCE_H
