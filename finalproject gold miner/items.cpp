#include "items.h"
#include <stdlib.h> //rand()->a really large int

#include "anchor.h"
#include "bomb.h"
#include"gamewindow.h"

#include <QTimer>
#include <QList>
#include <QDebug>
#include<QRandomGenerator>

extern GameWindow* gamewindow;

Items::Items(QGraphicsItem* parent):QObject(),QGraphicsPixmapItem(parent)
{
    //items image
    setPixmap(QPixmap(":/picture/small gold.png"));

    //randomly generate the position
    int random_number = QRandomGenerator::global()->bounded(30,700);
    int random_number2 = QRandomGenerator::global()->bounded(140,500);
    setPos(random_number,random_number2);
    timer = new QTimer();//timer: set a time, when time go to zero, signal execute
    connect(timer,SIGNAL(timeout()),this,SLOT(check_collide()));
    timer->start(50);//every 50 millisec, anchor move

}


void Items::check_collide()
{
    QList<QGraphicsItem*> colliding_items = collidingItems();


    //if a item from Anchor class collide with the gold, move up the bomb after 50 ms
    for(int i = 0; i<colliding_items.size();++i)
    {
        if(typeid (*colliding_items[i]) == typeid (Anchor))
        {

        //turn on timer_two to move the gold up
            QTimer* timer = new QTimer();
            connect(timer,SIGNAL(timeout()),this,SLOT(moveup()));
            timer->start(50);
            return;
        }
    }
}

void Items::moveup()
{
    //move the anchor up
    setPos(x(),y()-10);

    //check if it passed the miner; if so, remove the gold; at the same time, increase score by 10
    //remove item from the scene and deallocate its memory
    if(pos().y() < 50)
    {
        gamewindow->increase_Score();
        scene()->removeItem(this);
        delete this;
    }
}

Items::~Items(){
    delete timer;
};



