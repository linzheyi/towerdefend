#ifndef MYOBJECT_H
#define MYOBJECT_H

#include <QObject>
#include <QPixmap>
#include <QPoint>
#include <QPropertyAnimation>
#include <QPainter>

class myobject : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QPoint current_pos READ getCurrent_pos WRITE setCurrent_pos)
public:
    myobject(QPoint start_pos,QPoint target_pos,QString fileName);
    void paint(QPainter *painter);
    void move();
    QPoint getCurrent_pos();
    void setCurrent_pos(QPoint pos);

private:
    QPoint start_pos;
    QPoint target_pos;
    QPoint current_pos;
    QPixmap pixmap;


signals:

};

#endif // MYOBJECT_H
