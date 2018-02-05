#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include "QDebug"
#include "QTime"

#define cout qDebug() << "[" << __FILE__ << "->" << __LINE__ << "]:"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    cout << "hello world!";
    timer = new QTimer(this);
    timer->setInterval(1000);

    timer->start();
    ui->label->setText(QString(QTime::currentTime().toString("hh:mm:ss")));

    connect(ui->btn_hello,&QPushButton::clicked,this,&MainWindow::onHello);
    connect(timer,&QTimer::timeout,this,&MainWindow::onTimerout);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onHello()
{
    QMessageBox::about(this,"qt for learn git","hello world");
}

void MainWindow::onTimerout()
{
    ui->label->setText(QString(QTime::currentTime().toString("hh:mm:ss")));
}
