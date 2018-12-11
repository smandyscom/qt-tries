#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    CommonHelper::setStyle("style.qss",this);

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(":memory:");
    if(!db.open())
        qDebug() << "faile";
    QSqlQuery query;
       query.exec("create table person (id int primary key, "
                  "firstname varchar(20), lastname varchar(20))");
       query.exec("insert into person values(101, 'Danny', 'Young')");
       query.exec("insert into person values(102, 'Christine', 'Holand')");
       query.exec("insert into person values(103, 'Lars', 'Gordon')");
       query.exec("insert into person values(104, 'Roberto', 'Robitaille')");
       query.exec("insert into person values(105, 'Maria', 'Papadopoulos')");

    QSqlTableModel* memory = new enhancedTableModel();
    memory->setTable("person");
    memory->select();

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

    model = memory;

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

    ui->statusBar->showMessage(QString(result));
}
