#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include "QDebug"
#include "QTime"
#include "QPixmap"

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
    ui->label_time->setText(QString(QTime::currentTime().toString("hh:mm:ss")));

    connect(ui->btn_hello,&QPushButton::clicked,this,&MainWindow::onHello);
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
    ui->label_time->setText(QString(QTime::currentTime().toString("hh:mm:ss")));
    QString filepath = path+ QString::number(qrand()%9)+".jpg";
    QPixmap meinv(filepath);
    meinv.scaled(ui->label_meinv->size());
    ui->label_meinv->setPixmap(meinv);
}
