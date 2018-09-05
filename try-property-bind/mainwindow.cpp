#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    __source = new Source(this);

    connect(__source,SIGNAL(valueChanged(int)),ui->lcdNumber,SLOT(display(int)));
    connect(__source,SIGNAL(value2Changed(int)),ui->lcdNumber_2,SLOT(display(int)));

    connect(this,SIGNAL(valueChanged(int)),ui->lcdNumber_3,SLOT(display(int)));

    CommonHelper::setStyle("/Users/Apple/Github/qt-tries/try-property-bind/style2.qss",this);
    qDebug() << this->styleSheet();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
//    ui->pushButton->setProperty("flip","true"); //able to set string property

    this->centralWidget()->setProperty("flip",QVariant::fromValue(!this->centralWidget()->property("flip").toBool())); //possible use hierarachy to update

        this->style()->unpolish(this); //valid
        this->style()->polish(this);

//    this->style()->unpolish(qApp); //valid
//    this->style()->polish(qApp);


//    ui->pushButton->style()->unpolish(ui->pushButton); //need to update specific widget
//    ui->pushButton->style()->polish(ui->pushButton);

}
