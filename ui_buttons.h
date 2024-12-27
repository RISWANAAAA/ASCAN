/********************************************************************************
** Form generated from reading UI file 'buttons.ui'
**
** Created by: Qt User Interface Compiler version 5.15.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BUTTONS_H
#define UI_BUTTONS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Buttons
{
public:
    QPushButton *ButCalibration;
    QPushButton *ButDoctor;
    QPushButton *ButMeasure;
    QPushButton *ButCurrent;
    QPushButton *ButSettings;
    QPushButton *ButLens;
    QTabWidget *tabWidget;
    QWidget *tab_3;
    QPushButton *ButPatTouch;
    QPushButton *ButPatAdd;
    QPushButton *ButPatDelete;
    QPushButton *ButPatEdit;
    QPushButton *ButPatView;
    QTableView *tableView;
    QWidget *tab_4;
    QTableView *tableView_2;
    QPushButton *ButDocEdit;
    QPushButton *ButDocTouch;
    QPushButton *ButDocView;
    QPushButton *ButDocDelete;
    QPushButton *ButDocAdd;
    QWidget *tab_5;
    QTableView *tableView_3;
    QPushButton *ButLensEdit;
    QPushButton *ButLensTouch;
    QPushButton *ButLensDelete;
    QPushButton *ButLensAdd;
    QWidget *tab_6;
    QLabel *label_4;
    QWidget *tab_7;
    QLabel *label_5;
    QWidget *tab_8;
    QLabel *label_6;
    QWidget *tab;
    QLabel *label_7;
    QPushButton *ButPatient;
    QPushButton *ButCalculator;

    void setupUi(QWidget *Buttons)
    {
        if (Buttons->objectName().isEmpty())
            Buttons->setObjectName(QString::fromUtf8("Buttons"));
        Buttons->resize(1280, 720);
        Buttons->setStyleSheet(QString::fromUtf8("background-color: rgb(29,63,67);"));
        ButCalibration = new QPushButton(Buttons);
        ButCalibration->setObjectName(QString::fromUtf8("ButCalibration"));
        ButCalibration->setGeometry(QRect(940, 610, 181, 131));
        ButCalibration->setStyleSheet(QString::fromUtf8("image: url(:/image/CALIBRATIONIMG.png);\n"
"background-color:transparent;\n"
"border:none;"));
        ButDoctor = new QPushButton(Buttons);
        ButDoctor->setObjectName(QString::fromUtf8("ButDoctor"));
        ButDoctor->setGeometry(QRect(180, 610, 181, 131));
        ButDoctor->setStyleSheet(QString::fromUtf8("image: url(:/image/DOCTORIMG.png);\n"
"background-color:transparent;\n"
"border:none;"));
        ButMeasure = new QPushButton(Buttons);
        ButMeasure->setObjectName(QString::fromUtf8("ButMeasure"));
        ButMeasure->setGeometry(QRect(570, 610, 181, 131));
        ButMeasure->setStyleSheet(QString::fromUtf8("image: url(:/image/MEASUREIMG.png);\n"
"background-color:transparent;\n"
"border:none;"));
        ButCurrent = new QPushButton(Buttons);
        ButCurrent->setObjectName(QString::fromUtf8("ButCurrent"));
        ButCurrent->setGeometry(QRect(1240, 10, 41, 61));
        ButCurrent->setStyleSheet(QString::fromUtf8("image: url(:/image/3dot.png);\n"
"background-color:transparent;\n"
"border:none;"));
        ButSettings = new QPushButton(Buttons);
        ButSettings->setObjectName(QString::fromUtf8("ButSettings"));
        ButSettings->setGeometry(QRect(1110, 610, 181, 131));
        ButSettings->setStyleSheet(QString::fromUtf8("image: url(:/image/SETTINGSIMG.png);\n"
"background-color:transparent;\n"
"border:none;"));
        ButLens = new QPushButton(Buttons);
        ButLens->setObjectName(QString::fromUtf8("ButLens"));
        ButLens->setGeometry(QRect(380, 610, 181, 131));
        ButLens->setStyleSheet(QString::fromUtf8("image: url(:/image/LENSIMG.png);\n"
"background-color:transparent;\n"
"border:none;"));
        tabWidget = new QTabWidget(Buttons);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(0, -30, 1291, 661));
        tabWidget->setStyleSheet(QString::fromUtf8(""));
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        tab_3->setStyleSheet(QString::fromUtf8(""));
        ButPatTouch = new QPushButton(tab_3);
        ButPatTouch->setObjectName(QString::fromUtf8("ButPatTouch"));
        ButPatTouch->setGeometry(QRect(1180, 440, 81, 71));
        ButPatTouch->setStyleSheet(QString::fromUtf8("image: url(:/image/assesstive.png);\n"
"background-color:transparent;\n"
"border:none;"));
        ButPatAdd = new QPushButton(tab_3);
        ButPatAdd->setObjectName(QString::fromUtf8("ButPatAdd"));
        ButPatAdd->setGeometry(QRect(1140, 350, 81, 71));
        ButPatAdd->setStyleSheet(QString::fromUtf8("image: url(:/image/adddoctor.png);\n"
"border:none;\n"
"background-color:transparent;"));
        ButPatDelete = new QPushButton(tab_3);
        ButPatDelete->setObjectName(QString::fromUtf8("ButPatDelete"));
        ButPatDelete->setGeometry(QRect(1080, 410, 91, 71));
        ButPatDelete->setStyleSheet(QString::fromUtf8("border:none;\n"
"image: url(:/image/delete.png);\n"
"background-color:transparent;"));
        ButPatEdit = new QPushButton(tab_3);
        ButPatEdit->setObjectName(QString::fromUtf8("ButPatEdit"));
        ButPatEdit->setGeometry(QRect(1090, 490, 91, 71));
        ButPatEdit->setStyleSheet(QString::fromUtf8("border:none;\n"
"background-color:transparent;\n"
"image: url(:/image/edit.png);"));
        ButPatView = new QPushButton(tab_3);
        ButPatView->setObjectName(QString::fromUtf8("ButPatView"));
        ButPatView->setGeometry(QRect(1160, 540, 91, 71));
        ButPatView->setStyleSheet(QString::fromUtf8("border:none;\n"
"background-color:transparent;\n"
"image: url(:/image/viewbut.png);"));
        tableView = new QTableView(tab_3);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(0, 50, 861, 531));
        tableView->setStyleSheet(QString::fromUtf8("background-color: rgb(30, 131, 140);"));
        tabWidget->addTab(tab_3, QString());
        tableView->raise();
        ButPatEdit->raise();
        ButPatTouch->raise();
        ButPatView->raise();
        ButPatDelete->raise();
        ButPatAdd->raise();
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        tableView_2 = new QTableView(tab_4);
        tableView_2->setObjectName(QString::fromUtf8("tableView_2"));
        tableView_2->setGeometry(QRect(40, 150, 531, 431));
        tableView_2->setStyleSheet(QString::fromUtf8("background-color: rgb(30, 131, 140);"));
        ButDocEdit = new QPushButton(tab_4);
        ButDocEdit->setObjectName(QString::fromUtf8("ButDocEdit"));
        ButDocEdit->setGeometry(QRect(1090, 480, 91, 71));
        ButDocEdit->setStyleSheet(QString::fromUtf8("border:none;\n"
"background-color:transparent;\n"
"image: url(:/image/edit.png);"));
        ButDocTouch = new QPushButton(tab_4);
        ButDocTouch->setObjectName(QString::fromUtf8("ButDocTouch"));
        ButDocTouch->setGeometry(QRect(1190, 430, 81, 71));
        ButDocTouch->setStyleSheet(QString::fromUtf8("image: url(:/image/assesstive.png);\n"
"background-color:transparent;\n"
"border:none;"));
        ButDocView = new QPushButton(tab_4);
        ButDocView->setObjectName(QString::fromUtf8("ButDocView"));
        ButDocView->setGeometry(QRect(1180, 540, 91, 71));
        ButDocView->setStyleSheet(QString::fromUtf8("border:none;\n"
"background-color:transparent;\n"
"image: url(:/image/viewbut.png);"));
        ButDocDelete = new QPushButton(tab_4);
        ButDocDelete->setObjectName(QString::fromUtf8("ButDocDelete"));
        ButDocDelete->setGeometry(QRect(1080, 380, 91, 71));
        ButDocDelete->setStyleSheet(QString::fromUtf8("border:none;\n"
"image: url(:/image/delete.png);\n"
"background-color:transparent;"));
        ButDocAdd = new QPushButton(tab_4);
        ButDocAdd->setObjectName(QString::fromUtf8("ButDocAdd"));
        ButDocAdd->setGeometry(QRect(1170, 320, 81, 71));
        ButDocAdd->setStyleSheet(QString::fromUtf8("image: url(:/image/adddoctor.png);\n"
"border:none;\n"
"background-color:transparent;"));
        tabWidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        tableView_3 = new QTableView(tab_5);
        tableView_3->setObjectName(QString::fromUtf8("tableView_3"));
        tableView_3->setGeometry(QRect(80, 110, 256, 192));
        tableView_3->setStyleSheet(QString::fromUtf8("background-color: rgb(30, 131, 140);"));
        ButLensEdit = new QPushButton(tab_5);
        ButLensEdit->setObjectName(QString::fromUtf8("ButLensEdit"));
        ButLensEdit->setGeometry(QRect(1180, 530, 91, 71));
        ButLensEdit->setStyleSheet(QString::fromUtf8("border:none;\n"
"background-color:transparent;\n"
"image: url(:/image/edit.png);"));
        ButLensTouch = new QPushButton(tab_5);
        ButLensTouch->setObjectName(QString::fromUtf8("ButLensTouch"));
        ButLensTouch->setGeometry(QRect(1190, 430, 81, 71));
        ButLensTouch->setStyleSheet(QString::fromUtf8("image: url(:/image/assesstive.png);\n"
"background-color:transparent;\n"
"border:none;"));
        ButLensDelete = new QPushButton(tab_5);
        ButLensDelete->setObjectName(QString::fromUtf8("ButLensDelete"));
        ButLensDelete->setGeometry(QRect(1080, 440, 91, 71));
        ButLensDelete->setStyleSheet(QString::fromUtf8("border:none;\n"
"image: url(:/image/delete.png);\n"
"background-color:transparent;"));
        ButLensAdd = new QPushButton(tab_5);
        ButLensAdd->setObjectName(QString::fromUtf8("ButLensAdd"));
        ButLensAdd->setGeometry(QRect(1170, 330, 81, 71));
        ButLensAdd->setStyleSheet(QString::fromUtf8("border:none;\n"
"background-color:transparent;\n"
"image: url(:/image/addlens.png);"));
        tabWidget->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QString::fromUtf8("tab_6"));
        label_4 = new QLabel(tab_6);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(320, 240, 391, 191));
        label_4->setStyleSheet(QString::fromUtf8("background-color: rgb(118, 223, 250);\n"
"font: 75 36pt \"Ubuntu\";\n"
"font:bold;"));
        label_4->setAlignment(Qt::AlignCenter);
        tabWidget->addTab(tab_6, QString());
        tab_7 = new QWidget();
        tab_7->setObjectName(QString::fromUtf8("tab_7"));
        label_5 = new QLabel(tab_7);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(480, 250, 391, 191));
        label_5->setStyleSheet(QString::fromUtf8("background-color: rgb(118, 223, 250);\n"
"font: 75 36pt \"Ubuntu\";\n"
"font:bold;"));
        label_5->setAlignment(Qt::AlignCenter);
        tabWidget->addTab(tab_7, QString());
        tab_8 = new QWidget();
        tab_8->setObjectName(QString::fromUtf8("tab_8"));
        label_6 = new QLabel(tab_8);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(440, 200, 391, 191));
        label_6->setStyleSheet(QString::fromUtf8("background-color: rgb(118, 223, 250);\n"
"font: 75 36pt \"Ubuntu\";\n"
"font:bold;"));
        label_6->setAlignment(Qt::AlignCenter);
        tabWidget->addTab(tab_8, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        label_7 = new QLabel(tab);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(440, 220, 391, 191));
        label_7->setStyleSheet(QString::fromUtf8("background-color: rgb(118, 223, 250);\n"
"font: 75 36pt \"Ubuntu\";\n"
"font:bold;"));
        label_7->setAlignment(Qt::AlignCenter);
        tabWidget->addTab(tab, QString());
        ButPatient = new QPushButton(Buttons);
        ButPatient->setObjectName(QString::fromUtf8("ButPatient"));
        ButPatient->setGeometry(QRect(0, 610, 181, 131));
        ButPatient->setStyleSheet(QString::fromUtf8("image: url(:/image/PATIENTIMG.png);\n"
"background-color:transparent;\n"
"border:none;"));
        ButCalculator = new QPushButton(Buttons);
        ButCalculator->setObjectName(QString::fromUtf8("ButCalculator"));
        ButCalculator->setGeometry(QRect(760, 610, 181, 131));
        ButCalculator->setStyleSheet(QString::fromUtf8("image: url(:/image/CALCULATORIMG.png);\n"
"background-color:transparent;\n"
"border:none;"));
        tabWidget->raise();
        ButPatient->raise();
        ButDoctor->raise();
        ButLens->raise();
        ButMeasure->raise();
        ButCalculator->raise();
        ButCalibration->raise();
        ButSettings->raise();
        ButCurrent->raise();

        retranslateUi(Buttons);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Buttons);
    } // setupUi

    void retranslateUi(QWidget *Buttons)
    {
        Buttons->setWindowTitle(QCoreApplication::translate("Buttons", "Form", nullptr));
        ButCalibration->setText(QString());
        ButDoctor->setText(QString());
        ButMeasure->setText(QString());
        ButCurrent->setText(QString());
        ButSettings->setText(QString());
        ButLens->setText(QString());
        ButPatTouch->setText(QString());
        ButPatAdd->setText(QString());
        ButPatDelete->setText(QString());
        ButPatEdit->setText(QString());
        ButPatView->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("Buttons", "Tab 1", nullptr));
        ButDocEdit->setText(QString());
        ButDocTouch->setText(QString());
        ButDocView->setText(QString());
        ButDocDelete->setText(QString());
        ButDocAdd->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("Buttons", "Tab 2", nullptr));
        ButLensEdit->setText(QString());
        ButLensTouch->setText(QString());
        ButLensDelete->setText(QString());
        ButLensAdd->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QCoreApplication::translate("Buttons", "Page", nullptr));
        label_4->setText(QCoreApplication::translate("Buttons", "Measure", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_6), QCoreApplication::translate("Buttons", "Page", nullptr));
        label_5->setText(QCoreApplication::translate("Buttons", "Calculator", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_7), QCoreApplication::translate("Buttons", "Page", nullptr));
        label_6->setText(QCoreApplication::translate("Buttons", "Calibration", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_8), QCoreApplication::translate("Buttons", "Page", nullptr));
        label_7->setText(QCoreApplication::translate("Buttons", "Settings", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("Buttons", "Page", nullptr));
        ButPatient->setText(QString());
        ButCalculator->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Buttons: public Ui_Buttons {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BUTTONS_H
