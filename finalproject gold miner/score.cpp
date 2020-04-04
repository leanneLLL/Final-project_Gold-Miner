#include"score.h"

#include <QFont>

Score::Score(QGraphicsItem *parent):QGraphicsTextItem(parent){
    //initialize the score to zero
    score = 0;

    //draw the text
    setPlainText(QString("Score:") + QString::number(score));//"Score:" is a const char
    setDefaultTextColor(Qt::black);
    setFont(QFont("Helvetica",25));
    //score location adjusted
    setX(150);
}


void Score::increase()
{
   score=score+10;
    //update text
    setPlainText(QString("Score:") + QString::number(score));
}

int Score::getScore()
{
    return score;
}

void Score::increase_diamond_score()
{
    score=score+50;
     //update text
    setPlainText(QString("Score:") + QString::number(score));
}

void Score::set_zero()
{
    score = 0;
    //update text
    setPlainText(QString("Score:") + QString::number(score));
}
