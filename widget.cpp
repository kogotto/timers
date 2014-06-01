#include "widget.h"

#include <QPainter>
#include <QTimer>
#include <QMessageBox>

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

    connect(button, SIGNAL(clicked()),
            this, SLOT(buttonSlot()));

    t->start(100);

    QTimer * t2 = new QTimer(this);
    connect(t2, SIGNAL(timeout()),
            this, SLOT(update()));
    t2->start(10);
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

void Widget::buttonSlot()
{
    QMessageBox::about(this, "button", "message");
}

void Widget::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.drawPixmap(0, 0, reciver.getImage());
}
