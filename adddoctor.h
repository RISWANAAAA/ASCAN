#ifndef ADDDOCTOR_H
#define ADDDOCTOR_H

#include <QDialog>
#define PATH "/home/amt-04/ascanmain.db"
#include<QtSql>
#include<QSqlDatabase>
#include<QSqlError>
#include<QSqlQuery>
namespace Ui {
class AddDoctor;
}

class AddDoctor : public QDialog
{
    Q_OBJECT

public:
    explicit AddDoctor(QWidget *parent = nullptr);
    ~AddDoctor();
    void doctoreditdetails(const QString &id,const QString &name,const QString &lens1,const QString &lens2,const QString &lens3,const QString &formula);

private slots:
    void on_ButDocBack_clicked();

    void on_ButDocSave_clicked();
signals:
    void updatedocsql();
    void savedocsql();

private:
    Ui::AddDoctor *ui;
    QSqlDatabase mydb1;

};

#endif // ADDDOCTOR_H
