#ifndef BUTTONS_H
#define BUTTONS_H

#include <QWidget>
#include <QMouseEvent>
#include<QPushButton>
#define PATH "/home/amt-04/ascanmain.db"
#include<QtSql>
#include<QSqlDatabase>
#include<QSqlError>
#include<QSqlQuery>

namespace Ui {
class Buttons;
}

class Buttons : public QWidget
{
    Q_OBJECT

public:
    explicit Buttons(QWidget *parent = nullptr);
    ~Buttons();
    void updateButtonState();
    void loadpatientsql();
    void loaddoctorsql();
    void loadlenssql();

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;


private slots:
    void on_ButPatient_clicked();

    void on_ButDoctor_clicked();

    void on_ButLens_clicked();

    void on_ButMeasure_clicked();

    void on_ButCalculator_clicked();

    void on_ButCalibration_clicked();

    void on_ButSettings_clicked();

    void on_ButPatTouch_clicked();

    void on_ButLensTouch_clicked();

    void on_ButDocTouch_clicked();

private:
    Ui::Buttons *ui;
    QPushButton *buttons[7];
    int currentButtonIndex;
    QPoint lastMousePosition;
     int swipeDirection;

bool patassistive=false;
bool docassistive=false;
bool lensassistive=false;

};

#endif // BUTTONS_H
