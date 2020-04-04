#ifndef BOMB_ENDWINDOW_H
#define BOMB_ENDWINDOW_H

#include <QMainWindow>
#include<QGraphicsPixmapItem>
#include<QPixmap>
#include <QDesktopWidget>
#include<score.h>

namespace Ui {
class bomb_endwindow;
}

class bomb_endwindow : public QMainWindow
{
    Q_OBJECT

public:
    //constructor
    explicit bomb_endwindow(QWidget *parent = nullptr);
    //destructor
    ~bomb_endwindow();

signals:
    /*
     display score at the bomb end window;  signal is sent to ui file
     @param the score, an integer
    */
    void update_score(int);

    /*
     reset gamewindow scene; signal is sent to game window
    */
    void reset_game();

    /*
     restart the game; signal is sent to game window
    */
    void restart_game();

public slots:
    /*
     get the current game score; signal is sent from game window
     */
    void new_score(int i);

private slots:
    /*
     restart the game if the button restart is clicked
    */
    void on_pushButton_clicked();

private:
    Ui::bomb_endwindow *ui;
    int score;
};

#endif // BOMB_ENDWINDOW_H
