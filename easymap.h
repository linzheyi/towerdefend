#ifndef EASYMAP_H
#define EASYMAP_H

#include <QMainWindow>
#include <QPainter>
#include <QPixmap>
#include <QPaintEvent>
#include <QPushButton>
#include <QList>
#include "tower.h"
#include "myobject.h"



class easymap : public QMainWindow
{
    Q_OBJECT
public:
    explicit easymap(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent*);
    //在地图上绘制塔
    void set_tower();
    void add_object();
    void update_scene();
private:
    //管理塔
    QList<tower*>tower_list;

    //管理敌人运动
    QList<myobject*>object_list;




signals:

};

#endif // EASYMAP_H
