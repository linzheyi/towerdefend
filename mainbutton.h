#ifndef MAINBUTTON_H
#define MAINBUTTON_H

#include <QWidget>
#include <QPushButton>

class mainbutton : public QPushButton
{
    Q_OBJECT
public:
   mainbutton(QString bt);
   void jumpdown();         //按钮上跳
   void jumpup();           //按钮下跳

signals:

};

#endif // MAINBUTTON_H
