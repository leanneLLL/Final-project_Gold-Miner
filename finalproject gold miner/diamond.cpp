#include"diamond.h"
#include "gamewindow.h"

extern GameWindow* gamewindow;

Diamond::Diamond(QGraphicsItem* parent):QObject(), QGraphicsPixmapItem(parent)
{
    //diamond image
    setPixmap(QPixmap(":/picture/diamond.png"));
    setScale(0.1);

    //randomly generate the position
    int random_number = QRandomGenerator::global()->bounded(30,700);
    int random_number2 = QRandomGenerator::global()->bounded(140,500);
    setPos(random_number,random_number2);

    diamond_timer = new QTimer();//timer: set a time, when time go to zero, signal execute
    connect(diamond_timer,SIGNAL(timeout()),this,SLOT(diamond_check_collide()));
    diamond_timer->start(50);//every 50 millisec, anchor move

}

void Diamond::diamond_check_collide()
{
    QList<QGraphicsItem*> colliding_items = collidingItems();
    //if a item from Anchor class collide with the diamond, move up the diamond after 50 ms
    for(int i = 0; i<colliding_items.size();++i)
    {
        if(typeid (*colliding_items[i]) == typeid (Anchor))
        {
          //turn on timer_two to move the diamond up
            QTimer* timer = new QTimer();
            connect(timer,SIGNAL(timeout()),this,SLOT(diamond_moveup()));
            timer->start(50);

            return;
        }
    }
}

void Diamond::diamond_moveup()
{
    //move the diamond up
    setPos(x(),y()-10);

    //if the diamond is out of the cave, remove it; at the same time, increase score by 50
    if(pos().y() < 30)//if it passes the miner, remove from the scene and deallocate memory
    {
        gamewindow->increase_diamond();//meanwhile increase the score
        scene()->removeItem(this);
        delete this;
    }
};

Diamond::~Diamond(){
    delete diamond_timer;
};
