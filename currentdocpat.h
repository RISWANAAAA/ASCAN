#ifndef CURRENTDOCPAT_H
#define CURRENTDOCPAT_H

#include <QDialog>
#include"loaddoctor.h"
//#define PATH "/home/amt-04/ascanmain.db"
#define PATH "ascanmain.db"
#include<QtSql>
#include<QSqlDatabase>
#include<QSqlError>
namespace Ui {
class currentDocPat;
}

class currentDocPat : public QDialog
{
    Q_OBJECT

public:
    explicit currentDocPat(QWidget *parent = nullptr);
    ~currentDocPat();
    void rx_fromloaddoc();
   void loadcurrentpatientid(const QString &id);
   void loadcurrentdoctorid(const QString &id);

private slots:
    void on_ButDocSql_clicked();

    void on_ButPatSql_clicked();
    void on_Butok_clicked();
    void onTabChanged(int index);

signals:
    void loaddocsqldatabase();
    void loadpatsqldatabase();
    void tx_main();
    void tx_patdocnameid_main(const QString &id,const QString &name);
    void tx_docidname_button(const QString &id,const QString &name);
private:
    Ui::currentDocPat *ui;
    loaddoctor *load;
    QSqlDatabase mydb1;
    QString lastSelectedPatientID;
    QString lastSelectedPatientName;

};

#endif // CURRENTDOCPAT_H
