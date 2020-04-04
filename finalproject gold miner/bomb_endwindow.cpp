#include "bomb_endwindow.h"
#include "ui_bomb_endwindow.h"
#include "gamewindow.h"

extern GameWindow* gamewindow;
bomb_endwindow::bomb_endwindow(QWidget *parent): QMainWindow(parent), ui(new Ui::bomb_endwindow)
{
    ui->setupUi(this);
    this->setFixedSize(800, 600);
    this->setWindowTitle(tr("Killed by a Bomb"));

    //set background picture
    QPixmap background(":/picture/gameOver.jpg");
    background = background.scaled(this->size(),Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, background);
    this->setPalette(palette);
    score=0;
}

void bomb_endwindow::new_score(int i) {
    emit update_score(i);
}

bomb_endwindow::~bomb_endwindow()
{
    delete ui;
}

void bomb_endwindow::on_pushButton_clicked()
{
    this->close();
    emit restart_game();
}
