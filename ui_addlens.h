/********************************************************************************
** Form generated from reading UI file 'addlens.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDLENS_H
#define UI_ADDLENS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_AddLens
{
public:
    QLabel *label;
    QLabel *lbllensiol;
    QLabel *lbllensdetails;
    QLineEdit *lineiol;
    QLabel *lbllenstype;
    QComboBox *comboBox;
    QLabel *lbllensasrkt;
    QLineEdit *lineASRKT;
    QLabel *lbllasrkii;
    QLineEdit *lineASRKII;
    QLabel *lbllacd;
    QLineEdit *lineACD;
    QLabel *lbllsf;
    QLineEdit *lineSF;
    QLabel *lblla0;
    QLineEdit *linea0;
    QLabel *lblla1;
    QLineEdit *linea1;
    QLabel *lblla2;
    QLineEdit *linea2;
    QPushButton *ButLensSave;
    QPushButton *ButLensBack;

    void setupUi(QDialog *AddLens)
    {
        if (AddLens->objectName().isEmpty())
            AddLens->setObjectName(QString::fromUtf8("AddLens"));
        AddLens->resize(700, 700);
        AddLens->setMinimumSize(QSize(0, 0));
        label = new QLabel(AddLens);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 700, 700));
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 117, 143);"));
        lbllensiol = new QLabel(AddLens);
        lbllensiol->setObjectName(QString::fromUtf8("lbllensiol"));
        lbllensiol->setGeometry(QRect(100, 70, 181, 41));
        lbllensiol->setStyleSheet(QString::fromUtf8("background-color: rgb(222, 221, 218);\n"
"font: 75 20pt \"Ubuntu\";\n"
"font:bold;"));
        lbllensiol->setAlignment(Qt::AlignCenter);
        lbllensdetails = new QLabel(AddLens);
        lbllensdetails->setObjectName(QString::fromUtf8("lbllensdetails"));
        lbllensdetails->setGeometry(QRect(190, 10, 321, 31));
        lbllensdetails->setStyleSheet(QString::fromUtf8("background-color: rgb(222, 221, 218);\n"
"font: 75 20pt \"Ubuntu\";\n"
"font:bold;"));
        lbllensdetails->setAlignment(Qt::AlignCenter);
        lineiol = new QLineEdit(AddLens);
        lineiol->setObjectName(QString::fromUtf8("lineiol"));
        lineiol->setGeometry(QRect(280, 70, 271, 41));
        lbllenstype = new QLabel(AddLens);
        lbllenstype->setObjectName(QString::fromUtf8("lbllenstype"));
        lbllenstype->setGeometry(QRect(100, 130, 181, 41));
        lbllenstype->setStyleSheet(QString::fromUtf8("background-color: rgb(222, 221, 218);\n"
"font: 75 20pt \"Ubuntu\";\n"
"font:bold;"));
        lbllenstype->setAlignment(Qt::AlignCenter);
        comboBox = new QComboBox(AddLens);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(280, 130, 271, 41));
        comboBox->setStyleSheet(QString::fromUtf8("font: 75 24pt \"Ubuntu\";\n"
"font:bold;"));
        lbllensasrkt = new QLabel(AddLens);
        lbllensasrkt->setObjectName(QString::fromUtf8("lbllensasrkt"));
        lbllensasrkt->setGeometry(QRect(100, 190, 181, 41));
        lbllensasrkt->setStyleSheet(QString::fromUtf8("background-color: rgb(222, 221, 218);\n"
"font: 75 20pt \"Ubuntu\";\n"
"font:bold;"));
        lbllensasrkt->setAlignment(Qt::AlignCenter);
        lineASRKT = new QLineEdit(AddLens);
        lineASRKT->setObjectName(QString::fromUtf8("lineASRKT"));
        lineASRKT->setGeometry(QRect(280, 190, 271, 41));
        lbllasrkii = new QLabel(AddLens);
        lbllasrkii->setObjectName(QString::fromUtf8("lbllasrkii"));
        lbllasrkii->setGeometry(QRect(100, 250, 181, 41));
        lbllasrkii->setStyleSheet(QString::fromUtf8("background-color: rgb(222, 221, 218);\n"
"font: 75 20pt \"Ubuntu\";\n"
"font:bold;"));
        lbllasrkii->setAlignment(Qt::AlignCenter);
        lineASRKII = new QLineEdit(AddLens);
        lineASRKII->setObjectName(QString::fromUtf8("lineASRKII"));
        lineASRKII->setGeometry(QRect(280, 250, 271, 41));
        lbllacd = new QLabel(AddLens);
        lbllacd->setObjectName(QString::fromUtf8("lbllacd"));
        lbllacd->setGeometry(QRect(100, 310, 181, 41));
        lbllacd->setStyleSheet(QString::fromUtf8("background-color: rgb(222, 221, 218);\n"
"font: 75 20pt \"Ubuntu\";\n"
"font:bold;"));
        lbllacd->setAlignment(Qt::AlignCenter);
        lineACD = new QLineEdit(AddLens);
        lineACD->setObjectName(QString::fromUtf8("lineACD"));
        lineACD->setGeometry(QRect(280, 310, 271, 41));
        lbllsf = new QLabel(AddLens);
        lbllsf->setObjectName(QString::fromUtf8("lbllsf"));
        lbllsf->setGeometry(QRect(100, 370, 181, 41));
        lbllsf->setStyleSheet(QString::fromUtf8("background-color: rgb(222, 221, 218);\n"
"font: 75 20pt \"Ubuntu\";\n"
"font:bold;"));
        lbllsf->setAlignment(Qt::AlignCenter);
        lineSF = new QLineEdit(AddLens);
        lineSF->setObjectName(QString::fromUtf8("lineSF"));
        lineSF->setGeometry(QRect(280, 370, 271, 41));
        lblla0 = new QLabel(AddLens);
        lblla0->setObjectName(QString::fromUtf8("lblla0"));
        lblla0->setGeometry(QRect(100, 430, 181, 41));
        lblla0->setStyleSheet(QString::fromUtf8("background-color: rgb(222, 221, 218);\n"
"font: 75 20pt \"Ubuntu\";\n"
"font:bold;"));
        lblla0->setAlignment(Qt::AlignCenter);
        linea0 = new QLineEdit(AddLens);
        linea0->setObjectName(QString::fromUtf8("linea0"));
        linea0->setGeometry(QRect(280, 430, 271, 41));
        lblla1 = new QLabel(AddLens);
        lblla1->setObjectName(QString::fromUtf8("lblla1"));
        lblla1->setGeometry(QRect(100, 490, 181, 41));
        lblla1->setStyleSheet(QString::fromUtf8("background-color: rgb(222, 221, 218);\n"
"font: 75 20pt \"Ubuntu\";\n"
"font:bold;"));
        lblla1->setAlignment(Qt::AlignCenter);
        linea1 = new QLineEdit(AddLens);
        linea1->setObjectName(QString::fromUtf8("linea1"));
        linea1->setGeometry(QRect(280, 490, 271, 41));
        lblla2 = new QLabel(AddLens);
        lblla2->setObjectName(QString::fromUtf8("lblla2"));
        lblla2->setGeometry(QRect(100, 550, 181, 41));
        lblla2->setStyleSheet(QString::fromUtf8("background-color: rgb(222, 221, 218);\n"
"font: 75 20pt \"Ubuntu\";\n"
"font:bold;"));
        lblla2->setAlignment(Qt::AlignCenter);
        linea2 = new QLineEdit(AddLens);
        linea2->setObjectName(QString::fromUtf8("linea2"));
        linea2->setGeometry(QRect(280, 550, 271, 41));
        ButLensSave = new QPushButton(AddLens);
        ButLensSave->setObjectName(QString::fromUtf8("ButLensSave"));
        ButLensSave->setGeometry(QRect(100, 610, 181, 71));
        ButLensBack = new QPushButton(AddLens);
        ButLensBack->setObjectName(QString::fromUtf8("ButLensBack"));
        ButLensBack->setGeometry(QRect(360, 610, 181, 71));

        retranslateUi(AddLens);

        QMetaObject::connectSlotsByName(AddLens);
    } // setupUi

    void retranslateUi(QDialog *AddLens)
    {
        AddLens->setWindowTitle(QCoreApplication::translate("AddLens", "Dialog", nullptr));
        label->setText(QString());
        lbllensiol->setText(QCoreApplication::translate("AddLens", "Lens IOL", nullptr));
        lbllensdetails->setText(QCoreApplication::translate("AddLens", "Lens Details", nullptr));
        lbllenstype->setText(QCoreApplication::translate("AddLens", "Type", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("AddLens", "Anterior", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("AddLens", "Posterior", nullptr));

        lbllensasrkt->setText(QCoreApplication::translate("AddLens", "ASRKT", nullptr));
        lbllasrkii->setText(QCoreApplication::translate("AddLens", "ASRKII", nullptr));
        lbllacd->setText(QCoreApplication::translate("AddLens", "ACD", nullptr));
        lbllsf->setText(QCoreApplication::translate("AddLens", "SF", nullptr));
        lblla0->setText(QCoreApplication::translate("AddLens", "a0", nullptr));
        lblla1->setText(QCoreApplication::translate("AddLens", "a1", nullptr));
        lblla2->setText(QCoreApplication::translate("AddLens", "a2", nullptr));
        linea2->setText(QString());
        ButLensSave->setText(QCoreApplication::translate("AddLens", "SAVE", nullptr));
        ButLensBack->setText(QCoreApplication::translate("AddLens", "BACK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddLens: public Ui_AddLens {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDLENS_H
