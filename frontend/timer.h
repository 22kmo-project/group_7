#ifndef TIMER_H
#define TIMER_H
#include <QTimer>
#include <QWidget>


class timer
{
public:
    timer();

private slots:
    void startTimer();
    void handleTimeout();

private:
    QTimer * pQTimer;
    short s;
};

#endif // TIMER_H
