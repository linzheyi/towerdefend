#ifndef TOWER_H
#define TOWER_H

#include <QObject>
#include <QPoint>
#include <QPixmap>
#include <QPainter>

class tower : public QObject
{
    Q_OBJECT
public:
    //构造函数  位置+图片地址
    tower(QPoint pos,QString pixFileName);
    //绘制炮塔函数
    void paint(QPainter *painter);
private:

    QPoint _pos;//炮塔位置
    QPixmap _pixmap;
signals:


};

#endif // TOWER_H
