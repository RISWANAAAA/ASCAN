#ifndef LOADDOCTOR_H
#define LOADDOCTOR_H

#include <QDialog>
//#define PATH "/home/amt-04/ascanmain.db"
#define PATH "ascanmain.db"
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

    void on_ButDocLoad_clicked();


    void on_ButPatLoad_clicked();

signals:
    void sendpatcurrent();
    void loadpatid(const QString &id);
    void loaddocid(const QString &id);
private:
    Ui::loaddoctor *ui;
    QSqlDatabase mydb1;
    bool docassistive=false;
    bool patassistive=false;
    addPatient *Addp;
    AddDoctor *addd;
     QString idPatColumn1;
     QString namePatColumn;
     QString nameDocColumn;
    QString idDocColumn1;
    int selectedRow = -1;     // Store the index of the selected row
        QString selectedID;
};

#endif // LOADDOCTOR_H
