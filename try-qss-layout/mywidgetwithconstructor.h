#ifndef MYWIDGETWITHCONSTRUCTOR_H
#define MYWIDGETWITHCONSTRUCTOR_H

#include <QWidget>

namespace Ui {
class mywidgetwithconstructor;
}

class mywidgetwithconstructor : public QWidget
{
    Q_OBJECT

public:
    //!
    // constructor with args cannot be applied on "Promoted to " function
//    explicit mywidgetwithconstructor(int arg,QWidget *parent = nullptr);
    explicit mywidgetwithconstructor(QWidget *parent = nullptr);
    ~mywidgetwithconstructor();

private:
    Ui::mywidgetwithconstructor *ui;
};

#endif // MYWIDGETWITHCONSTRUCTOR_H
