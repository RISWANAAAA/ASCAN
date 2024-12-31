#ifndef ADDLENS_H
#define ADDLENS_H

#include <QDialog>
#define PATH "/home/amt-04/ascanmain.db"
#include<QtSql>
#include<QSqlDatabase>
#include<QSqlError>
#include<QSqlQuery>
namespace Ui {
class AddLens;
}

class AddLens : public QDialog
{
    Q_OBJECT

public:
    explicit AddLens(QWidget *parent = nullptr);
    ~AddLens();
    void editlensdetails(const QString &iol,const QString &type,const QString &asrkt,const QString &asrkii,const QString &acd,const QString &sf,const QString &a0,const QString &a1,const QString &a2);
private slots:
    void on_ButLensBack_clicked();

    void on_ButLensSave_clicked();
signals:
    void updatelenssql();
    void savelenssql();
private:
    Ui::AddLens *ui;
    QSqlDatabase mydb1;

};

#endif // ADDLENS_H
