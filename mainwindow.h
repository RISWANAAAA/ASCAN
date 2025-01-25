#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"buttons.h"
//#define PATH "/home/amt-04/ascanmain.db"
#define PATH "ascanmain.db"
#include<QtSql>
#include<QSqlDatabase>
#include<QSqlError>
#include<QSqlQuery>
#include"addpatient.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void loadlastpatient();
    void select_patient();
    void updateComboBox(const QString id, const QString &name);
    void updateComboBox1(const QString id, const QString &name);

void saveSelectedPatient(const QString &id, const QString &name);

void onComboBoxSelectionChanged();
void onPatientSelected(const QString &id);
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();
signals:
    void sendpatientsql();
    void sendpatientid(const QString &id,const QString &name);
    void emitpatientidname(const QString &id,const QString &name);

private:
    Ui::MainWindow *ui;
    Buttons *but;
    addPatient *addp;
    loaddoctor *load;
    QSqlDatabase mydb1;
    QString id;
    QString name;
    QString lastSelectedPatientID;
    QString lastSelectedPatientName;

};
#endif // MAINWINDOW_H
