#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gamewindow.h"

extern GameWindow* gamewindow;

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setFixedSize(800, 600);
    //setWindowFlags(Qt::FramelessWindowHint);
    setWindowTitle(tr("Gold Miner 1.0"));
    //window set central
    QDesktopWidget* desktop = QApplication::desktop();
    move((desktop->width() - this->width())/2, (desktop->height() - this->height())/2);

    //add background picture
    QPixmap background(":/picture/blackBackground.jpg");
    background=background.scaled(this->size(),Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background,background);
    this->setPalette(palette);


    //set coursor image
    QPixmap pixmap(":/picture/ccc.png");
    QCursor cursor= QCursor(pixmap,-1,-1);
    setCursor(cursor);




}

MainWindow::~MainWindow()
{
    delete ui;
}




//start button , start new game
void MainWindow::on_buttonStart_clicked()
{
    this->hide();
    emit dlgshow();
    gamewindow->set_time();

    //emit quit();
}

//rules, direct to rules & instruction page
void MainWindow::on_buttonRules_clicked()
{
    this->hide();
    //emit quit();
    emit rulesShow();
}

//receive signal from game page, return main window
void MainWindow::receiveReturn()
{
    this->show();
}

void MainWindow::on_buttonMute_clicked()
{
    gamewindow->mute();

}
