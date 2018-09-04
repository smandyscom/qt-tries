#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    __source = new Source(this);

    connect(__source,SIGNAL(valueChanged(int)),ui->lcdNumber,SLOT(display(int)));
    connect(__source,SIGNAL(value2Changed(int)),ui->lcdNumber_2,SLOT(display(int)));

    connect(this,SIGNAL(valueChanged(int)),ui->lcdNumber_3,SLOT(display(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ui->pushButton->setProperty("bgColor","red"); //able to set string property
    ui->pushButton->style()->unpolish(ui->pushButton);
    ui->pushButton->style()->polish(ui->pushButton);
}
