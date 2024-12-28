/********************************************************************************
** Form generated from reading UI file 'viewpatient.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEWPATIENT_H
#define UI_VIEWPATIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_viewpatient
{
public:
    QLabel *label;
    QLineEdit *linepatid;
    QLabel *lblpatgender;
    QLabel *lblpatopmethod;
    QLabel *lblpatopmode;
    QLabel *lblpatid;
    QLabel *lblpatopeye;
    QLabel *lblpatphone;
    QLabel *lblpatname;
    QLabel *lblpatage;
    QLabel *lblpatopmethod_2;
    QLineEdit *linepatname;
    QLineEdit *linepatage;
    QLineEdit *linepatphone;
    QLineEdit *linepatgender;
    QLineEdit *linepatopmethod;
    QLineEdit *linepatopmode;
    QLineEdit *linepatopeye;
    QPushButton *ButOk;

    void setupUi(QDialog *viewpatient)
    {
        if (viewpatient->objectName().isEmpty())
            viewpatient->setObjectName(QString::fromUtf8("viewpatient"));
        viewpatient->resize(700, 700);
        label = new QLabel(viewpatient);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 700, 700));
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 117, 143);"));
        linepatid = new QLineEdit(viewpatient);
        linepatid->setObjectName(QString::fromUtf8("linepatid"));
        linepatid->setGeometry(QRect(240, 90, 121, 41));
        lblpatgender = new QLabel(viewpatient);
        lblpatgender->setObjectName(QString::fromUtf8("lblpatgender"));
        lblpatgender->setGeometry(QRect(140, 330, 131, 41));
        lblpatgender->setStyleSheet(QString::fromUtf8("background-color: rgb(222, 221, 218);\n"
"font: 75 20pt \"Ubuntu\";\n"
"font:bold;"));
        lblpatgender->setAlignment(Qt::AlignCenter);
        lblpatopmethod = new QLabel(viewpatient);
        lblpatopmethod->setObjectName(QString::fromUtf8("lblpatopmethod"));
        lblpatopmethod->setGeometry(QRect(140, 390, 271, 41));
        lblpatopmethod->setStyleSheet(QString::fromUtf8("background-color: rgb(222, 221, 218);\n"
"font: 75 20pt \"Ubuntu\";\n"
"font:bold;"));
        lblpatopmethod->setAlignment(Qt::AlignCenter);
        lblpatopmode = new QLabel(viewpatient);
        lblpatopmode->setObjectName(QString::fromUtf8("lblpatopmode"));
        lblpatopmode->setGeometry(QRect(140, 450, 271, 41));
        lblpatopmode->setStyleSheet(QString::fromUtf8("background-color: rgb(222, 221, 218);\n"
"font: 75 20pt \"Ubuntu\";\n"
"font:bold;"));
        lblpatopmode->setAlignment(Qt::AlignCenter);
        lblpatid = new QLabel(viewpatient);
        lblpatid->setObjectName(QString::fromUtf8("lblpatid"));
        lblpatid->setGeometry(QRect(140, 90, 101, 41));
        lblpatid->setStyleSheet(QString::fromUtf8("background-color: rgb(222, 221, 218);\n"
"font: 75 20pt \"Ubuntu\";\n"
"font:bold;"));
        lblpatid->setAlignment(Qt::AlignCenter);
        lblpatopeye = new QLabel(viewpatient);
        lblpatopeye->setObjectName(QString::fromUtf8("lblpatopeye"));
        lblpatopeye->setGeometry(QRect(140, 510, 271, 41));
        lblpatopeye->setStyleSheet(QString::fromUtf8("background-color: rgb(222, 221, 218);\n"
"font: 75 20pt \"Ubuntu\";\n"
"font:bold;"));
        lblpatopeye->setAlignment(Qt::AlignCenter);
        lblpatphone = new QLabel(viewpatient);
        lblpatphone->setObjectName(QString::fromUtf8("lblpatphone"));
        lblpatphone->setGeometry(QRect(140, 270, 131, 41));
        lblpatphone->setStyleSheet(QString::fromUtf8("background-color: rgb(222, 221, 218);\n"
"font: 75 20pt \"Ubuntu\";\n"
"font:bold;"));
        lblpatphone->setAlignment(Qt::AlignCenter);
        lblpatname = new QLabel(viewpatient);
        lblpatname->setObjectName(QString::fromUtf8("lblpatname"));
        lblpatname->setGeometry(QRect(140, 150, 111, 41));
        lblpatname->setStyleSheet(QString::fromUtf8("background-color: rgb(222, 221, 218);\n"
"font: 75 20pt \"Ubuntu\";\n"
"font:bold;"));
        lblpatname->setAlignment(Qt::AlignCenter);
        lblpatage = new QLabel(viewpatient);
        lblpatage->setObjectName(QString::fromUtf8("lblpatage"));
        lblpatage->setGeometry(QRect(140, 210, 111, 41));
        lblpatage->setStyleSheet(QString::fromUtf8("background-color: rgb(222, 221, 218);\n"
"font: 75 20pt \"Ubuntu\";\n"
"font:bold;"));
        lblpatage->setAlignment(Qt::AlignCenter);
        lblpatopmethod_2 = new QLabel(viewpatient);
        lblpatopmethod_2->setObjectName(QString::fromUtf8("lblpatopmethod_2"));
        lblpatopmethod_2->setGeometry(QRect(200, 10, 271, 41));
        lblpatopmethod_2->setStyleSheet(QString::fromUtf8("background-color: rgb(222, 221, 218);\n"
"font: 75 20pt \"Ubuntu\";\n"
"font:bold;"));
        lblpatopmethod_2->setAlignment(Qt::AlignCenter);
        linepatname = new QLineEdit(viewpatient);
        linepatname->setObjectName(QString::fromUtf8("linepatname"));
        linepatname->setGeometry(QRect(250, 150, 221, 41));
        linepatage = new QLineEdit(viewpatient);
        linepatage->setObjectName(QString::fromUtf8("linepatage"));
        linepatage->setGeometry(QRect(250, 210, 221, 41));
        linepatphone = new QLineEdit(viewpatient);
        linepatphone->setObjectName(QString::fromUtf8("linepatphone"));
        linepatphone->setGeometry(QRect(270, 270, 221, 41));
        linepatgender = new QLineEdit(viewpatient);
        linepatgender->setObjectName(QString::fromUtf8("linepatgender"));
        linepatgender->setGeometry(QRect(270, 330, 221, 41));
        linepatopmethod = new QLineEdit(viewpatient);
        linepatopmethod->setObjectName(QString::fromUtf8("linepatopmethod"));
        linepatopmethod->setGeometry(QRect(410, 390, 221, 41));
        linepatopmode = new QLineEdit(viewpatient);
        linepatopmode->setObjectName(QString::fromUtf8("linepatopmode"));
        linepatopmode->setGeometry(QRect(410, 450, 221, 41));
        linepatopeye = new QLineEdit(viewpatient);
        linepatopeye->setObjectName(QString::fromUtf8("linepatopeye"));
        linepatopeye->setGeometry(QRect(410, 510, 221, 41));
        ButOk = new QPushButton(viewpatient);
        ButOk->setObjectName(QString::fromUtf8("ButOk"));
        ButOk->setGeometry(QRect(290, 590, 201, 81));

        retranslateUi(viewpatient);

        QMetaObject::connectSlotsByName(viewpatient);
    } // setupUi

    void retranslateUi(QDialog *viewpatient)
    {
        viewpatient->setWindowTitle(QCoreApplication::translate("viewpatient", "Dialog", nullptr));
        label->setText(QString());
        lblpatgender->setText(QCoreApplication::translate("viewpatient", "Gender", nullptr));
        lblpatopmethod->setText(QCoreApplication::translate("viewpatient", "Operating Method", nullptr));
        lblpatopmode->setText(QCoreApplication::translate("viewpatient", "Operating Mode", nullptr));
        lblpatid->setText(QCoreApplication::translate("viewpatient", "ID", nullptr));
        lblpatopeye->setText(QCoreApplication::translate("viewpatient", "Operating Eye", nullptr));
        lblpatphone->setText(QCoreApplication::translate("viewpatient", "Phone", nullptr));
        lblpatname->setText(QCoreApplication::translate("viewpatient", "Name", nullptr));
        lblpatage->setText(QCoreApplication::translate("viewpatient", "Age", nullptr));
        lblpatopmethod_2->setText(QCoreApplication::translate("viewpatient", "View Patient", nullptr));
        ButOk->setText(QCoreApplication::translate("viewpatient", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class viewpatient: public Ui_viewpatient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEWPATIENT_H
