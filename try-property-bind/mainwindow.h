#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <source.h>
#include <commonhelper.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    Q_PROPERTY(int Value MEMBER __value NOTIFY valueChanged)
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
signals:
    void valueChanged(int);
private:
    Ui::MainWindow *ui;
    Source* __source;

protected:
    int __value;
private slots:
    void on_pushButton_clicked();
};

#endif // MAINWINDOW_H
