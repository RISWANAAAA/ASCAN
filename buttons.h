#ifndef BUTTONS_H
#define BUTTONS_H

#include <QWidget>
#include <QMouseEvent>
#include<QPushButton>
#define PATH "/home/amt-04/ascanmain.db"
#include<QtSql>
#include<QSqlDatabase>
#include<QSqlError>
#include<QSqlQuery>
#include"adddoctor.h"
#include"addpatient.h"
#include"addlens.h"
#include"viewdoc.h"
#include"viewpatient.h"
#include"currentdocpat.h"

namespace Ui {
class Buttons;
}

class Buttons : public QWidget
{
    Q_OBJECT

public:
    explicit Buttons(QWidget *parent = nullptr);
    ~Buttons();
    void updateButtonState();
    void loadpatientsql();
    void loaddoctorsql();
    void loadlenssql();

    void loadcurrentdoctor();
    void currentFormulaButton(int button);
    void rx_patidname(const QString &id,const QString &name);
protected:
 bool eventFilter(QObject *obj, QEvent *event) override; // Declaration of eventFilter
 void mouseReleaseEvent(QMouseEvent *event) override;
 void mousePressEvent(QMouseEvent *event) override;
 void mouseMoveEvent(QMouseEvent *event) override;


private slots:
    void on_ButPatient_clicked();

    void on_ButDoctor_clicked();

    void on_ButLens_clicked();

    void on_ButMeasure_clicked();

    void on_ButCalculator_clicked();

    void on_ButCalibration_clicked();

    void on_ButSettings_clicked();

    void on_ButPatTouch_clicked();

    void on_ButLensTouch_clicked();

    void on_ButDocTouch_clicked();

    void on_ButPatAdd_clicked();

    void on_ButDocAdd_clicked();

    void on_ButLensAdd_clicked();

    void on_ButPatDelete_clicked();

    void on_ButPatEdit_clicked();

    void on_ButPatView_clicked();

    void on_ButDocDelete_clicked();

    void on_ButDocEdit_clicked();

    void on_ButDocView_clicked();

    void on_ButLensDelete_clicked();

    void on_ButLensEdit_clicked();

    void on_ButCurrent_clicked();

    void on_ButSRKT_clicked();

    void on_ButSRKII_clicked();

    void on_ButHofferQ_clicked();

    void on_ButHolladay_clicked();

    void on_ButHaigis_clicked();

private:
    Ui::Buttons *ui;
    QPushButton *buttons[7];
    int currentButtonIndex;
    QPoint lastMousePosition;
     int swipeDirection;

bool patassistive=false;
bool docassistive=false;
bool lensassistive=false;
addPatient *pat;
AddDoctor *doc;
AddLens *lens;
viewdoc *viewd;
viewpatient *viewp;
QSqlDatabase mydb1;
currentDocPat *Current;

};

#endif // BUTTONS_H
