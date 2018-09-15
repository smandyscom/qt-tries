#include "mywidget.h"
#include "ui_mywidget.h"

mywidget::mywidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mywidget)
{
    ui->setupUi(this);

    ui->label->setText(parent->objectName());
}

mywidget::~mywidget()
{
    delete ui;
}

bool mywidget::event(QEvent* event)
{
    switch(event->type())
    {
        case QEvent::DynamicPropertyChange:
        break;
    default:
        break;
    }

    //! Should polish specific widget
    //style()->unpolish(ui->pushButton);
    style()->polish(ui->pushButton);

    return QWidget::event(event);
}
