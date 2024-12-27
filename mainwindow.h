#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"buttons.h"
#define PATH "/home/amt-04/ascanmain.db"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    Buttons *but;
};
#endif // MAINWINDOW_H
