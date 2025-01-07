#ifndef ADDDOCTOR_H
#define ADDDOCTOR_H

#include <QDialog>
#define PATH "/home/amt-04/ascanmain.db"
#include<QtSql>
#include<QSqlDatabase>
#include<QSqlError>
#include<QSqlQuery>
#include"addlens.h"
#include"textkeypad.h"
#include"intkeypad.h"
namespace Ui {
class AddDoctor;
}

class AddDoctor : public QDialog
{
    Q_OBJECT

public:
    explicit AddDoctor(QWidget *parent = nullptr);
    ~AddDoctor();
    void getlens();
    void getinsertiol(const QString &text);

    void doctoreditdetails(const QString &id,const QString &name,const QString &lens1,const QString &lens2,const QString &lens3,const QString &formula);
private slots:
    void on_ButDocBack_clicked();

    void on_ButDocSave_clicked();
signals:
    void updatedocsql();
    void savedocsql();
    void lastupdatedocid_buttons(const QString &id,const QString &docname);
private:
    Ui::AddDoctor *ui;
    QSqlDatabase mydb1;
    AddLens *l;
   textkeypad *text;
   intkeypad *key;

};

#endif // ADDDOCTOR_H
