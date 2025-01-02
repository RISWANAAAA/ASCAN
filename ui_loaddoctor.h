/********************************************************************************
** Form generated from reading UI file 'loaddoctor.ui'
**
** Created by: Qt User Interface Compiler version 5.15.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOADDOCTOR_H
#define UI_LOADDOCTOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_loaddoctor
{
public:
    QTabWidget *tabWidget;
    QWidget *tab;
    QTableView *tableView;
    QPushButton *ButDocAdd;
    QPushButton *ButDocDelete;
    QPushButton *ButDocTouch;
    QPushButton *ButDocLoad;
    QWidget *tab_2;
    QTableView *tableView_2;
    QPushButton *ButPatAdd;
    QPushButton *ButPatTouch;
    QPushButton *ButPatDelete;
    QPushButton *ButPatLoad;

    void setupUi(QDialog *loaddoctor)
    {
        if (loaddoctor->objectName().isEmpty())
            loaddoctor->setObjectName(QString::fromUtf8("loaddoctor"));
        loaddoctor->resize(700, 700);
        loaddoctor->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 117, 143);"));
        tabWidget = new QTabWidget(loaddoctor);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(0, -30, 711, 741));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        tableView = new QTableView(tab);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(0, 0, 701, 701));
        ButDocAdd = new QPushButton(tab);
        ButDocAdd->setObjectName(QString::fromUtf8("ButDocAdd"));
        ButDocAdd->setGeometry(QRect(530, 420, 81, 71));
        ButDocAdd->setStyleSheet(QString::fromUtf8("border:none;\n"
"image: url(:/image/adddoctor.png);\n"
"background-color:transparent;"));
        ButDocDelete = new QPushButton(tab);
        ButDocDelete->setObjectName(QString::fromUtf8("ButDocDelete"));
        ButDocDelete->setGeometry(QRect(520, 570, 91, 71));
        ButDocDelete->setStyleSheet(QString::fromUtf8("border:none;\n"
"image: url(:/image/delete.png);\n"
"background-color:transparent;"));
        ButDocTouch = new QPushButton(tab);
        ButDocTouch->setObjectName(QString::fromUtf8("ButDocTouch"));
        ButDocTouch->setGeometry(QRect(620, 500, 81, 71));
        ButDocTouch->setStyleSheet(QString::fromUtf8("image: url(:/image/assesstive.png);\n"
"background-color:transparent;\n"
"border:none;"));
        ButDocLoad = new QPushButton(tab);
        ButDocLoad->setObjectName(QString::fromUtf8("ButDocLoad"));
        ButDocLoad->setGeometry(QRect(260, 630, 121, 61));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tableView_2 = new QTableView(tab_2);
        tableView_2->setObjectName(QString::fromUtf8("tableView_2"));
        tableView_2->setGeometry(QRect(40, 0, 591, 701));
        ButPatAdd = new QPushButton(tab_2);
        ButPatAdd->setObjectName(QString::fromUtf8("ButPatAdd"));
        ButPatAdd->setGeometry(QRect(500, 450, 81, 71));
        ButPatAdd->setStyleSheet(QString::fromUtf8("border:none;\n"
"image: url(:/image/addperson.png);\n"
"background-color:transparent;"));
        ButPatTouch = new QPushButton(tab_2);
        ButPatTouch->setObjectName(QString::fromUtf8("ButPatTouch"));
        ButPatTouch->setGeometry(QRect(590, 530, 81, 71));
        ButPatTouch->setStyleSheet(QString::fromUtf8("image: url(:/image/assesstive.png);\n"
"background-color:transparent;\n"
"border:none;"));
        ButPatDelete = new QPushButton(tab_2);
        ButPatDelete->setObjectName(QString::fromUtf8("ButPatDelete"));
        ButPatDelete->setGeometry(QRect(490, 600, 91, 71));
        ButPatDelete->setStyleSheet(QString::fromUtf8("border:none;\n"
"image: url(:/image/delete.png);\n"
"background-color:transparent;"));
        ButPatLoad = new QPushButton(tab_2);
        ButPatLoad->setObjectName(QString::fromUtf8("ButPatLoad"));
        ButPatLoad->setGeometry(QRect(230, 610, 121, 61));
        tabWidget->addTab(tab_2, QString());

        retranslateUi(loaddoctor);

        QMetaObject::connectSlotsByName(loaddoctor);
    } // setupUi

    void retranslateUi(QDialog *loaddoctor)
    {
        loaddoctor->setWindowTitle(QCoreApplication::translate("loaddoctor", "Dialog", nullptr));
        ButDocAdd->setText(QString());
        ButDocDelete->setText(QString());
        ButDocTouch->setText(QString());
        ButDocLoad->setText(QCoreApplication::translate("loaddoctor", "Load", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("loaddoctor", "Tab 1", nullptr));
        ButPatAdd->setText(QString());
        ButPatTouch->setText(QString());
        ButPatDelete->setText(QString());
        ButPatLoad->setText(QCoreApplication::translate("loaddoctor", "Load", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("loaddoctor", "Tab 2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class loaddoctor: public Ui_loaddoctor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOADDOCTOR_H
