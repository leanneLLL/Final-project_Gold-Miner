 #ifndef ANCHOR_H
#define ANCHOR_H
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QTimer>

class Anchor: public QObject,public QGraphicsPixmapItem{
        Q_OBJECT
public:
    //constructor
    Anchor(QGraphicsItem* parent=0);
    //destructor
    ~Anchor();

public slots:
    /*
     move the anchor down
     */
    void move();

    /*
     move the anchor up
     */
    void move_up();
    /*
     move the bomb up
     */
    void move_up_bomb();

private:
    QTimer* timer;
    QTimer* timer_two;
};

#endif // ANCHOR_H
