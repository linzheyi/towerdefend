#include "tower.h"
#include <QPoint>
#include <QPixmap>
#include <QPainter>

//构造函数  位置+图片地址
tower::tower(QPoint pos,QString pixFileName):QObject(0),_pixmap(pixFileName)
{
    _pos=pos;
}

//绘制炮塔
void tower::paint(QPainter *painter)
{
    painter->drawPixmap(_pos,_pixmap);
}
