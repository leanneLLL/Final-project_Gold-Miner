#ifndef DIAMOND_H
#define DIAMOND_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include<QRandomGenerator>
#include<QTimer>
#include"anchor.h"

class Diamond: public QObject, public QGraphicsPixmapItem{

    Q_OBJECT

public:
    //constructor
    Diamond(QGraphicsItem* parent=0);
    //destructor
    ~Diamond();

public slots:
    /*
     check whether anchor has grabbed a diamond
     */
    void diamond_check_collide();

    /*
     move up diamonds when collide with anchor
     */
    void diamond_moveup();

private:
    QTimer* diamond_timer;
};

#endif // DIAMOND_H
