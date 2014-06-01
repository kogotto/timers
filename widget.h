#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "ui_widget.h"
#include "timerreciver.h"


class Widget:
        public QWidget,
        private Ui::Widget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

public slots:
    void before();
    void after();

protected:
    virtual void paintEvent(QPaintEvent *);

private:
    TTimerReciver reciver;
};

#endif // WIDGET_H
