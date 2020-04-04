#ifndef ENDWINDOW_H
#define ENDWINDOW_H

#include <QMainWindow>
#include <QDesktopWidget>
#include<QGraphicsPixmapItem>
#include<QPixmap>
#include<score.h>

namespace Ui {
class endwindow;
}

class endwindow : public QMainWindow
{
    Q_OBJECT

public:
    //constructor
    explicit endwindow(QWidget *parent = nullptr);
    //destructor
    ~endwindow();

signals:
    /*
     display score at the end window;  signal is sent to ui file
     @param the score, an integer
    */
    void update_score(int);

    /*
     reset gamewindow scene; signal is sent to game window
    */
    void reset_game();

    /*
     get the current game score; signal is sent from game window
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
    Ui::endwindow *ui;
    int score;
};

#endif // ENDWINDOW_H
