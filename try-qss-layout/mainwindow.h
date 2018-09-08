#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <commonhelper.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    bool event(QEvent* event) Q_DECL_OVERRIDE;

private slots:
    void on_pushButtonLoadQss_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
