#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    ui->statusBar->insertPermanentWidget(0,new widget1(ui->statusBar));
//    new widget1(ui->statusBar);
//    new widget2(ui->statusBar);
//    new widget1(ui->statusBar);

    ui->statusBar->addPermanentWidget(new widget1());
    ui->statusBar->addPermanentWidget(new widget2());
    //ui->statusBar->insertWidget(-1,new widget1());
    //ui->statusBar->insertWidget(-1,new widget2());

//    new widget1(this);

    ui->statusBar->showMessage("message1",50000);
}

MainWindow::~MainWindow()
{
    delete ui;
}
