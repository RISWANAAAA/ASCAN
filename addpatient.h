#ifndef ADDPATIENT_H
#define ADDPATIENT_H

#include <QDialog>
#define PATH "/home/amt-04/ascanmain.db"
#include<QtSql>
#include<QSqlDatabase>
#include<QSqlError>
#include<QSqlQuery>
#include"intkeypad.h"
#include"textkeypad.h"
#include <QMouseEvent>

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
    bool eventFilter(QObject* object, QEvent* event);

private slots:
    void on_ButPatBack_clicked();
    void on_ButPatSave_clicked();
    void on_clicked(const QString& digit);
    void on_clickedenter();
   void handleClearSignal();
signals:
    void updatepatsql();
    void savepatsql();
    void saveforload();
    void savepatid_name(const QString &id,const QString &name);
private:
    Ui::addPatient *ui;
    QSqlDatabase mydb1;
    textkeypad *text;
    intkeypad *key;
    QMap<QLineEdit*, int> lastValidValues;


};

#endif // ADDPATIENT_H
