#ifndef WINWINDOW_H
#define WINWINDOW_H

#include <QMainWindow>
#include <QDesktopWidget>
#include<QGraphicsPixmapItem>
#include<QPixmap>
#include<score.h>

namespace Ui {
class winwindow;
}

class winwindow : public QMainWindow
{
    Q_OBJECT

public:
    //constructor
    explicit winwindow(QWidget *parent = nullptr);
    //destructor
    ~winwindow();

signals:
    /*
     display score at the win window;  signal is sent to ui file
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
    Ui::winwindow *ui;
    int score;
};

#endif // WINWINDOW_H
