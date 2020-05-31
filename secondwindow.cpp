#include "secondwindow.h"
#include "mainbutton.h"
#include "easymap.h"
#include <QPainter>
#include <QPixmap>
#include <QPaintEvent>
#include <QPushButton>
#include <QDebug>
#include <QTimer>


//选关界面

SecondWindow::SecondWindow(QWidget *parent) : QMainWindow(parent)
{
    this->setFixedSize(1000,800);

    //在选关界面添加返回按钮back_bt
    mainbutton *back_bt=new mainbutton(":/new/prefix1/picture/backbutton.jpg");
    back_bt->setParent(this);
    back_bt->move(40,40);
    connect(back_bt,&mainbutton::clicked,this,[=](){
        back_bt->jumpdown();
        back_bt->jumpup();
        QTimer::singleShot(500,this,[=](){
           emit clickback();
        });
    });

    //在选关界面添加难度选择按钮（未完成hard）
    //选择easy关卡，点击easy按钮，easy关出现
    mainbutton *level_bt=new mainbutton(":/new/prefix1/picture/easybutton.jpg");
    level_bt->setParent(this);
    level_bt->move(600,500);
    easymap *emap=new easymap;
    connect(level_bt,&QPushButton::clicked,this,[=](){
        level_bt->jumpdown();
        level_bt->jumpup();
        QTimer::singleShot(500,this,[=](){
            this->close();
            emap->show();
        });
    });

}

//绘制选关界面
void SecondWindow::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    QPixmap pixmap(":/new/prefix1/picture/secondwindow.gif");
    painter.drawPixmap(0,0,this->width(),this->height(),pixmap);
}
