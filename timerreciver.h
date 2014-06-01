#ifndef TIMERRECIVER_H
#define TIMERRECIVER_H

#include <QObject>
#include <QPixmap>

class TTimerReciver : public QObject
{
    Q_OBJECT
public:
    explicit TTimerReciver(QObject *parent = 0);

    const QPixmap & getImage() const {
        return img;
    }

    QPixmap & getImage() {
        return img;
    }

signals:

public slots:
    void heavySlot();
private:
    QPixmap img;
};

#endif // TIMERRECIVER_H
