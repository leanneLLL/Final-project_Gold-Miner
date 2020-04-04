#ifndef BOMB_H
#define BOMB_H
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include "items.h"

class Bomb: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    //constructor
    Bomb(QGraphicsItem* parent=0);
    //destructor
    ~Bomb();

public slots:
    /*
     check whether anchor has grabbed a bomb
    */
    void bomb_check_collide();

    /*
     move up bombs when collide with anchor
     */
    void bomb_moveup();

private:
    QTimer* bomb_timer;
};

#endif // BOMB_H
