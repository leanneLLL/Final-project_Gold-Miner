#include "endwindow.h"
#include "ui_endwindow.h"


endwindow::endwindow(QWidget *parent) :QMainWindow(parent), ui(new Ui::endwindow)
{
    ui->setupUi(this);
    this->setFixedSize(800, 600);
    this->setWindowTitle(tr("Game Over"));
    //set background picture
    QPixmap background(":/picture/gameOver.jpg");
    background = background.scaled(this->size(),Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, background);
    this->setPalette(palette);
    score=0;
    //window set central
    QDesktopWidget* desktop = QApplication::desktop();
    move((desktop->width() - this->width())/2, (desktop->height() - this->height())/2);

}

endwindow::~endwindow()
{
    delete ui;
}

void endwindow::new_score(int i)
{
    emit update_score(i);
}


void endwindow::on_pushButton_clicked()
{
    this->hide();
    emit restart_game();
}
