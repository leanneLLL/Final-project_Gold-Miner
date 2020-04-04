#include "winwindow.h"
#include "ui_winwindow.h"

winwindow::winwindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::winwindow)
{
    ui->setupUi(this);
    this->setFixedSize(800, 600);
    this->setWindowTitle(tr("You Win!"));
    //set background picture
    QPixmap background(":/picture/win.jpg");
    background = background.scaled(this->size(),Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, background);
    this->setPalette(palette);

    score=0;

    //window set central
    QDesktopWidget* desktop = QApplication::desktop();
    move((desktop->width() - this->width())/2, (desktop->height() - this->height())/2);

}

winwindow::~winwindow()
{
    delete ui;
}

void winwindow::new_score(int i)
{
    emit update_score(i);
}

void winwindow::on_pushButton_clicked()
{
    this->hide();
    emit restart_game();
}
