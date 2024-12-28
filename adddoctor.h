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

private slots:
    void on_ButDocBack_clicked();

private:
    Ui::AddDoctor *ui;
};

#endif // ADDDOCTOR_H
