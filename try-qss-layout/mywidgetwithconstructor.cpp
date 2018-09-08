#include "mywidgetwithconstructor.h"
#include "ui_mywidgetwithconstructor.h"

mywidgetwithconstructor::mywidgetwithconstructor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mywidgetwithconstructor)
{
    ui->setupUi(this);
}

mywidgetwithconstructor::~mywidgetwithconstructor()
{
    delete ui;
}
