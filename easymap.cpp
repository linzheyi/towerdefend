#include "easymap.h"
#include "secondwindow.h"
#include "mainbutton.h"
#include "tower.h"
#include <QPainter>
#include <QPixmap>
#include <QPaintEvent>
#include <QPushButton>
#include <QDebug>
#include <QTimer>
#include <QPropertyAnimation>

//easy级地图

easymap::easymap(QWidget *parent) : QMainWindow(parent)
{
    this->setFixedSize(1400,950);

    //在地图上添加用于安装塔的按钮settower_bt
    mainbutton *settower_bt=new mainbutton(":/new/prefix1/picture/settower_new.jpg");
    settower_bt->setParent(this);
    settower_bt->move(500,400);

    //实现点击按钮时地图上出现塔(感觉需要一个settower_button类继承button！！！！！待实现）
    connect(settower_bt,&mainbutton::clicked,this,&easymap::set_tower);
    connect(settower_bt,&mainbutton::clicked,this,&easymap::add_object);
    QTimer *timer=new QTimer(this);
    connect(timer,&QTimer::timeout,this,&easymap::update_scene);
    timer->start(5);

}

//绘制easy地图
void easymap::paintEvent(QPaintEvent*)
{
    QPainter painter2(this);
    QPixmap pixmap(":/new/prefix1/picture/easymap.jpg");
    painter2.drawPixmap(0,0,this->width(),this->height(),pixmap);
    foreach(tower *each_tower,tower_list)
        each_tower->paint(&painter2);
    foreach(myobject *object,object_list)
        object->paint(&painter2);
}

//在地图上绘制塔
void easymap::set_tower(){
    tower *new_tower=new tower(QPoint(500,350),":/new/prefix1/picture/tower1.jpg");
    tower_list.push_back(new_tower);
    update();
}
void easymap::add_object(){
    myobject *object=new myobject(QPoint(0,500),QPoint(600,500),":/new/prefix1/picture/enemy.jpg");
    object_list.push_back(object);
    object->move();
    update();
}
void easymap::update_scene(){
    update();
}
