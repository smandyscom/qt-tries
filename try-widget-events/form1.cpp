#include "form1.h"
#include "ui_form1.h"
#include <QDebug>


Form1::Form1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form1)
{
    ui->setupUi(this);
}

Form1::~Form1()
{
    delete ui;
}

void Form1::hideEvent(QHideEvent *event)
{
    qDebug() << "hideEvent";

//    return QWidget::hideEvent(event);
}
