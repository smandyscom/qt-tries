#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void onButtonToggle(bool value);
    void onButtonPressed();
    void onButtonReleased();
private:
    Ui::MainWindow *ui;

    int counter;
};

#endif // MAINWINDOW_H
