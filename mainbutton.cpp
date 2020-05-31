#include "mainbutton.h"
#include <QPixmap>
#include <QPropertyAnimation>

mainbutton::mainbutton(QString bt):QPushButton(0)
{
    QPixmap pixmap(bt);
    this->setFixedSize(pixmap.width(),pixmap.height());
    this->setStyleSheet("QPushButton{border:Opx;}");
    this->setIcon(pixmap);
    this->setIconSize(QSize(pixmap.width(),pixmap.height()));

}

//实现按钮下跳
void mainbutton::jumpdown(){
    QPropertyAnimation *animation=new QPropertyAnimation(this,"geometry");
    //设置动画时间
    animation->setDuration(200);
    //设置动画开始时位置
    animation->setStartValue(QRect(this->x(),this->y(),this->width(),this->height()));
    //设置动画结束时位置
    animation->setEndValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
    //跳动曲线
    animation->setEasingCurve(QEasingCurve::OutBounce);
    //让动画开始
    animation->start();
}

//实现按钮上跳
void mainbutton::jumpup(){
    QPropertyAnimation *animation=new QPropertyAnimation(this,"geometry");
    animation->setDuration(200);
    animation->setStartValue(QRect(this->x(),this->y(),this->width(),this->height()));
    animation->setEndValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
    animation->setEasingCurve(QEasingCurve::OutBounce);
    animation->start();
}
