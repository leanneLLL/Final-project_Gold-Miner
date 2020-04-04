#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H


#include <mainwindow.h>
#include <QGraphicsView>
#include <QTimer>
#include <QLCDNumber>
#include <QMediaPlayer>
#include <QGraphicsProxyWidget>
#include "anchor.h"
#include "miner.h"
#include "items.h"
#include "bomb.h"
#include "diamond.h"
#include "score.h"
#include "endwindow.h"
#include "winwindow.h"
#include "mainwindow.h"


class GameWindow :public QGraphicsView{
    Q_OBJECT

public:
    GameWindow();
    ~GameWindow();

    /*
        set the starting time of the timers and connect with the item generation slots
    */
    void generateItems();


    /*
        increase the score if grab a gold
    */
    void increase_Score();


    /*
        increase the score if grab a diamond
    */
    void increase_diamond();


    /*
        get the current score
    */
    int get_score();//return score to the bomb_endwindow


    /*
        re-set miner focus to prevent the user from accidently
        clicking the screen and remove the focus from the miner
    */
    void mousePressEvent(QMouseEvent *event);


    /*
        set the score to zero
    */
    void set_zero_score();

    /*
        set the focus to miner
    */
    void set_miner_focus();


    /*
        increase the remaining time to 60
    */
    void set_time();


    /*
        mute the background music in gamewindow
    */
    void mute();


private slots:
    void receiveshow();//receive signal from mainwindow, show game window
    void on_returnmainButton_clicked();//return main window
    void update_time(); //countdown
    void mutebutton_clicked();//mute button

    //generators
    void generate_golds();
    void generate_diamonds();
    void generate_bombs();

    //restart the game
    void restart();

    //reset scene by removing the items from the scene
    void reset();

signals:
    void showmainwindow();//connect to mainwindow, return main window
    void quit();//quit app
    void countdown_timeout(); //times up

private:
    QGraphicsScene* scene;

    Miner* miner;
    Anchor* anchor;
    Score* score;

    Items* items;
    Diamond* diamonds;
    Bomb* bombs;


    QMediaPlayer* music;

    QTimer* countdown;

    QTimer* bomb_timer;
    QTimer* gold_timer;
    QTimer* diamond_timer;

    QLCDNumber* timeLCD;

    QPushButton *button;
    QPushButton* buttonMute;
    int time_left;
    endwindow* end;
    winwindow* win;

    //Ui::GameWindow *ui;
};

#endif // GAMEWINDOW_H
