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

private slots:
    void on_ButLensBack_clicked();

private:
    Ui::AddLens *ui;
};

#endif // ADDLENS_H
