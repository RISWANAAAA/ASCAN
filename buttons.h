#ifndef BUTTONS_H
#define BUTTONS_H

#include <QWidget>
#include <QMouseEvent>
#include<QPushButton>
//#define PATH "/home/amt-04/ascanmain.db"
#define PATH "ascanmain.db"
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
#include"calformula.h"
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

    void currentFormulaButton(int button);
    void loadLastDoctor();
    void rx_lastdoctid(const QString &id,const QString &docname);
    void rx_currentButton(const QString &id,const QString &docname);
    void rx_insertiol_addlens(const QString &text);
    void getlens();
    void setupConnections();
    void setupconnectionsSRKT();
    void setupconnectionsHOFFERQ();
    void setupconnectionsHOLLADAY();
    void setupconnectionsHAIGIS();
    void srkiilinechanged();
public slots:
    void rx_patidname(const QString &id,const QString &name);
    void rx_currentpatidname(const QString &id,const QString &name);
    void onDoctorDetailsChanged();
    void updateLineEdit(QComboBox *comboBox, QLineEdit *lineEdit);
    void updateLineEditSRKT(QComboBox *comboBox, QLineEdit *lineEdit);
    void updateLineEditHOFFERQ(QComboBox *comboBox, QLineEdit *lineEdit);

    void updateLineEditHOLLADAY(QComboBox *comboBox, QLineEdit *lineEdit);

    void updateLineEditHAIGIS(QComboBox *comboBox, QLineEdit *lineEdit);

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
signals:
    void sendidtocurrent(const QString &id);
    void tx_currentpatdoc_main(const QString &id);
    void tx_docidtocurrent(const QString &id);
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
CalFormula *formula;
int rx_value;
int axial_length;
int keratometer;

};

#endif // BUTTONS_H
