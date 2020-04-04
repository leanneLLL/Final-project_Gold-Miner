#ifndef MAP_H
#define MAP_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>


class Items:public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    //constructor
    Items(QGraphicsItem* parent=0);
    //destructor
    ~Items();

public slots:
    /*
     check whether anchor has grabbed a gold
    */
    void check_collide();

    /*
     move up bombs when collide with anchor
     */
    void moveup();

private:
    QTimer* timer;
};

#endif // MAP_H
