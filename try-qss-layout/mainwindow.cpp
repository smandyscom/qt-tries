#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonLoadQss_clicked()
{
    CommonHelper::setStyle("/Users/Apple/Github/qt-tries/try-qss-layout/style.qss",this);
    qDebug() << styleSheet();
}

void MainWindow::on_pushButton_5_clicked()
{
    foreach (QObject* var, children()) {
        var->setProperty("prop",QVariant::fromValue(false));
    }
}

void MainWindow::on_pushButton_6_clicked()
{
    foreach (QObject* var, children()) {
        var->setProperty("prop",QVariant::fromValue(true));
    }
}

void MainWindow::on_pushButton_7_clicked()
{
    foreach (QObject* var, QList<QWidget*>({ui->widget,ui->widget_2})) {
        var->setProperty("enabled",!var->property("enabled").toBool());
    }
}

bool MainWindow::event(QEvent* event)
{
    style()->unpolish(this);
    style()->polish(this);

    return QMainWindow::event(event);
}
