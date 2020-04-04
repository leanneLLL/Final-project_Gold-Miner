#ifndef MINER_H
#define MINER_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QKeyEvent>
#include <QGraphicsScene>

class Miner: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    //constructor
    Miner(QGraphicsItem* parent = 0);


    /*
     keyPressEvent function that allows users to move the miner and release anchors
     */
    void keyPressEvent(QKeyEvent* event);

};
#endif // MINER_H

