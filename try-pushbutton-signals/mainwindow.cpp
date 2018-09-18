#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //!Only checkable buttons can be checked
//    connect(ui->pushButtonCheckable,&QPushButton::clicked,this,&MainWindow::onButtonToggle);
    connect(ui->pushButtonCheckable,&QPushButton::pressed,this,&MainWindow::onButtonPressed);
    connect(ui->pushButtonCheckable,&QPushButton::released,this,&MainWindow::onButtonReleased);
    //!
    connect(ui->pushButtonRaw,&QPushButton::clicked,this,&MainWindow::onButtonToggle);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onButtonToggle(bool value)
{
    //! For non checkable button , signal would send once when click
    counter+=1;
    ui->statusBar->showMessage(QString("%1,%2,%3").arg(sender()->objectName()).arg(value).arg(counter));
}


void MainWindow::onButtonPressed()
{
    //! For non checkable button , signal would send once when click
    counter+=1;
    ui->statusBar->showMessage(QString("Pressed,%1,%2").arg(sender()->objectName()).arg(counter));
}

void MainWindow::onButtonReleased()
{
    //! For non checkable button , signal would send once when click
    counter+=1;
    ui->statusBar->showMessage(QString("Released,%1,%2").arg(sender()->objectName()).arg(counter));
}
