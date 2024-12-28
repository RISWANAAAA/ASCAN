/********************************************************************************
** Form generated from reading UI file 'adddoctor.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDDOCTOR_H
#define UI_ADDDOCTOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_AddDoctor
{
public:
    QLabel *label;
    QLabel *lblpatid;
    QLabel *lblpatname;
    QLineEdit *linedocname;
    QLineEdit *linedocid;
    QLabel *lbldocdetails;
    QLabel *lbllenspre1;
    QComboBox *comboBox;
    QComboBox *comboBox_2;
    QLabel *lbllenspre2;
    QComboBox *comboBox_3;
    QLabel *lbllenspre3;
    QComboBox *comboBox_4;
    QLabel *lbllensformula;
    QPushButton *ButDocSave;
    QPushButton *ButDocBack;

    void setupUi(QDialog *AddDoctor)
    {
        if (AddDoctor->objectName().isEmpty())
            AddDoctor->setObjectName(QString::fromUtf8("AddDoctor"));
        AddDoctor->resize(700, 700);
        label = new QLabel(AddDoctor);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 700, 700));
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 117, 143);"));
        lblpatid = new QLabel(AddDoctor);
        lblpatid->setObjectName(QString::fromUtf8("lblpatid"));
        lblpatid->setGeometry(QRect(120, 90, 101, 41));
        lblpatid->setStyleSheet(QString::fromUtf8("background-color: rgb(222, 221, 218);\n"
"font: 75 20pt \"Ubuntu\";\n"
"font:bold;"));
        lblpatid->setAlignment(Qt::AlignCenter);
        lblpatname = new QLabel(AddDoctor);
        lblpatname->setObjectName(QString::fromUtf8("lblpatname"));
        lblpatname->setGeometry(QRect(120, 150, 111, 41));
        lblpatname->setStyleSheet(QString::fromUtf8("background-color: rgb(222, 221, 218);\n"
"font: 75 20pt \"Ubuntu\";\n"
"font:bold;"));
        lblpatname->setAlignment(Qt::AlignCenter);
        linedocname = new QLineEdit(AddDoctor);
        linedocname->setObjectName(QString::fromUtf8("linedocname"));
        linedocname->setGeometry(QRect(230, 150, 251, 41));
        linedocid = new QLineEdit(AddDoctor);
        linedocid->setObjectName(QString::fromUtf8("linedocid"));
        linedocid->setGeometry(QRect(220, 90, 121, 41));
        lbldocdetails = new QLabel(AddDoctor);
        lbldocdetails->setObjectName(QString::fromUtf8("lbldocdetails"));
        lbldocdetails->setGeometry(QRect(190, 10, 321, 31));
        lbldocdetails->setStyleSheet(QString::fromUtf8("background-color: rgb(222, 221, 218);\n"
"font: 75 20pt \"Ubuntu\";\n"
"font:bold;"));
        lbldocdetails->setAlignment(Qt::AlignCenter);
        lbllenspre1 = new QLabel(AddDoctor);
        lbllenspre1->setObjectName(QString::fromUtf8("lbllenspre1"));
        lbllenspre1->setGeometry(QRect(120, 220, 221, 41));
        lbllenspre1->setStyleSheet(QString::fromUtf8("background-color: rgb(222, 221, 218);\n"
"font: 75 20pt \"Ubuntu\";\n"
"font:bold;"));
        lbllenspre1->setAlignment(Qt::AlignCenter);
        comboBox = new QComboBox(AddDoctor);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(340, 220, 291, 41));
        comboBox_2 = new QComboBox(AddDoctor);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setGeometry(QRect(340, 290, 291, 41));
        lbllenspre2 = new QLabel(AddDoctor);
        lbllenspre2->setObjectName(QString::fromUtf8("lbllenspre2"));
        lbllenspre2->setGeometry(QRect(120, 290, 221, 41));
        lbllenspre2->setStyleSheet(QString::fromUtf8("background-color: rgb(222, 221, 218);\n"
"font: 75 20pt \"Ubuntu\";\n"
"font:bold;"));
        lbllenspre2->setAlignment(Qt::AlignCenter);
        comboBox_3 = new QComboBox(AddDoctor);
        comboBox_3->setObjectName(QString::fromUtf8("comboBox_3"));
        comboBox_3->setGeometry(QRect(360, 380, 271, 41));
        lbllenspre3 = new QLabel(AddDoctor);
        lbllenspre3->setObjectName(QString::fromUtf8("lbllenspre3"));
        lbllenspre3->setGeometry(QRect(120, 380, 241, 41));
        lbllenspre3->setStyleSheet(QString::fromUtf8("background-color: rgb(222, 221, 218);\n"
"font: 75 20pt \"Ubuntu\";\n"
"font:bold;"));
        lbllenspre3->setAlignment(Qt::AlignCenter);
        comboBox_4 = new QComboBox(AddDoctor);
        comboBox_4->setObjectName(QString::fromUtf8("comboBox_4"));
        comboBox_4->setGeometry(QRect(340, 460, 291, 41));
        lbllensformula = new QLabel(AddDoctor);
        lbllensformula->setObjectName(QString::fromUtf8("lbllensformula"));
        lbllensformula->setGeometry(QRect(120, 460, 221, 41));
        lbllensformula->setStyleSheet(QString::fromUtf8("background-color: rgb(222, 221, 218);\n"
"font: 75 20pt \"Ubuntu\";\n"
"font:bold;"));
        lbllensformula->setAlignment(Qt::AlignCenter);
        ButDocSave = new QPushButton(AddDoctor);
        ButDocSave->setObjectName(QString::fromUtf8("ButDocSave"));
        ButDocSave->setGeometry(QRect(110, 560, 181, 111));
        ButDocBack = new QPushButton(AddDoctor);
        ButDocBack->setObjectName(QString::fromUtf8("ButDocBack"));
        ButDocBack->setGeometry(QRect(390, 560, 181, 111));

        retranslateUi(AddDoctor);

        QMetaObject::connectSlotsByName(AddDoctor);
    } // setupUi

    void retranslateUi(QDialog *AddDoctor)
    {
        AddDoctor->setWindowTitle(QCoreApplication::translate("AddDoctor", "Dialog", nullptr));
        label->setText(QString());
        lblpatid->setText(QCoreApplication::translate("AddDoctor", "ID", nullptr));
        lblpatname->setText(QCoreApplication::translate("AddDoctor", "Name", nullptr));
        linedocname->setText(QString());
        lbldocdetails->setText(QCoreApplication::translate("AddDoctor", "Doctor Details", nullptr));
        lbllenspre1->setText(QCoreApplication::translate("AddDoctor", "Lens Preset One", nullptr));
        lbllenspre2->setText(QCoreApplication::translate("AddDoctor", "Lens Preset Two", nullptr));
        lbllenspre3->setText(QCoreApplication::translate("AddDoctor", "Lens Preset Three", nullptr));
        lbllensformula->setText(QCoreApplication::translate("AddDoctor", "Primary Formula", nullptr));
        ButDocSave->setText(QCoreApplication::translate("AddDoctor", "SAVE", nullptr));
        ButDocBack->setText(QCoreApplication::translate("AddDoctor", "BACK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddDoctor: public Ui_AddDoctor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDDOCTOR_H
