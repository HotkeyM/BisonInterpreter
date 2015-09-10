//© Дмитрий Утямишев, 2011

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "calc++-driver.hh"
#include "graphon.h"
namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    calcxx_driver d;
    Graphon *g;

private slots:
    void on_pushButton_clicked();
};

#endif // MAINWINDOW_H
