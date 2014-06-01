#include "widget.h"

#include <QPainter>
#include <QTimer>

#include <iostream>
using namespace std;

Widget::Widget(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
    QTimer * t = new QTimer(this);

    connect(t, SIGNAL(timeout()),
            this, SLOT(before()));
    connect(t, SIGNAL(timeout()),
            &reciver, SLOT(heavySlot()));
    connect(t, SIGNAL(timeout()),
            this, SLOT(after()));

    t->start(1000);
}

Widget::~Widget()
{
}

void Widget::before()
{
    cout << ":::::: before" << endl;
}

void Widget::after()
{
    cout << ":::::: after" << endl;
}

void Widget::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.drawPixmap(0, 0, reciver.getImage());
}
