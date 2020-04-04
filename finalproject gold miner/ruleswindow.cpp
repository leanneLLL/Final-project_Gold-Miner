#include "ruleswindow.h"
#include "ui_ruleswindow.h"

rulesWindow::rulesWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::rulesWindow)
{
    ui->setupUi(this);

    setFixedSize(800, 600);
    setWindowTitle(tr("Game Instruction"));

    //window set central
    QDesktopWidget* desktop = QApplication::desktop();
    move((desktop->width() - this->width())/2, (desktop->height() - this->height())/2);

    //add background picture
    QPixmap background(":/picture/instruction3.jpg");
    background=background.scaled(this->size(),Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background,background);
    this->setPalette(palette);

    //cursor
    QPixmap pixmap(":/picture/ccc.png");
    QCursor cursor= QCursor(pixmap,-1,-1);
    setCursor(cursor);
}

rulesWindow::~rulesWindow()
{
    delete ui;
}

void rulesWindow::receiveshow()
{
    this->show();
}

void rulesWindow::on_returnButton_clicked()
{
    this->hide();
    emit showmainwindow();
}
