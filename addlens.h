#ifndef ADDLENS_H
#define ADDLENS_H

#include <QDialog>
//#define PATH "/home/amt-04/ascanmain.db"
#define PATH "ascanmain.db"
#include<QtSql>
#include<QSqlDatabase>
#include<QSqlError>
#include<QSqlQuery>
#include"intkeypad.h"
#include"textkeypad.h"
#include<QMouseEvent>
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
    bool eventFilter(QObject* object, QEvent* event);

private slots:

    void on_ButLensBack_clicked();

    void on_ButLensSave_clicked();
    void on_clicked(const QString& digit);
    void on_clickedenter();
void spaceclicked();
   void handleClearSignal();
signals:
    void updatelenssql();
    void savelenssql();
    void tx_insertiol(const QString &iol);
private:
    Ui::AddLens *ui;
    QSqlDatabase mydb1;
    textkeypad *text;
    intkeypad *key;
    QMap<QLineEdit*, int> lastValidValues;
    QMap<QLineEdit*, QString> lastValidValues1;


};

#endif // ADDLENS_H
