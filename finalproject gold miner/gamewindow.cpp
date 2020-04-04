#include "gamewindow.h"


#include <QPainter>
#include <QPixmap>
#include <QTimer>
#include <QImage>
#include<QGraphicsProxyWidget>
#include <QList>

GameWindow::GameWindow()
{

    //general settings of the window
    scene = new QGraphicsScene();
    this->setFixedSize(800, 600);
    scene->setSceneRect(0,0,800,600);//both to be 800x600
    this->setWindowTitle(tr("Gold Miner 1.0"));
    setBackgroundBrush(QBrush(QImage(":/picture/newdinasourBackground.png")));//pass the background image

    //window set central
    QDesktopWidget* desktop = QApplication::desktop();
    move((desktop->width() - this->width())/2, (desktop->height() - this->height())/2);

    //add miner
    miner = new Miner();
    scene->addItem(miner);

    //add the score
    score = new Score();
    scene->addItem(score);

    //add countdown timer
    countdown = new QTimer(this);
    time_left = 60;
    connect(countdown, SIGNAL(timeout()), this, SLOT(update_time()));
    //countdown->start( 1000 );

    //countdown display with lcd
    timeLCD = new QLCDNumber();
    timeLCD->display(60);
    timeLCD->setSegmentStyle(QLCDNumber::Filled);
    timeLCD->setAttribute( Qt::WA_NoBackground );
    timeLCD->setFrameStyle( QFrame::NoFrame );
    QGraphicsProxyWidget *proxy = this->scene->addWidget(timeLCD);
    proxy->setPos(720, 10);

    //set the scene
    this->setScene(scene);

    //make the miner focusable so it can move
    miner->setFlag(QGraphicsItem::ItemIsFocusable);
    miner->setFocus();

    //place the miner object at the top center
    miner->setPos(this->width()/2 - miner->pixmap().width()/2,15);


    generateItems();

    button = new QPushButton;
    QGraphicsProxyWidget *returnButton = this->scene->addWidget(button);
    returnButton->setPos(0,-10);
    button->setFlat(true);
    button->setAutoFillBackground(true);

    QPixmap pixmap(":/picture/returnButton1.png");
    QIcon ButtonIcon(pixmap);
    button->setIcon(ButtonIcon);
    button->setFixedSize(pixmap.width(),pixmap.height());
    button->setIconSize(pixmap.size());
    button->setStyleSheet("background-color: rgba(255, 255, 255, 0);");

    //play background music
    music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/music/back2.mp3"));
    music->play();

    buttonMute = new QPushButton;
    QGraphicsProxyWidget *muteButton = this->scene->addWidget(buttonMute);
    muteButton->setPos(750,560);
    button->setFlat(true);
    button->setAutoFillBackground(true);

    QPixmap pixmap2(":/picture/muteButton copy.png");
    QIcon ButtonIcon2(pixmap2);
    buttonMute->setIcon(ButtonIcon2);
    buttonMute->setFixedSize(pixmap2.width(),pixmap2.height());
    buttonMute->setIconSize(pixmap2.size());
    buttonMute->setStyleSheet("background-color: rgba(255, 255, 255, 0);");

    //cursor
    QPixmap pixmap1(":/picture/ccc.png");
    QCursor cursor= QCursor(pixmap1,-1,-1);
    setCursor(cursor);

    //initialize end window
    end = new endwindow();

    //initializ win window
    win= new winwindow();

    //return to the main window
    QObject::connect(button,SIGNAL(clicked()),this,SLOT(on_returnmainButton_clicked()));

    //mute in gamewindow
    QObject::connect(buttonMute,SIGNAL(clicked()),this,SLOT(mutebutton_clicked()));

    //restart the game from end window
    QObject::connect(end,SIGNAL(restart_game()),this,SLOT(restart()));
    QObject::connect(end,SIGNAL(reset_game()),this,SLOT(reset()));

    //restart the game from win window
    QObject::connect(win,SIGNAL(restart_game()),this,SLOT(restart()));
    QObject::connect(win,SIGNAL(reset_game()),this,SLOT(reset()));

}

int GameWindow::get_score() {
    return score->getScore();
}

void GameWindow::mousePressEvent(QMouseEvent *event)
{
    if(event->button() & Qt::RightButton)
    {
        miner->setFlag(QGraphicsItem::ItemIsFocusable);
        miner->setFocus();
        //this->setFocusPolicy(Qt::NoFocus);

    }
    else
    {
        //this->setFocusPolicy(Qt::NoFocus);
        miner->setFlag(QGraphicsItem::ItemIsFocusable);
        miner->setFocus();
    }
}

