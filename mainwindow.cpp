#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QPixmap>
#include <QPaintEvent>
#include <QPushButton>
#include <QDebug>
#include <QTimer>
#include "mainbutton.h"
#include "secondwindow.h"
//主界面：开始游戏（待完成：规则说明、结束游戏）

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    this->setFixedSize(1000,800);
    ui->setupUi(this);

    //在主界面上添加开始游戏按钮bt
    mainbutton *bt=new mainbutton(":/new/prefix1/picture/startbutton1.jpg");
    bt->setParent(this);
    bt->move(600,500);
    SecondWindow *scene=new SecondWindow;

    //界面切换：主->选关
    connect(bt,&QPushButton::clicked,this,[=](){
        bt->jumpdown();
        bt->jumpup();
        QTimer::singleShot(500,this,[=](){
            this->close();
            scene->show();
        });
    });

    //界面切换：选关->主
    connect(scene,&SecondWindow::clickback,this,[=](){
        scene->close();
        this->show();
    });

    //在主界面上添加退出按钮exit
    mainbutton *exit=new mainbutton(":/new/prefix1/picture/end.jpg");
    exit->setParent(this);
    exit->move(600,650);

    //点击exit退出游戏
    connect(exit,&QPushButton::clicked,this,[=](){
        exit->jumpdown();
        exit->jumpup();
        QTimer::singleShot(500,this,[=](){
            this->close();
        });
    });

}

MainWindow::~MainWindow()
{
    delete ui;
}

//绘制主界面
void MainWindow::paintEvent(QPaintEvent*)
{
    QPainter painter1(this);
    QPixmap pixmap(":/new/prefix1/picture/mainwindow.jpg");
    painter1.drawPixmap(0,0,this->width(),this->height(),pixmap);

}
