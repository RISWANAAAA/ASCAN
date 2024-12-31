#ifndef LOADDOCTOR_H
#define LOADDOCTOR_H

#include <QDialog>
#define PATH "/home/amt-04/ascanmain.db"
#include<QtSql>
#include<QSqlDatabase>
#include<QSqlError>
#include"adddoctor.h"
#include"addpatient.h"
namespace Ui {
class loaddoctor;
}

class loaddoctor : public QDialog
{
    Q_OBJECT

public:
    explicit loaddoctor(QWidget *parent = nullptr);
    ~loaddoctor();
    void loaddoctorsql();
    void loadpatientsql();

private slots:

    void on_ButPatTouch_clicked();

    void on_ButPatAdd_clicked();

    void on_ButDocAdd_clicked();

    void on_ButDocTouch_clicked();
    void on_pushButton_clicked();

signals:
    void sendpatcurrent();
private:
    Ui::loaddoctor *ui;
    QSqlDatabase mydb1;
    bool docassistive=false;
    bool patassistive=false;
    addPatient *Addp;
    AddDoctor *addd;

};

#endif // LOADDOCTOR_H
