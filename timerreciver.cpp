#include "timerreciver.h"
#include <QPainter>
#include <iostream>
using namespace std;


#include <QTime>
struct TTimeMesurer {
    explicit TTimeMesurer(const QString & message):
        message(message) {
        cerr << "  " << message.toStdString() << " begins" << endl;
        timer.start();
    }

    ~TTimeMesurer() {
        cerr << "  " << message.toStdString() << " ends: " << timer.elapsed() << "ms\n";
    }

private:
    QString message;
    QTime timer;
};

TTimerReciver::TTimerReciver(QObject *parent) :
    QObject(parent)
{

}


void TTimerReciver::heavySlot()
{
    static int counter = 0;
    TTimeMesurer time(QString("heavySlot ") + QString::number(counter++));
    const int N = 100000;
    int w = 640;
    int h = 480;
    QPixmap newImg(w, h);
    for (int i = 0; i < N; ++i) {
        QPainter p(&newImg);
        QColor color(rand() % 255, rand() % 255, rand() % 255);
        QPen pen(color);
        p.setPen(pen);
        p.drawLine(rand() % w, rand() % h, rand() % w, rand() % h);
    }

    img = newImg;
}
