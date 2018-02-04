#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->btn_hello,&QPushButton::clicked,this,&MainWindow::onHello);
}

MainWindow::~MainWindow()
{
    delete ui;
}

MainWindow::onHello()
{
    QMessageBox::about(this,"qt for learn git","hello world\n"
                                               "vision 1.0");
}
