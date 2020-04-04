#ifndef SCORE_H
#define SCORE_H
#include "items.h"
#include "diamond.h"

#include<QGraphicsTextItem>

class Score: public QGraphicsTextItem{
public:
    //constructor
    Score(QGraphicsItem* parent=0);

    /*
     increase score if a gold is grabbed
    */
    void increase();

    /*
     increase score if a diamond is grabbed
    */
    void increase_diamond_score();

    /*
     getter function that returns the value of score, the private variable
     @return an integer which represent the score
    */
    int getScore();


    /*
     set the score to zero
    */
    void set_zero();

private:
    int score;
};


#endif // SCORE_H
