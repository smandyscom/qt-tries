#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    CommonHelper::setStyle("style.qss",this);

    timer = new QTimer(this);
    connect(timer,&QTimer::timeout,this,&MainWindow::onTimeout);
    timer->start(1000);

    model = new QStandardItemModel(4,2);

    for (int row = 0; row < 4; ++row) {
        for (int column = 0; column < 2; ++column) {
            QModelIndex index = model->index(row, column, QModelIndex());
            model->setData(index, QVariant((row + 1) * (column + 1)));
        }
//! [1] //! [2]
    }


    ui->tableView->setModel(model);
    ui->tableView->setItemDelegate(new MyDelegate(ui->tableView));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    CommonHelper::setStyle("style.qss",this);
    this->style()->unpolish(this);
    this->style()->polish(this);
}

void MainWindow::onTimeout()
{
    QModelIndex index = model->index(qrand() % model->rowCount(),
                                     qrand() % model->columnCount());

   bool result = model->setData(index,
                   !index.data(Qt::UserRole).toBool(),
                   Qt::UserRole); //use UserRole to transmit On/Off state
}
