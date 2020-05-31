#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QMainWindow>


class SecondWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit SecondWindow(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent*);

private:

signals:
    //信号：点击后返回上一界面
    void clickback();
};

#endif // SECONDWINDOW_H
