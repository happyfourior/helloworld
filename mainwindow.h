#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QTimer"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public:
    void onHello();
    void onTimerout();
private:
    Ui::MainWindow *ui;
    QTimer * timer;
    QString path = "C:/Users/Administrator/Desktop/meinv/";
};

#endif // MAINWINDOW_H
