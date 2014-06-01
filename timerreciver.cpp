#include "timerreciver.h"
#include <QPainter>
#include <iostream>
using namespace std;


#include <QTime>
struct TTimeMesurer {
    explicit TTimeMesurer(const char * message):
        message(message) {
        cerr << "  " << message << " begins" << endl;
        timer.start();
    }

    ~TTimeMesurer() {
        cerr << "  " << message << " ends: " << timer.elapsed() << "ms\n";
    }

private:
    const char * message;
    QTime timer;
};

TTimerReciver::TTimerReciver(QObject *parent) :
    QObject(parent)
{
}

const int N = 10000;

void TTimerReciver::heavySlot()
{
    TTimeMesurer time("heavySlot");
    int w = 640;
    int h = 480;
    QPixmap newImg(w, h);
    for (int i = 0; i < N; ++i) {
        QPainter p(&newImg);
        p.drawLine(rand() % w, rand() % h, rand() % w, rand() % h);
    }

    img = newImg;
}
