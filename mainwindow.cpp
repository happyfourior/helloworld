#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include "QDebug"
#include "QPixmap"

#define cout qDebug() << "[" << __FILE__ << "->" << __LINE__ << "]:"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap meinv("C:/Users/Administrator/Desktop/meinv/8.jpg");
    meinv.scaled(ui->label->size());
    ui->label->setPixmap(meinv);
    connect(ui->btn_hello,&QPushButton::clicked,this,&MainWindow::onHello);
    cout << "hello world!";
}

MainWindow::~MainWindow()
{
    delete ui;
}

MainWindow::onHello()
{
    QMessageBox::about(this,"qt for learn git","hello world");
}
