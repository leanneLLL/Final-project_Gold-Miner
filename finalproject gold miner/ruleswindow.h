#ifndef RULESWINDOW_H
#define RULESWINDOW_H

#include <QDialog>
#include <QDesktopWidget>
#include <mainwindow.h>
namespace Ui {
class rulesWindow;
}

class rulesWindow : public QDialog
{
    Q_OBJECT

public:
    //constructor
    explicit rulesWindow(QWidget *parent = nullptr);
    //destructor
    ~rulesWindow();
private:
    Ui::rulesWindow *ui;
private slots:
    /*
     show game instructions, signal received from mainwindow
     */
    void receiveshow();

    /*
    return to mainwindow if the return button is clicked
    */
    void on_returnButton_clicked();

signals:

    /*
     signal is sent to mainwindow for it to show
    */
    void showmainwindow();
};

#endif // RULESWINDOW_H
