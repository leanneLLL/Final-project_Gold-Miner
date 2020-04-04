#include "bomb.h"
#include "anchor.h"

#include "gamewindow.h"
#include "bomb_endwindow.h"

#include <stdlib.h>
#include <QTimer>
#include <QList>
#include <QDebug>
#include<iostream>
#include<QRandomGenerator>

extern GameWindow* gamewindow;
extern bomb_endwindow* b;

Bomb::Bomb(QGraphicsItem* parent):QObject(),QGraphicsPixmapItem(parent)
{
        //bomb image
       setPixmap(QPixmap(":/picture/bomb.png"));
       setScale(0.03);

       //randomly generate the position
       int random_number = QRandomGenerator::global()->bounded(30,700);
       int random_number2 = QRandomGenerator::global()->bounded(140,500);
       setPos(random_number,random_number2);

       bomb_timer = new QTimer();
       connect(bomb_timer,SIGNAL(timeout()),this,SLOT(bomb_check_collide()));
       bomb_timer->start(50);//every 50 millisec, anchor move

}

void Bomb::bomb_check_collide(){
    QList<QGraphicsItem*> colliding_items = collidingItems();

    //if a item from Anchor class collide with the bomb, move up the bomb after 50 ms
    for(int i = 0; i<colliding_items.size();++i)
    {
        if(typeid (*colliding_items[i]) == typeid (Anchor))//if the bomb collide with the anchor
        {

       //turn on timer_two to move the bomb up
            QTimer* timer = new QTimer();
            connect(timer,SIGNAL(timeout()),this,SLOT(bomb_moveup()));
            timer->start(50);

            return;
        }

    }
};

void Bomb::bomb_moveup()
{
    //move the anchor up
    setPos(x(),y()-10);

    //if the bomb is about to out from the screen, remove it and deallocate the memory
    if(pos().y() < 50)
    {
        scene()->removeItem(this);
        delete this;

    }

};


Bomb::~Bomb(){
    delete bomb_timer;
};


