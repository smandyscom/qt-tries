#ifndef DERIVED_H
#define DERIVED_H

#include <QObject>
#include <base.h>

class Derived : public Base
{
    Q_OBJECT
public:
    explicit Derived(QObject *parent = nullptr);

    void method() Q_DECL_OVERRIDE;

signals:

public slots:
};

#endif // DERIVED_H
