#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <QComboBox>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
protected slots:
    void onSelectionChanged(int i);
private:
    Ui::MainWindow *ui;

    QStandardItemModel* model;
};

#endif // MAINWINDOW_H
