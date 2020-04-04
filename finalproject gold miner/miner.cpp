#include "miner.h"
#include "anchor.h"

Miner::Miner(QGraphicsItem *parent):QGraphicsPixmapItem(parent)
{
    //add miner picture
    setPixmap(QPixmap(":/picture/1 copy.png"));
}

void Miner::keyPressEvent(QKeyEvent *event)
{
    {
        //if the left key is pressed, move the miner left by 15 pixels
        if(event->key() == Qt::Key_Left)
        {
            if(x()>0)//pos().x()>0
            {
                setPos(x()-15,y());
            }

        }

        //if the right key is pressed, move the miner right by 15 pixels
        else if(event->key() == Qt::Key_Right)
        {
            if(x()+pixmap().width()<800)
            {
                setPos(x()+15,y());
            }
        }

        //if space is pressed, release the anchor
        else if(event->key() == Qt::Key_Space)
        {
            this->clearFocus();
            //release the anchor
            Anchor* anchor = new Anchor();
            anchor->setPos(x()+45,y()+pixmap().height());
            scene()->addItem(anchor);
        }
    }
}
