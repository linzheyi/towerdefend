#include "myobject.h"

myobject::myobject(QPoint start_pos,QPoint target_pos,QString fileName):QObject(0),pixmap(fileName)
{
    this->current_pos=start_pos;
    this->start_pos=start_pos;
    this->target_pos=target_pos;
}
void myobject::paint(QPainter *painter)
{
    painter->drawPixmap(current_pos,pixmap);
}
void myobject::move()
{
    QPropertyAnimation *animation=new QPropertyAnimation(this,"current_pos");
    animation->setDuration(2000);
    animation->setStartValue(start_pos);
    animation->setEndValue(target_pos);
    animation->start();

}
QPoint myobject::getCurrent_pos(){
    return this->current_pos;
}
void myobject::setCurrent_pos(QPoint pos){
    this->current_pos=pos;
}
