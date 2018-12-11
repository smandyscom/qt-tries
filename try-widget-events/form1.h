#ifndef FORM1_H
#define FORM1_H

#include <QWidget>

namespace Ui {
class Form1;
}

class Form1 : public QWidget
{
    Q_OBJECT

public:
    explicit Form1(QWidget *parent = 0);
    ~Form1();

    void hideEvent(QHideEvent* event) Q_DECL_OVERRIDE;

private:
    Ui::Form1 *ui;
};

#endif // FORM1_H
