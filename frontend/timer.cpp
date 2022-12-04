#include "timer.h"
#include <QTimer>
#include <QDebug>
//#include <winsock.h>
#include <windows.h>
#include <QObject>
#include <QTimer>
#include <QWidget>
//#include <winsock.h>


timer::timer()
{
    /*s=0;
    pQTimer = new QTimer(this);
    connect(pQTimer,SIGNAL(timeout()),this, SLOT(handleTimeout()));
    pQTimer->start(1000);
    //startTimer();*/

}

void timer::startTimer()
{
   /*connect(pQTimer,SIGNAL(timeout()),this,SLOT(handleTimeout()));
    pQTimer->start(1000);*/

}

void timer::handleTimeout()
{
    s++;
    qDebug()<<s;
    if (s==30)
    {
        pQTimer->stop();
        delete pQTimer;
        pQTimer=nullptr;
        //return 1;
    }
    //return 0;
}
