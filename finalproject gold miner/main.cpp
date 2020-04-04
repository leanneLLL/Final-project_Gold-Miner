#include "mainwindow.h"
#include "gamewindow.h"
#include "bomb_endwindow.h"
#include "ruleswindow.h"
#include "endwindow.h"
#include <QApplication>


bomb_endwindow* b;
GameWindow * gamewindow;
rulesWindow * r;
endwindow* end;


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    gamewindow = new GameWindow();
    b = new bomb_endwindow();
    r = new rulesWindow();
    end = new endwindow();

    QObject::connect(&w,SIGNAL(quit()),&a,SLOT(quit()));//connect mainwindow quit, application quit
    QObject::connect(&w,SIGNAL(dlgshow()),gamewindow,SLOT(receiveshow()));//connect mainwindow call game window, game window show
    QObject::connect(&w,SIGNAL(rulesShow()),r,SLOT(receiveshow()));

    //connect game window call main windiw, maindow show
    QObject::connect(gamewindow,SIGNAL(showmainwindow()),&w,SLOT(receiveReturn()));
    QObject::connect(r,SIGNAL(showmainwindow()),&w,SLOT(receiveReturn()));

    //restart game
    QObject::connect(b,SIGNAL(restart_game()),gamewindow,SLOT(restart()));
    QObject::connect(b,SIGNAL(reset_game()),gamewindow,SLOT(reset()));

    return a.exec();
}
