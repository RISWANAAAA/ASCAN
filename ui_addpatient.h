/********************************************************************************
** Form generated from reading UI file 'addpatient.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDPATIENT_H
#define UI_ADDPATIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_addPatient
{
public:
    QLabel *label;
    QLabel *lblpatid;
    QLineEdit *linepatid;
    QLabel *lblpatname;
    QLineEdit *linepatname;
    QLabel *lblpatdetails;
    QLabel *lblpatage;
    QLineEdit *linepatage;
    QLabel *lblpatphone;
    QLineEdit *linepatphone;
    QLabel *lblpatgender;
    QCheckBox *CheckMale;
    QCheckBox *CheckFemale;
    QCheckBox *CheckOther;
    QCheckBox *CheckImmersion;
    QCheckBox *CheckContact;
    QLabel *lblpatopmode;
    QCheckBox *CheckPhakic;
    QLabel *lblpatopmethod;
    QCheckBox *CheckApakic;
    QCheckBox *CheckDense;
    QCheckBox *CheckRight;
    QLabel *lblpatopeye;
    QCheckBox *CheckLeft;
    QLabel *lblpatkleft;
    QLabel *lblpatkl1;
    QLineEdit *linepatkl1;
    QLabel *lblpatkl2;
    QLineEdit *linepatkl2;
    QLabel *lblpatkl;
    QLineEdit *linepatkl;
    QLabel *lblpatkr2;
    QLabel *lblpatkright;
    QLabel *lblpatkr1;
    QLabel *lblpatkr;
    QLineEdit *linepatkr;
    QLineEdit *linepatkr2;
    QLineEdit *linepatkr1;
    QPushButton *ButPatSave;
    QPushButton *ButPatBack;

    void setupUi(QDialog *addPatient)
    {
        if (addPatient->objectName().isEmpty())
            addPatient->setObjectName(QString::fromUtf8("addPatient"));
        addPatient->resize(700, 700);
        label = new QLabel(addPatient);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 700, 700));
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 117, 143);"));
        lblpatid = new QLabel(addPatient);
        lblpatid->setObjectName(QString::fromUtf8("lblpatid"));
        lblpatid->setGeometry(QRect(10, 50, 101, 41));
        lblpatid->setStyleSheet(QString::fromUtf8("background-color: rgb(222, 221, 218);\n"
"font: 75 20pt \"Ubuntu\";\n"
"font:bold;"));
        lblpatid->setAlignment(Qt::AlignCenter);
        linepatid = new QLineEdit(addPatient);
        linepatid->setObjectName(QString::fromUtf8("linepatid"));
        linepatid->setGeometry(QRect(110, 50, 121, 41));
        lblpatname = new QLabel(addPatient);
        lblpatname->setObjectName(QString::fromUtf8("lblpatname"));
        lblpatname->setGeometry(QRect(310, 50, 111, 41));
        lblpatname->setStyleSheet(QString::fromUtf8("background-color: rgb(222, 221, 218);\n"
"font: 75 20pt \"Ubuntu\";\n"
"font:bold;"));
        lblpatname->setAlignment(Qt::AlignCenter);
        linepatname = new QLineEdit(addPatient);
        linepatname->setObjectName(QString::fromUtf8("linepatname"));
        linepatname->setGeometry(QRect(420, 50, 251, 41));
        lblpatdetails = new QLabel(addPatient);
        lblpatdetails->setObjectName(QString::fromUtf8("lblpatdetails"));
        lblpatdetails->setGeometry(QRect(180, 10, 321, 31));
        lblpatdetails->setStyleSheet(QString::fromUtf8("background-color: rgb(222, 221, 218);\n"
"font: 75 20pt \"Ubuntu\";\n"
"font:bold;"));
        lblpatdetails->setAlignment(Qt::AlignCenter);
        lblpatage = new QLabel(addPatient);
        lblpatage->setObjectName(QString::fromUtf8("lblpatage"));
        lblpatage->setGeometry(QRect(10, 130, 111, 41));
        lblpatage->setStyleSheet(QString::fromUtf8("background-color: rgb(222, 221, 218);\n"
"font: 75 20pt \"Ubuntu\";\n"
"font:bold;"));
        lblpatage->setAlignment(Qt::AlignCenter);
        linepatage = new QLineEdit(addPatient);
        linepatage->setObjectName(QString::fromUtf8("linepatage"));
        linepatage->setGeometry(QRect(120, 130, 151, 41));
        lblpatphone = new QLabel(addPatient);
        lblpatphone->setObjectName(QString::fromUtf8("lblpatphone"));
        lblpatphone->setGeometry(QRect(280, 130, 131, 41));
        lblpatphone->setStyleSheet(QString::fromUtf8("background-color: rgb(222, 221, 218);\n"
"font: 75 20pt \"Ubuntu\";\n"
"font:bold;"));
        lblpatphone->setAlignment(Qt::AlignCenter);
        linepatphone = new QLineEdit(addPatient);
        linepatphone->setObjectName(QString::fromUtf8("linepatphone"));
        linepatphone->setGeometry(QRect(410, 130, 271, 41));
        lblpatgender = new QLabel(addPatient);
        lblpatgender->setObjectName(QString::fromUtf8("lblpatgender"));
        lblpatgender->setGeometry(QRect(10, 190, 131, 41));
        lblpatgender->setStyleSheet(QString::fromUtf8("background-color: rgb(222, 221, 218);\n"
"font: 75 20pt \"Ubuntu\";\n"
"font:bold;"));
        lblpatgender->setAlignment(Qt::AlignCenter);
        CheckMale = new QCheckBox(addPatient);
        CheckMale->setObjectName(QString::fromUtf8("CheckMale"));
        CheckMale->setGeometry(QRect(160, 200, 111, 31));
        CheckMale->setStyleSheet(QString::fromUtf8("QCheckBox {\n"
"    font-size: 25px;\n"
"    color: rgb(255, 255, 255);\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QCheckBox::indicator {\n"
"    width: 20px;\n"
"    height: 20px;\n"
"    background-color: black;\n"
"    border: 1px solid gray;\n"
"}\n"
"\n"
"QCheckBox::indicator:checked {\n"
"    background-color: black;\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked {\n"
"    background-color: white;\n"
"    border: 1px solid gray;\n"
"}\n"
""));
        CheckFemale = new QCheckBox(addPatient);
        CheckFemale->setObjectName(QString::fromUtf8("CheckFemale"));
        CheckFemale->setGeometry(QRect(270, 200, 131, 31));
        CheckFemale->setStyleSheet(QString::fromUtf8("QCheckBox {\n"
"    font-size: 25px;\n"
"    color: rgb(255, 255, 255);\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QCheckBox::indicator {\n"
"    width: 20px;\n"
"    height: 20px;\n"
"    background-color: black;\n"
"    border: 1px solid gray;\n"
"}\n"
"\n"
"QCheckBox::indicator:checked {\n"
"    background-color: black;\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked {\n"
"    background-color: white;\n"
"    border: 1px solid gray;\n"
"}\n"
""));
        CheckOther = new QCheckBox(addPatient);
        CheckOther->setObjectName(QString::fromUtf8("CheckOther"));
        CheckOther->setGeometry(QRect(420, 200, 111, 31));
        CheckOther->setStyleSheet(QString::fromUtf8("QCheckBox {\n"
"    font-size: 25px;\n"
"    color: rgb(255, 255, 255);\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QCheckBox::indicator {\n"
"    width: 20px;\n"
"    height: 20px;\n"
"    background-color: black;\n"
"    border: 1px solid gray;\n"
"}\n"
"\n"
"QCheckBox::indicator:checked {\n"
"    background-color: black;\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked {\n"
"    background-color: white;\n"
"    border: 1px solid gray;\n"
"}\n"
""));
        CheckImmersion = new QCheckBox(addPatient);
        CheckImmersion->setObjectName(QString::fromUtf8("CheckImmersion"));
        CheckImmersion->setGeometry(QRect(440, 310, 191, 31));
        CheckImmersion->setStyleSheet(QString::fromUtf8("QCheckBox {\n"
"    font-size: 25px;\n"
"    color: rgb(255, 255, 255);\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QCheckBox::indicator {\n"
"    width: 20px;\n"
"    height: 20px;\n"
"    background-color: black;\n"
"    border: 1px solid gray;\n"
"}\n"
"\n"
"QCheckBox::indicator:checked {\n"
"    background-color: black;\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked {\n"
"    background-color: white;\n"
"    border: 1px solid gray;\n"
"}\n"
""));
        CheckContact = new QCheckBox(addPatient);
        CheckContact->setObjectName(QString::fromUtf8("CheckContact"));
        CheckContact->setGeometry(QRect(300, 310, 131, 31));
        CheckContact->setStyleSheet(QString::fromUtf8("QCheckBox {\n"
"    font-size: 25px;\n"
"    color: rgb(255, 255, 255);\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QCheckBox::indicator {\n"
"    width: 20px;\n"
"    height: 20px;\n"
"    background-color: black;\n"
"    border: 1px solid gray;\n"
"}\n"
"\n"
"QCheckBox::indicator:checked {\n"
"    background-color: black;\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked {\n"
"    background-color: white;\n"
"    border: 1px solid gray;\n"
"}\n"
""));
        lblpatopmode = new QLabel(addPatient);
        lblpatopmode->setObjectName(QString::fromUtf8("lblpatopmode"));
        lblpatopmode->setGeometry(QRect(10, 306, 271, 41));
        lblpatopmode->setStyleSheet(QString::fromUtf8("background-color: rgb(222, 221, 218);\n"
"font: 75 20pt \"Ubuntu\";\n"
"font:bold;"));
        lblpatopmode->setAlignment(Qt::AlignCenter);
        CheckPhakic = new QCheckBox(addPatient);
        CheckPhakic->setObjectName(QString::fromUtf8("CheckPhakic"));
        CheckPhakic->setGeometry(QRect(440, 255, 121, 31));
        CheckPhakic->setStyleSheet(QString::fromUtf8("QCheckBox {\n"
"    font-size: 25px;\n"
"    color: rgb(255, 255, 255);\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QCheckBox::indicator {\n"
"    width: 20px;\n"
"    height: 20px;\n"
"    background-color: black;\n"
"    border: 1px solid gray;\n"
"}\n"
"\n"
"QCheckBox::indicator:checked {\n"
"    background-color: black;\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked {\n"
"    background-color: white;\n"
"    border: 1px solid gray;\n"
"}\n"
""));
        lblpatopmethod = new QLabel(addPatient);
        lblpatopmethod->setObjectName(QString::fromUtf8("lblpatopmethod"));
        lblpatopmethod->setGeometry(QRect(10, 250, 271, 41));
        lblpatopmethod->setStyleSheet(QString::fromUtf8("background-color: rgb(222, 221, 218);\n"
"font: 75 20pt \"Ubuntu\";\n"
"font:bold;"));
        lblpatopmethod->setAlignment(Qt::AlignCenter);
        CheckApakic = new QCheckBox(addPatient);
        CheckApakic->setObjectName(QString::fromUtf8("CheckApakic"));
        CheckApakic->setGeometry(QRect(300, 255, 131, 31));
        CheckApakic->setStyleSheet(QString::fromUtf8("QCheckBox {\n"
"    font-size: 25px;\n"
"    color: rgb(255, 255, 255);\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QCheckBox::indicator {\n"
"    width: 20px;\n"
"    height: 20px;\n"
"    background-color: black;\n"
"    border: 1px solid gray;\n"
"}\n"
"\n"
"QCheckBox::indicator:checked {\n"
"    background-color: black;\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked {\n"
"    background-color: white;\n"
"    border: 1px solid gray;\n"
"}\n"
""));
        CheckDense = new QCheckBox(addPatient);
        CheckDense->setObjectName(QString::fromUtf8("CheckDense"));
        CheckDense->setGeometry(QRect(580, 255, 111, 31));
        CheckDense->setStyleSheet(QString::fromUtf8("QCheckBox {\n"
"    font-size: 25px;\n"
"    color: rgb(255, 255, 255);\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QCheckBox::indicator {\n"
"    width: 20px;\n"
"    height: 20px;\n"
"    background-color: black;\n"
"    border: 1px solid gray;\n"
"}\n"
"\n"
"QCheckBox::indicator:checked {\n"
"    background-color: black;\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked {\n"
"    background-color: white;\n"
"    border: 1px solid gray;\n"
"}\n"
""));
        CheckRight = new QCheckBox(addPatient);
        CheckRight->setObjectName(QString::fromUtf8("CheckRight"));
        CheckRight->setGeometry(QRect(440, 370, 191, 31));
        CheckRight->setStyleSheet(QString::fromUtf8("QCheckBox {\n"
"    font-size: 25px;\n"
"    color: rgb(255, 255, 255);\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QCheckBox::indicator {\n"
"    width: 20px;\n"
"    height: 20px;\n"
"    background-color: black;\n"
"    border: 1px solid gray;\n"
"}\n"
"\n"
"QCheckBox::indicator:checked {\n"
"    background-color: black;\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked {\n"
"    background-color: white;\n"
"    border: 1px solid gray;\n"
"}\n"
""));
        lblpatopeye = new QLabel(addPatient);
        lblpatopeye->setObjectName(QString::fromUtf8("lblpatopeye"));
        lblpatopeye->setGeometry(QRect(10, 366, 271, 41));
        lblpatopeye->setStyleSheet(QString::fromUtf8("background-color: rgb(222, 221, 218);\n"
"font: 75 20pt \"Ubuntu\";\n"
"font:bold;"));
        lblpatopeye->setAlignment(Qt::AlignCenter);
        CheckLeft = new QCheckBox(addPatient);
        CheckLeft->setObjectName(QString::fromUtf8("CheckLeft"));
        CheckLeft->setGeometry(QRect(300, 370, 141, 31));
        CheckLeft->setStyleSheet(QString::fromUtf8("QCheckBox {\n"
"    font-size: 25px;\n"
"    color: rgb(255, 255, 255);\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QCheckBox::indicator {\n"
"    width: 20px;\n"
"    height: 20px;\n"
"    background-color: black;\n"
"    border: 1px solid gray;\n"
"}\n"
"\n"
"QCheckBox::indicator:checked {\n"
"    background-color: black;\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked {\n"
"    background-color: white;\n"
"    border: 1px solid gray;\n"
"}\n"
""));
        lblpatkleft = new QLabel(addPatient);
        lblpatkleft->setObjectName(QString::fromUtf8("lblpatkleft"));
        lblpatkleft->setGeometry(QRect(420, 420, 271, 41));
        lblpatkleft->setStyleSheet(QString::fromUtf8("background-color: rgb(222, 221, 218);\n"
"font: 75 20pt \"Ubuntu\";\n"
"font:bold;"));
        lblpatkleft->setAlignment(Qt::AlignCenter);
        lblpatkl1 = new QLabel(addPatient);
        lblpatkl1->setObjectName(QString::fromUtf8("lblpatkl1"));
        lblpatkl1->setGeometry(QRect(10, 470, 101, 41));
        lblpatkl1->setStyleSheet(QString::fromUtf8("background-color: rgb(222, 221, 218);\n"
"font: 75 20pt \"Ubuntu\";\n"
"font:bold;"));
        lblpatkl1->setAlignment(Qt::AlignCenter);
        linepatkl1 = new QLineEdit(addPatient);
        linepatkl1->setObjectName(QString::fromUtf8("linepatkl1"));
        linepatkl1->setGeometry(QRect(110, 470, 121, 41));
        lblpatkl2 = new QLabel(addPatient);
        lblpatkl2->setObjectName(QString::fromUtf8("lblpatkl2"));
        lblpatkl2->setGeometry(QRect(240, 470, 101, 41));
        lblpatkl2->setStyleSheet(QString::fromUtf8("background-color: rgb(222, 221, 218);\n"
"font: 75 20pt \"Ubuntu\";\n"
"font:bold;"));
        lblpatkl2->setAlignment(Qt::AlignCenter);
        linepatkl2 = new QLineEdit(addPatient);
        linepatkl2->setObjectName(QString::fromUtf8("linepatkl2"));
        linepatkl2->setGeometry(QRect(340, 470, 121, 41));
        lblpatkl = new QLabel(addPatient);
        lblpatkl->setObjectName(QString::fromUtf8("lblpatkl"));
        lblpatkl->setGeometry(QRect(470, 470, 101, 41));
        lblpatkl->setStyleSheet(QString::fromUtf8("background-color: rgb(222, 221, 218);\n"
"font: 75 20pt \"Ubuntu\";\n"
"font:bold;"));
        lblpatkl->setAlignment(Qt::AlignCenter);
        linepatkl = new QLineEdit(addPatient);
        linepatkl->setObjectName(QString::fromUtf8("linepatkl"));
        linepatkl->setGeometry(QRect(570, 470, 121, 41));
        lblpatkr2 = new QLabel(addPatient);
        lblpatkr2->setObjectName(QString::fromUtf8("lblpatkr2"));
        lblpatkr2->setGeometry(QRect(240, 570, 101, 41));
        lblpatkr2->setStyleSheet(QString::fromUtf8("background-color: rgb(222, 221, 218);\n"
"font: 75 20pt \"Ubuntu\";\n"
"font:bold;"));
        lblpatkr2->setAlignment(Qt::AlignCenter);
        lblpatkright = new QLabel(addPatient);
        lblpatkright->setObjectName(QString::fromUtf8("lblpatkright"));
        lblpatkright->setGeometry(QRect(390, 520, 301, 41));
        lblpatkright->setStyleSheet(QString::fromUtf8("background-color: rgb(222, 221, 218);\n"
"font: 75 20pt \"Ubuntu\";\n"
"font:bold;"));
        lblpatkright->setAlignment(Qt::AlignCenter);
        lblpatkr1 = new QLabel(addPatient);
        lblpatkr1->setObjectName(QString::fromUtf8("lblpatkr1"));
        lblpatkr1->setGeometry(QRect(10, 570, 101, 41));
        lblpatkr1->setStyleSheet(QString::fromUtf8("background-color: rgb(222, 221, 218);\n"
"font: 75 20pt \"Ubuntu\";\n"
"font:bold;"));
        lblpatkr1->setAlignment(Qt::AlignCenter);
        lblpatkr = new QLabel(addPatient);
        lblpatkr->setObjectName(QString::fromUtf8("lblpatkr"));
        lblpatkr->setGeometry(QRect(470, 570, 101, 41));
        lblpatkr->setStyleSheet(QString::fromUtf8("background-color: rgb(222, 221, 218);\n"
"font: 75 20pt \"Ubuntu\";\n"
"font:bold;"));
        lblpatkr->setAlignment(Qt::AlignCenter);
        linepatkr = new QLineEdit(addPatient);
        linepatkr->setObjectName(QString::fromUtf8("linepatkr"));
        linepatkr->setGeometry(QRect(570, 570, 121, 41));
        linepatkr2 = new QLineEdit(addPatient);
        linepatkr2->setObjectName(QString::fromUtf8("linepatkr2"));
        linepatkr2->setGeometry(QRect(340, 570, 121, 41));
        linepatkr1 = new QLineEdit(addPatient);
        linepatkr1->setObjectName(QString::fromUtf8("linepatkr1"));
        linepatkr1->setGeometry(QRect(110, 570, 121, 41));
        ButPatSave = new QPushButton(addPatient);
        ButPatSave->setObjectName(QString::fromUtf8("ButPatSave"));
        ButPatSave->setGeometry(QRect(140, 630, 141, 51));
        ButPatBack = new QPushButton(addPatient);
        ButPatBack->setObjectName(QString::fromUtf8("ButPatBack"));
        ButPatBack->setGeometry(QRect(380, 630, 141, 51));

        retranslateUi(addPatient);

        QMetaObject::connectSlotsByName(addPatient);
    } // setupUi

    void retranslateUi(QDialog *addPatient)
    {
        addPatient->setWindowTitle(QCoreApplication::translate("addPatient", "Dialog", nullptr));
        label->setText(QString());
        lblpatid->setText(QCoreApplication::translate("addPatient", "ID", nullptr));
        lblpatname->setText(QCoreApplication::translate("addPatient", "Name", nullptr));
        linepatname->setText(QString());
        lblpatdetails->setText(QCoreApplication::translate("addPatient", "Patient Details", nullptr));
        lblpatage->setText(QCoreApplication::translate("addPatient", "Age", nullptr));
        linepatage->setText(QString());
        lblpatphone->setText(QCoreApplication::translate("addPatient", "Phone", nullptr));
        linepatphone->setText(QString());
        lblpatgender->setText(QCoreApplication::translate("addPatient", "Gender", nullptr));
        CheckMale->setText(QCoreApplication::translate("addPatient", "Male", nullptr));
        CheckFemale->setText(QCoreApplication::translate("addPatient", "Female", nullptr));
        CheckOther->setText(QCoreApplication::translate("addPatient", "Other", nullptr));
        CheckImmersion->setText(QCoreApplication::translate("addPatient", "Immersion", nullptr));
        CheckContact->setText(QCoreApplication::translate("addPatient", "Contact", nullptr));
        lblpatopmode->setText(QCoreApplication::translate("addPatient", "Operating Mode", nullptr));
        CheckPhakic->setText(QCoreApplication::translate("addPatient", "Phakic", nullptr));
        lblpatopmethod->setText(QCoreApplication::translate("addPatient", "Operating Method", nullptr));
        CheckApakic->setText(QCoreApplication::translate("addPatient", "Aphakic", nullptr));
        CheckDense->setText(QCoreApplication::translate("addPatient", "Dense", nullptr));
        CheckRight->setText(QCoreApplication::translate("addPatient", "Right", nullptr));
        lblpatopeye->setText(QCoreApplication::translate("addPatient", "Operating Eye", nullptr));
        CheckLeft->setText(QCoreApplication::translate("addPatient", "Left", nullptr));
        lblpatkleft->setText(QCoreApplication::translate("addPatient", "KeratoMeter - LEFT", nullptr));
        lblpatkl1->setText(QCoreApplication::translate("addPatient", "KL1", nullptr));
        lblpatkl2->setText(QCoreApplication::translate("addPatient", "KL2", nullptr));
        lblpatkl->setText(QCoreApplication::translate("addPatient", "KL", nullptr));
        lblpatkr2->setText(QCoreApplication::translate("addPatient", "KR2", nullptr));
        lblpatkright->setText(QCoreApplication::translate("addPatient", "KeratoMeter - RIGHT", nullptr));
        lblpatkr1->setText(QCoreApplication::translate("addPatient", "KR1", nullptr));
        lblpatkr->setText(QCoreApplication::translate("addPatient", "KR", nullptr));
        ButPatSave->setText(QCoreApplication::translate("addPatient", "save", nullptr));
        ButPatBack->setText(QCoreApplication::translate("addPatient", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class addPatient: public Ui_addPatient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDPATIENT_H
