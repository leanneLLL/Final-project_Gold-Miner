#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>

#include <QStackedWidget>
#include <QLabel>
#include <QPushButton>

#include <QWidget>
#include <QDesktopWidget>
#include <QPixmap>
QT_BEGIN_NAMESPACE


namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
private slots:
    void receiveReturn();//receive the return button signal from the gamewindow
    void on_buttonStart_clicked();//starbutton
    void on_buttonRules_clicked();//rules button
    void on_buttonMute_clicked();//mute button

signals:
    void dlgshow();//show the gamewindow
    void quit();//quit the applicatin
    void rulesShow();// show the instruction window


};
#endif // MAINWINDOW_H
