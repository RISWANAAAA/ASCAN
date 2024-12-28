#ifndef ADDPATIENT_H
#define ADDPATIENT_H

#include <QDialog>
#define PATH "/home/amt-04/ascanmain.db"
#include<QtSql>
#include<QSqlDatabase>
#include<QSqlError>
#include<QSqlQuery>
namespace Ui {
class addPatient;
}

class addPatient : public QDialog
{
    Q_OBJECT

public:
    explicit addPatient(QWidget *parent = nullptr);
    ~addPatient();
    void setpatientDetails(const QString &id, const QString &name, const QString &age, const QString &gender,const QString &number,const QString &method,const QString &mode,const QString &eye,const QString &keratol1,QString keratol2,const QString &keratol,const QString kerator1,const QString kerator2,const QString kerator);

private slots:
    void on_ButPatBack_clicked();
    void on_ButPatSave_clicked();

signals:
    void updatepatsql();
    void savepatsql();
private:
    Ui::addPatient *ui;
    QSqlDatabase mydb1;

};

#endif // ADDPATIENT_H
