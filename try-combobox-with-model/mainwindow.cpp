#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    model = new QStandardItemModel(4,2);

    for (int row = 0; row < 4; ++row) {
        for (int column = 0; column < 2; ++column) {
            QModelIndex index = model->index(row, column, QModelIndex());
            model->setData(index, QVariant((row + 1) * (column + 1)));
        }
    }

    ui->comboBox->setModel(model);
    connect(ui->comboBox,SIGNAL(currentIndexChanged(int)),this,SLOT(onSelectionChanged(int)));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onSelectionChanged(int i)
{
    //!Invalid
    QVariant var = ui->comboBox->currentData();
    //! When using model , should access from modelIndex
    var = ui->comboBox->model()->index(ui->comboBox->currentIndex(),ui->comboBox->modelColumn()).data();
    ui->statusBar->showMessage(QString("%1").arg(var.toString()));
}
