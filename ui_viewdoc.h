/********************************************************************************
** Form generated from reading UI file 'viewdoc.ui'
**
** Created by: Qt User Interface Compiler version 5.15.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEWDOC_H
#define UI_VIEWDOC_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_viewdoc
{
public:
    QLabel *label;
    QLabel *lbllenspre1;
    QLineEdit *linedocid;
    QLabel *lbllenspre2;
    QLabel *lbllenspre3;
    QLabel *lbllensformula;
    QLabel *lblpatid;
    QLineEdit *linedocname;
    QLabel *lblpatname;
    QLineEdit *linedocpre1;
    QLineEdit *linedocpre2;
    QLineEdit *linedocpre3;
    QLineEdit *linedocformula;
    QLabel *lblpatname_2;
    QPushButton *BUTOK;

    void setupUi(QDialog *viewdoc)
    {
        if (viewdoc->objectName().isEmpty())
            viewdoc->setObjectName(QString::fromUtf8("viewdoc"));
        viewdoc->resize(700, 700);
        label = new QLabel(viewdoc);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 700, 700));
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 117, 143);"));
        lbllenspre1 = new QLabel(viewdoc);
        lbllenspre1->setObjectName(QString::fromUtf8("lbllenspre1"));
        lbllenspre1->setGeometry(QRect(120, 260, 221, 41));
        lbllenspre1->setStyleSheet(QString::fromUtf8("background-color: rgb(222, 221, 218);\n"
"font: 75 20pt \"Ubuntu\";\n"
"font:bold;"));
        lbllenspre1->setAlignment(Qt::AlignCenter);
        linedocid = new QLineEdit(viewdoc);
        linedocid->setObjectName(QString::fromUtf8("linedocid"));
        linedocid->setGeometry(QRect(220, 120, 121, 41));
        lbllenspre2 = new QLabel(viewdoc);
        lbllenspre2->setObjectName(QString::fromUtf8("lbllenspre2"));
        lbllenspre2->setGeometry(QRect(120, 340, 221, 41));
        lbllenspre2->setStyleSheet(QString::fromUtf8("background-color: rgb(222, 221, 218);\n"
"font: 75 20pt \"Ubuntu\";\n"
"font:bold;"));
        lbllenspre2->setAlignment(Qt::AlignCenter);
        lbllenspre3 = new QLabel(viewdoc);
        lbllenspre3->setObjectName(QString::fromUtf8("lbllenspre3"));
        lbllenspre3->setGeometry(QRect(120, 420, 241, 41));
        lbllenspre3->setStyleSheet(QString::fromUtf8("background-color: rgb(222, 221, 218);\n"
"font: 75 20pt \"Ubuntu\";\n"
"font:bold;"));
        lbllenspre3->setAlignment(Qt::AlignCenter);
        lbllensformula = new QLabel(viewdoc);
        lbllensformula->setObjectName(QString::fromUtf8("lbllensformula"));
        lbllensformula->setGeometry(QRect(120, 500, 221, 41));
        lbllensformula->setStyleSheet(QString::fromUtf8("background-color: rgb(222, 221, 218);\n"
"font: 75 20pt \"Ubuntu\";\n"
"font:bold;"));
        lbllensformula->setAlignment(Qt::AlignCenter);
        lblpatid = new QLabel(viewdoc);
        lblpatid->setObjectName(QString::fromUtf8("lblpatid"));
        lblpatid->setGeometry(QRect(120, 120, 101, 41));
        lblpatid->setStyleSheet(QString::fromUtf8("background-color: rgb(222, 221, 218);\n"
"font: 75 20pt \"Ubuntu\";\n"
"font:bold;"));
        lblpatid->setAlignment(Qt::AlignCenter);
        linedocname = new QLineEdit(viewdoc);
        linedocname->setObjectName(QString::fromUtf8("linedocname"));
        linedocname->setGeometry(QRect(230, 190, 251, 41));
        lblpatname = new QLabel(viewdoc);
        lblpatname->setObjectName(QString::fromUtf8("lblpatname"));
        lblpatname->setGeometry(QRect(120, 190, 111, 41));
        lblpatname->setStyleSheet(QString::fromUtf8("background-color: rgb(222, 221, 218);\n"
"font: 75 20pt \"Ubuntu\";\n"
"font:bold;"));
        lblpatname->setAlignment(Qt::AlignCenter);
        linedocpre1 = new QLineEdit(viewdoc);
        linedocpre1->setObjectName(QString::fromUtf8("linedocpre1"));
        linedocpre1->setGeometry(QRect(340, 260, 271, 41));
        linedocpre2 = new QLineEdit(viewdoc);
        linedocpre2->setObjectName(QString::fromUtf8("linedocpre2"));
        linedocpre2->setGeometry(QRect(340, 340, 271, 41));
        linedocpre3 = new QLineEdit(viewdoc);
        linedocpre3->setObjectName(QString::fromUtf8("linedocpre3"));
        linedocpre3->setGeometry(QRect(360, 420, 251, 41));
        linedocformula = new QLineEdit(viewdoc);
        linedocformula->setObjectName(QString::fromUtf8("linedocformula"));
        linedocformula->setGeometry(QRect(340, 500, 271, 41));
        lblpatname_2 = new QLabel(viewdoc);
        lblpatname_2->setObjectName(QString::fromUtf8("lblpatname_2"));
        lblpatname_2->setGeometry(QRect(190, 30, 291, 41));
        lblpatname_2->setStyleSheet(QString::fromUtf8("background-color: rgb(222, 221, 218);\n"
"font: 75 20pt \"Ubuntu\";\n"
"font:bold;"));
        lblpatname_2->setAlignment(Qt::AlignCenter);
        BUTOK = new QPushButton(viewdoc);
        BUTOK->setObjectName(QString::fromUtf8("BUTOK"));
        BUTOK->setGeometry(QRect(270, 600, 201, 61));

        retranslateUi(viewdoc);

        QMetaObject::connectSlotsByName(viewdoc);
    } // setupUi

    void retranslateUi(QDialog *viewdoc)
    {
        viewdoc->setWindowTitle(QCoreApplication::translate("viewdoc", "Dialog", nullptr));
        label->setText(QString());
        lbllenspre1->setText(QCoreApplication::translate("viewdoc", "Lens Preset One", nullptr));
        lbllenspre2->setText(QCoreApplication::translate("viewdoc", "Lens Preset Two", nullptr));
        lbllenspre3->setText(QCoreApplication::translate("viewdoc", "Lens Preset Three", nullptr));
        lbllensformula->setText(QCoreApplication::translate("viewdoc", "Primary Formula", nullptr));
        lblpatid->setText(QCoreApplication::translate("viewdoc", "ID", nullptr));
        linedocname->setText(QString());
        lblpatname->setText(QCoreApplication::translate("viewdoc", "Name", nullptr));
        linedocpre1->setText(QString());
        linedocpre2->setText(QString());
        linedocpre3->setText(QString());
        linedocformula->setText(QString());
        lblpatname_2->setText(QCoreApplication::translate("viewdoc", "View Doctor", nullptr));
        BUTOK->setText(QCoreApplication::translate("viewdoc", "ok", nullptr));
    } // retranslateUi

};

namespace Ui {
    class viewdoc: public Ui_viewdoc {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEWDOC_H
