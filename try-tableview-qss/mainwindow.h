#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <commonhelper.h>
#include <mydelegate.h>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
protected slots:
    void onTimeout();
private:
    Ui::MainWindow *ui;
    QStandardItemModel* model;

    QTimer* timer;
};

#endif // MAINWINDOW_H