void GameWindow::set_zero_score()
{
    score->set_zero();
}

void GameWindow::set_miner_focus()
{
    miner->setFlag(QGraphicsItem::ItemIsFocusable);
    miner->setFocus();
}

void GameWindow::generateItems()
{
    //generate gold
    gold_timer = new QTimer();
    connect(gold_timer,SIGNAL(timeout()),this,SLOT(generate_golds()));

    //generate bombs
    bomb_timer = new QTimer();
    connect(bomb_timer,SIGNAL(timeout()),this,SLOT(generate_bombs()));

    //generate diamonds
    diamond_timer = new QTimer();
    connect(diamond_timer,SIGNAL(timeout()),this,SLOT(generate_diamonds()));


}

void GameWindow::increase_Score()
{
    score->increase();
}

void GameWindow::increase_diamond()
{
    score->increase_diamond_score();
}

//show game page, when signal receive from mainwindow start
void GameWindow::receiveshow()
{
    countdown->start(1000); //countdown by second
    gold_timer->start(3000);//every 3 sec, generate golds
    diamond_timer->start(10000); //every 7 seconds, generate diamond
    bomb_timer->start(12000); //every 10 seconds, generate bomb
    this->show();
}




//return back to main window
void GameWindow::on_returnmainButton_clicked()
{

    //clear all items
        QList<QGraphicsItem*> all = scene->items();
        for (int i = 0; i < all.size(); i++)
        {
             QGraphicsItem *gi = all[i];
            if ((typeid (*all[i]) == typeid (Bomb))||(typeid (*all[i]) == typeid (Items))||(typeid (*all[i]) == typeid (Diamond)))
            {
                scene->removeItem(gi);
                delete gi;
            }

        }

       set_zero_score();
       this->hide();
       emit showmainwindow();

       //reset game params
       miner->setPos(this->width()/2 - miner->pixmap().width()/2,15);
       miner->setFlag(QGraphicsItem::ItemIsFocusable);
       miner->setFocus();
       set_zero_score();

}



void GameWindow::update_time(){
    time_left-=1;
    timeLCD->display(time_left);
    timeLCD->setStyleSheet("image: url(:/picture/alarmClock.png);background-color: rgba(255, 255, 255, 0);");

    if (time_left==0){
        countdown->stop();
        if ((score->getScore())>=300)
        {
            win->new_score(score->getScore());
            win->show();
            emit win->reset_game();
            this->hide();
        }
        else
        {
            end->new_score(score->getScore());
            end->show();
            emit end->reset_game();
            this->hide();
         }
    }
}

void GameWindow::mutebutton_clicked()
{
    mute();
}


void GameWindow::generate_golds()
{
    //create golds
    items = new Items();//then add this to the same scene
    scene->addItem(items);
}

void GameWindow::generate_diamonds()
{
    diamonds=new Diamond();
    scene->addItem(diamonds);
}

void GameWindow::generate_bombs()
{
    bombs = new Bomb();
    scene->addItem(bombs);
}



void GameWindow::set_time(){
    time_left = 60;
}


void GameWindow::mute()
{
    music->setMuted(true);
}

void GameWindow::reset(){
    //clear all items
        QList<QGraphicsItem*> all = scene->items();
        for (int i = 0; i < all.size(); i++)
        {
            QGraphicsItem *gi = all[i];
            //if a QGraphicsItem is of type Bomb, Items, or Diamond
            if ((typeid (*all[i]) == typeid (Bomb))||(typeid (*all[i]) == typeid (Items))||(typeid (*all[i]) == typeid (Diamond)))
            {
                scene->removeItem(gi);
                delete gi;
            }

        }

       //reset game params
       miner->setPos(this->width()/2 - miner->pixmap().width()/2,15);
       miner->setFlag(QGraphicsItem::ItemIsFocusable);
       miner->setFocus();
       set_zero_score();

}

void GameWindow::restart(){
    countdown->start(1000); //countdown by second
    gold_timer->start(2000);//every 2 sec, generate golds
    diamond_timer->start(5000); //every 5 seconds, generate diamond
    bomb_timer->start(7000); //every 7 seconds, generate bomb
    set_time();
    timeLCD->display(time_left);
    this->show();
}

GameWindow::~GameWindow(){
    delete scene;
    delete miner;
    delete items;
    delete score;
    delete bombs;
    delete diamonds;
    delete countdown;
    delete diamond_timer;
    delete gold_timer;
    delete bomb_timer;
}
