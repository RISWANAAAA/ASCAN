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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
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
    QLineEdit *lineAL;
    QLineEdit *lineSD;
    QLabel *lbllt;
    QLineEdit *lineLT;
    QLabel *lblvit;
    QLineEdit *lineACD;
    QLabel *lblsd;
    QLabel *lblal;
    QLabel *lblacd;
    QLineEdit *lineAvgAl;
    QLineEdit *lineVIT;
    QLabel *lblavgal;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QPushButton *ButReading1;
    QPushButton *ButReading2;
    QPushButton *ButReading3;
    QPushButton *ButReading4;
    QPushButton *ButReading5;
    QPushButton *ButReading6;
    QPushButton *ButReading7;
    QPushButton *ButReading8;
    QPushButton *ButReading9;
    QPushButton *ButReading10;
    QWidget *tab_7;
    QPushButton *ButSRKT;
    QPushButton *ButSRKII;
    QPushButton *ButHofferQ;
    QPushButton *ButHolladay;
    QPushButton *ButHaigis;
    QLineEdit *linelens1iol2;
    QLineEdit *linelens1ref2;
    QComboBox *combolens1;
    QLineEdit *linelens1ref1;
    QLabel *lbllemm1;
    QLabel *lbllen1ref;
    QLineEdit *linelens1ref5;
    QLineEdit *linelens1ref3;
    QLineEdit *linelens1iol1;
    QLineEdit *linelens1iol5;
    QLineEdit *linelens1iol4;
    QLineEdit *linelens1emm;
    QLineEdit *linelens1aconst;
    QLabel *lbllen1layout;
    QLineEdit *linelens1iol3;
    QLabel *lbllen1iol;
    QLabel *lbllens1aconst;
    QLineEdit *linelens1ref4;
    QLineEdit *linelens2ref2;
    QLineEdit *linelens2iol4;
    QLineEdit *linelens2ref1;
    QLineEdit *linelens2iol3;
    QLineEdit *linelens2aconst;
    QLineEdit *linelens2emm2;
    QLineEdit *linelens2iol5;
    QLabel *lbllens2iol;
    QLabel *lbllen2ref;
    QLineEdit *linelens2iol1;
    QLineEdit *linelens2ref3;
    QLineEdit *linelens2ref4;
    QLineEdit *linelens2iol2;
    QLabel *lblemm2;
    QLineEdit *linelens2ref5;
    QLabel *lbllens2aconst;
    QComboBox *combolens2;
    QLabel *lbllen2layout;
    QLineEdit *linelens3ref2;
    QLineEdit *linelens3iol4;
    QLineEdit *linelens3ref1;
    QLineEdit *linelens3iol3;
    QLineEdit *linelens3aconst3;
    QLineEdit *linelens3emm3;
    QLineEdit *linelens3iol5;
    QLabel *lbllen3iol;
    QLabel *lbllens3ref;
    QLineEdit *linelens3iol1;
    QLineEdit *linelens3ref3;
    QLineEdit *linelens3ref4;
    QLineEdit *linelens3iol2;
    QLabel *lblemm3;
    QLineEdit *linelens3ref5;
    QLabel *lbllen3aconst;
    QComboBox *combolens3;
    QLabel *lbllen3layout;
    QLabel *lblk1;
    QLineEdit *linek1;
    QLabel *lblk2;
    QLineEdit *linek2;
    QLabel *lblk;
    QLineEdit *linek;
    QLabel *lblrx;
    QLineEdit *linerx;
    QLabel *lblacd_2;
    QLineEdit *lineacd;
    QWidget *tab_8;
    QLabel *label_6;
    QWidget *tab;
    QLabel *label_7;
    QPushButton *ButPatient;
    QPushButton *ButCalculator;
    QLineEdit *linepatid;
    QLabel *lblpatid;
    QLineEdit *linepatname;
    QLabel *lblpatname;
    QLineEdit *linedocid;
    QLabel *lbldocid;
    QLineEdit *linedocname;
    QLabel *lbldocname;

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
        ButCurrent->setGeometry(QRect(0, 10, 41, 51));
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
        tabWidget->setGeometry(QRect(0, -30, 1280, 661));
        tabWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(30, 131, 140);"));
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
        ButPatAdd->setStyleSheet(QString::fromUtf8("border:none;\n"
"image: url(:/image/addperson.png);\n"
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
        lineAL = new QLineEdit(tab_6);
        lineAL->setObjectName(QString::fromUtf8("lineAL"));
        lineAL->setGeometry(QRect(0, 540, 121, 51));
        lineAL->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        lineSD = new QLineEdit(tab_6);
        lineSD->setObjectName(QString::fromUtf8("lineSD"));
        lineSD->setGeometry(QRect(0, 180, 121, 51));
        lineSD->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        lbllt = new QLabel(tab_6);
        lbllt->setObjectName(QString::fromUtf8("lbllt"));
        lbllt->setGeometry(QRect(30, 430, 41, 21));
        lbllt->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color:none;\n"
"font:bold;\n"
"font:15pt;"));
        lineLT = new QLineEdit(tab_6);
        lineLT->setObjectName(QString::fromUtf8("lineLT"));
        lineLT->setGeometry(QRect(0, 450, 121, 51));
        lineLT->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        lblvit = new QLabel(tab_6);
        lblvit->setObjectName(QString::fromUtf8("lblvit"));
        lblvit->setGeometry(QRect(30, 340, 61, 21));
        lblvit->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color:none;\n"
"font:bold;\n"
"font:15pt;"));
        lineACD = new QLineEdit(tab_6);
        lineACD->setObjectName(QString::fromUtf8("lineACD"));
        lineACD->setGeometry(QRect(0, 270, 121, 51));
        lineACD->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        lblsd = new QLabel(tab_6);
        lblsd->setObjectName(QString::fromUtf8("lblsd"));
        lblsd->setGeometry(QRect(30, 150, 41, 41));
        lblsd->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color:none;\n"
"font:bold;\n"
"font:15pt;"));
        lblal = new QLabel(tab_6);
        lblal->setObjectName(QString::fromUtf8("lblal"));
        lblal->setGeometry(QRect(30, 520, 51, 21));
        lblal->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color:none;\n"
"font:bold;\n"
"font:15pt;"));
        lblacd = new QLabel(tab_6);
        lblacd->setObjectName(QString::fromUtf8("lblacd"));
        lblacd->setGeometry(QRect(30, 250, 61, 21));
        lblacd->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color:none;\n"
"font:bold;\n"
"font:15pt;"));
        lineAvgAl = new QLineEdit(tab_6);
        lineAvgAl->setObjectName(QString::fromUtf8("lineAvgAl"));
        lineAvgAl->setGeometry(QRect(0, 90, 121, 51));
        lineAvgAl->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        lineVIT = new QLineEdit(tab_6);
        lineVIT->setObjectName(QString::fromUtf8("lineVIT"));
        lineVIT->setGeometry(QRect(0, 360, 121, 51));
        lineVIT->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        lblavgal = new QLabel(tab_6);
        lblavgal->setObjectName(QString::fromUtf8("lblavgal"));
        lblavgal->setGeometry(QRect(20, 60, 71, 41));
        lblavgal->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color:none;\n"
"font:bold;\n"
"font:15pt;"));
        scrollArea = new QScrollArea(tab_6);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(1080, 0, 191, 631));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 189, 629));
        ButReading1 = new QPushButton(scrollAreaWidgetContents);
        ButReading1->setObjectName(QString::fromUtf8("ButReading1"));
        ButReading1->setGeometry(QRect(50, 20, 89, 25));
        ButReading2 = new QPushButton(scrollAreaWidgetContents);
        ButReading2->setObjectName(QString::fromUtf8("ButReading2"));
        ButReading2->setGeometry(QRect(50, 80, 89, 25));
        ButReading3 = new QPushButton(scrollAreaWidgetContents);
        ButReading3->setObjectName(QString::fromUtf8("ButReading3"));
        ButReading3->setGeometry(QRect(50, 140, 89, 25));
        ButReading4 = new QPushButton(scrollAreaWidgetContents);
        ButReading4->setObjectName(QString::fromUtf8("ButReading4"));
        ButReading4->setGeometry(QRect(50, 200, 89, 25));
        ButReading5 = new QPushButton(scrollAreaWidgetContents);
        ButReading5->setObjectName(QString::fromUtf8("ButReading5"));
        ButReading5->setGeometry(QRect(50, 260, 89, 25));
        ButReading6 = new QPushButton(scrollAreaWidgetContents);
        ButReading6->setObjectName(QString::fromUtf8("ButReading6"));
        ButReading6->setGeometry(QRect(50, 320, 89, 25));
        ButReading7 = new QPushButton(scrollAreaWidgetContents);
        ButReading7->setObjectName(QString::fromUtf8("ButReading7"));
        ButReading7->setGeometry(QRect(50, 380, 89, 25));
        ButReading8 = new QPushButton(scrollAreaWidgetContents);
        ButReading8->setObjectName(QString::fromUtf8("ButReading8"));
        ButReading8->setGeometry(QRect(50, 440, 89, 25));
        ButReading9 = new QPushButton(scrollAreaWidgetContents);
        ButReading9->setObjectName(QString::fromUtf8("ButReading9"));
        ButReading9->setGeometry(QRect(50, 500, 89, 25));
        ButReading10 = new QPushButton(scrollAreaWidgetContents);
        ButReading10->setObjectName(QString::fromUtf8("ButReading10"));
        ButReading10->setGeometry(QRect(50, 550, 89, 25));
        scrollArea->setWidget(scrollAreaWidgetContents);
        tabWidget->addTab(tab_6, QString());
        tab_7 = new QWidget();
        tab_7->setObjectName(QString::fromUtf8("tab_7"));
        ButSRKT = new QPushButton(tab_7);
        ButSRKT->setObjectName(QString::fromUtf8("ButSRKT"));
        ButSRKT->setGeometry(QRect(1100, 120, 171, 71));
        ButSRKT->setStyleSheet(QString::fromUtf8("image: url(:/image/unselectformula.png);\n"
"color: rgb(0,0,0);\n"
"font: 75 italic 20pt \"Ubuntu\";\n"
"font:bold;\n"
"background-color:transparent;\n"
"border:none;"));
        ButSRKII = new QPushButton(tab_7);
        ButSRKII->setObjectName(QString::fromUtf8("ButSRKII"));
        ButSRKII->setGeometry(QRect(1100, 220, 171, 71));
        ButSRKII->setStyleSheet(QString::fromUtf8("image: url(:/image/unselectformula.png);\n"
"color: rgb(0,0,0);\n"
"font: 75 italic 20pt \"Ubuntu\";\n"
"font:bold;\n"
"background-color:transparent;\n"
"border:none;"));
        ButHofferQ = new QPushButton(tab_7);
        ButHofferQ->setObjectName(QString::fromUtf8("ButHofferQ"));
        ButHofferQ->setGeometry(QRect(1100, 320, 171, 71));
        ButHofferQ->setStyleSheet(QString::fromUtf8("image: url(:/image/unselectformula.png);\n"
"color: rgb(0,0,0);\n"
"font: 75 italic 20pt \"Ubuntu\";\n"
"font:bold;\n"
"background-color:transparent;\n"
"border:none;"));
        ButHolladay = new QPushButton(tab_7);
        ButHolladay->setObjectName(QString::fromUtf8("ButHolladay"));
        ButHolladay->setGeometry(QRect(1100, 420, 171, 71));
        ButHolladay->setStyleSheet(QString::fromUtf8("image: url(:/image/unselectformula.png);\n"
"color: rgb(0,0,0);\n"
"font: 75 italic 20pt \"Ubuntu\";\n"
"font:bold;\n"
"background-color:transparent;\n"
"border:none;"));
        ButHaigis = new QPushButton(tab_7);
        ButHaigis->setObjectName(QString::fromUtf8("ButHaigis"));
        ButHaigis->setGeometry(QRect(1100, 520, 171, 71));
        ButHaigis->setStyleSheet(QString::fromUtf8("image: url(:/image/unselectformula.png);\n"
"color: rgb(0,0,0);\n"
"font: 75 italic 20pt \"Ubuntu\";\n"
"font:bold;\n"
"background-color:transparent;\n"
"border:none;"));
        linelens1iol2 = new QLineEdit(tab_7);
        linelens1iol2->setObjectName(QString::fromUtf8("linelens1iol2"));
        linelens1iol2->setGeometry(QRect(330, 170, 111, 41));
        linelens1iol2->setStyleSheet(QString::fromUtf8("font: 18pt \"Ubuntu\";\n"
"color: rgb(255, 255, 255);\n"
"font:bold;\n"
"border-radius:10px;\n"
"border:1px solid white;"));
        linelens1iol2->setAlignment(Qt::AlignCenter);
        linelens1ref2 = new QLineEdit(tab_7);
        linelens1ref2->setObjectName(QString::fromUtf8("linelens1ref2"));
        linelens1ref2->setGeometry(QRect(330, 220, 111, 41));
        linelens1ref2->setStyleSheet(QString::fromUtf8("\n"
"font: 18pt \"Ubuntu\";\n"
"color: rgb(255, 255, 255);\n"
"font:bold;\n"
"border-radius:10px;\n"
"border:1px solid white;"));
        linelens1ref2->setAlignment(Qt::AlignCenter);
        combolens1 = new QComboBox(tab_7);
        combolens1->setObjectName(QString::fromUtf8("combolens1"));
        combolens1->setGeometry(QRect(0, 120, 311, 41));
        combolens1->setStyleSheet(QString::fromUtf8("font: 18pt \"Ubuntu\";\n"
"background-color: rgb(0, 117, 143);\n"
"color: rgb(255, 255, 255);\n"
"font:bold;\n"
"border-radius:10px;\n"
"border:3px solid white;"));
        linelens1ref1 = new QLineEdit(tab_7);
        linelens1ref1->setObjectName(QString::fromUtf8("linelens1ref1"));
        linelens1ref1->setGeometry(QRect(200, 220, 111, 41));
        linelens1ref1->setStyleSheet(QString::fromUtf8("font: 18pt \"Ubuntu\";\n"
"color: rgb(255, 255, 255);\n"
"font:bold;\n"
"border-radius:10px;\n"
"border:1px solid white;"));
        linelens1ref1->setAlignment(Qt::AlignCenter);
        lbllemm1 = new QLabel(tab_7);
        lbllemm1->setObjectName(QString::fromUtf8("lbllemm1"));
        lbllemm1->setGeometry(QRect(830, 170, 201, 41));
        lbllemm1->setStyleSheet(QString::fromUtf8("font: 18pt \"Ubuntu\";\n"
"background-color: rgb(0, 117, 143);\n"
"color: rgb(255, 255, 255);\n"
"font:bold;\n"
"border-radius:10px;\n"
"border:3px solid white;"));
        lbllemm1->setAlignment(Qt::AlignCenter);
        lbllen1ref = new QLabel(tab_7);
        lbllen1ref->setObjectName(QString::fromUtf8("lbllen1ref"));
        lbllen1ref->setGeometry(QRect(40, 220, 111, 41));
        lbllen1ref->setStyleSheet(QString::fromUtf8("font: 18pt \"Ubuntu\";\n"
"background-color: rgb(0, 117, 143);\n"
"color: rgb(255, 255, 255);\n"
"font:bold;\n"
"border-radius:10px;\n"
"border:3px solid white;"));
        lbllen1ref->setAlignment(Qt::AlignCenter);
        linelens1ref5 = new QLineEdit(tab_7);
        linelens1ref5->setObjectName(QString::fromUtf8("linelens1ref5"));
        linelens1ref5->setGeometry(QRect(700, 220, 101, 41));
        linelens1ref5->setStyleSheet(QString::fromUtf8("font: 18pt \"Ubuntu\";\n"
"color: rgb(255, 255, 255);\n"
"font:bold;\n"
"border-radius:10px;\n"
"border:1px solid white;"));
        linelens1ref3 = new QLineEdit(tab_7);
        linelens1ref3->setObjectName(QString::fromUtf8("linelens1ref3"));
        linelens1ref3->setGeometry(QRect(460, 220, 101, 41));
        linelens1ref3->setStyleSheet(QString::fromUtf8("font: 18pt \"Ubuntu\";\n"
"color: rgb(255, 255, 255);\n"
"font:bold;\n"
"border-radius:10px;\n"
"border:1px solid white;"));
        linelens1ref3->setAlignment(Qt::AlignCenter);
        linelens1iol1 = new QLineEdit(tab_7);
        linelens1iol1->setObjectName(QString::fromUtf8("linelens1iol1"));
        linelens1iol1->setGeometry(QRect(200, 170, 111, 41));
        linelens1iol1->setStyleSheet(QString::fromUtf8("font: 18pt \"Ubuntu\";\n"
"background-color: rgb(30, 131, 140);\n"
"color: rgb(255, 255, 255);\n"
"font:bold;\n"
"border-radius:10px;\n"
"border:1px solid white;"));
        linelens1iol1->setAlignment(Qt::AlignCenter);
        linelens1iol5 = new QLineEdit(tab_7);
        linelens1iol5->setObjectName(QString::fromUtf8("linelens1iol5"));
        linelens1iol5->setGeometry(QRect(700, 170, 101, 41));
        linelens1iol5->setStyleSheet(QString::fromUtf8("font: 18pt \"Ubuntu\";\n"
"color: rgb(255, 255, 255);\n"
"font:bold;\n"
"border-radius:10px;\n"
"border:1px solid white;"));
        linelens1iol4 = new QLineEdit(tab_7);
        linelens1iol4->setObjectName(QString::fromUtf8("linelens1iol4"));
        linelens1iol4->setGeometry(QRect(580, 170, 101, 41));
        linelens1iol4->setStyleSheet(QString::fromUtf8("font: 18pt \"Ubuntu\";\n"
"color: rgb(255, 255, 255);\n"
"font:bold;\n"
"border-radius:10px;\n"
"border:1px solid white;"));
        linelens1iol4->setAlignment(Qt::AlignCenter);
        linelens1emm = new QLineEdit(tab_7);
        linelens1emm->setObjectName(QString::fromUtf8("linelens1emm"));
        linelens1emm->setGeometry(QRect(830, 210, 201, 51));
        linelens1emm->setStyleSheet(QString::fromUtf8("font: 18pt \"Ubuntu\";\n"
"color: rgb(255, 255, 255);\n"
"font:bold;\n"
"border-radius:10px;\n"
"border:1px solid white;"));
        linelens1aconst = new QLineEdit(tab_7);
        linelens1aconst->setObjectName(QString::fromUtf8("linelens1aconst"));
        linelens1aconst->setGeometry(QRect(550, 120, 221, 41));
        linelens1aconst->setStyleSheet(QString::fromUtf8("font: 18pt \"Ubuntu\";\n"
"background-color: rgb(0, 117, 143);\n"
"color: rgb(255, 255, 255);\n"
"font:bold;\n"
"border-radius:10px;\n"
"border:3px solid white;"));
        lbllen1layout = new QLabel(tab_7);
        lbllen1layout->setObjectName(QString::fromUtf8("lbllen1layout"));
        lbllen1layout->setGeometry(QRect(0, 120, 1111, 151));
        lbllen1layout->setStyleSheet(QString::fromUtf8("border:1px solid white;\n"
"background-color: rgb(30, 131, 140);\n"
"border-radius:30px;"));
        linelens1iol3 = new QLineEdit(tab_7);
        linelens1iol3->setObjectName(QString::fromUtf8("linelens1iol3"));
        linelens1iol3->setGeometry(QRect(460, 170, 101, 41));
        linelens1iol3->setStyleSheet(QString::fromUtf8("font: 18pt \"Ubuntu\";\n"
"color: rgb(255, 255, 255);\n"
"font:bold;\n"
"border-radius:10px;\n"
"border:1px solid white;"));
        linelens1iol3->setAlignment(Qt::AlignCenter);
        lbllen1iol = new QLabel(tab_7);
        lbllen1iol->setObjectName(QString::fromUtf8("lbllen1iol"));
        lbllen1iol->setGeometry(QRect(40, 170, 111, 41));
        lbllen1iol->setStyleSheet(QString::fromUtf8("font: 18pt \"Ubuntu\";\n"
"background-color: rgb(0, 117, 143);\n"
"color: rgb(255, 255, 255);\n"
"font:bold;\n"
"border-radius:10px;\n"
"border:3px solid white;"));
        lbllen1iol->setAlignment(Qt::AlignCenter);
        lbllens1aconst = new QLabel(tab_7);
        lbllens1aconst->setObjectName(QString::fromUtf8("lbllens1aconst"));
        lbllens1aconst->setGeometry(QRect(310, 120, 241, 41));
        lbllens1aconst->setStyleSheet(QString::fromUtf8("font: 18pt \"Ubuntu\";\n"
"background-color: rgb(0, 117, 143);\n"
"color: rgb(255, 255, 255);\n"
"font:bold;\n"
"border-radius:10px;\n"
"border:3px solid white;"));
        lbllens1aconst->setAlignment(Qt::AlignCenter);
        linelens1ref4 = new QLineEdit(tab_7);
        linelens1ref4->setObjectName(QString::fromUtf8("linelens1ref4"));
        linelens1ref4->setGeometry(QRect(580, 220, 101, 41));
        linelens1ref4->setStyleSheet(QString::fromUtf8("font: 18pt \"Ubuntu\";\n"
"color: rgb(255, 255, 255);\n"
"font:bold;\n"
"border-radius:10px;\n"
"border:1px solid white;"));
        linelens1ref4->setAlignment(Qt::AlignCenter);
        linelens2ref2 = new QLineEdit(tab_7);
        linelens2ref2->setObjectName(QString::fromUtf8("linelens2ref2"));
        linelens2ref2->setGeometry(QRect(330, 380, 111, 41));
        linelens2ref2->setStyleSheet(QString::fromUtf8("font: 18pt \"Ubuntu\";\n"
"color: rgb(255, 255, 255);\n"
"font:bold;\n"
"border-radius:10px;\n"
"border:1px solid white;"));
        linelens2ref2->setAlignment(Qt::AlignCenter);
        linelens2iol4 = new QLineEdit(tab_7);
        linelens2iol4->setObjectName(QString::fromUtf8("linelens2iol4"));
        linelens2iol4->setGeometry(QRect(580, 330, 101, 41));
        linelens2iol4->setStyleSheet(QString::fromUtf8("font: 18pt \"Ubuntu\";\n"
"color: rgb(255, 255, 255);\n"
"font:bold;\n"
"border-radius:10px;\n"
"border:1px solid white;"));
        linelens2iol4->setAlignment(Qt::AlignCenter);
        linelens2ref1 = new QLineEdit(tab_7);
        linelens2ref1->setObjectName(QString::fromUtf8("linelens2ref1"));
        linelens2ref1->setGeometry(QRect(200, 380, 111, 41));
        linelens2ref1->setStyleSheet(QString::fromUtf8("font: 18pt \"Ubuntu\";\n"
"color: rgb(255, 255, 255);\n"
"font:bold;\n"
"border-radius:10px;\n"
"border:1px solid white;"));
        linelens2ref1->setAlignment(Qt::AlignCenter);
        linelens2iol3 = new QLineEdit(tab_7);
        linelens2iol3->setObjectName(QString::fromUtf8("linelens2iol3"));
        linelens2iol3->setGeometry(QRect(460, 330, 101, 41));
        linelens2iol3->setStyleSheet(QString::fromUtf8("font: 18pt \"Ubuntu\";\n"
"color: rgb(255, 255, 255);\n"
"font:bold;\n"
"border-radius:10px;\n"
"border:1px solid white;"));
        linelens2iol3->setAlignment(Qt::AlignCenter);
        linelens2aconst = new QLineEdit(tab_7);
        linelens2aconst->setObjectName(QString::fromUtf8("linelens2aconst"));
        linelens2aconst->setGeometry(QRect(550, 280, 221, 41));
        linelens2aconst->setStyleSheet(QString::fromUtf8("font: 18pt \"Ubuntu\";\n"
"background-color: rgb(0, 117, 143);\n"
"color: rgb(255, 255, 255);\n"
"font:bold;\n"
"border-radius:10px;\n"
"border:3px solid white;"));
        linelens2emm2 = new QLineEdit(tab_7);
        linelens2emm2->setObjectName(QString::fromUtf8("linelens2emm2"));
        linelens2emm2->setGeometry(QRect(830, 370, 201, 51));
        linelens2emm2->setStyleSheet(QString::fromUtf8("font: 18pt \"Ubuntu\";\n"
"color: rgb(255, 255, 255);\n"
"font:bold;\n"
"border-radius:10px;\n"
"border:1px solid white;"));
        linelens2iol5 = new QLineEdit(tab_7);
        linelens2iol5->setObjectName(QString::fromUtf8("linelens2iol5"));
        linelens2iol5->setGeometry(QRect(700, 330, 101, 41));
        linelens2iol5->setStyleSheet(QString::fromUtf8("font: 18pt \"Ubuntu\";\n"
"color: rgb(255, 255, 255);\n"
"font:bold;\n"
"border-radius:10px;\n"
"border:1px solid white;"));
        lbllens2iol = new QLabel(tab_7);
        lbllens2iol->setObjectName(QString::fromUtf8("lbllens2iol"));
        lbllens2iol->setGeometry(QRect(40, 330, 111, 41));
        lbllens2iol->setStyleSheet(QString::fromUtf8("font: 18pt \"Ubuntu\";\n"
"background-color: rgb(0, 117, 143);\n"
"color: rgb(255, 255, 255);\n"
"font:bold;\n"
"border-radius:10px;\n"
"border:3px solid white;"));
        lbllens2iol->setAlignment(Qt::AlignCenter);
        lbllen2ref = new QLabel(tab_7);
        lbllen2ref->setObjectName(QString::fromUtf8("lbllen2ref"));
        lbllen2ref->setGeometry(QRect(40, 380, 111, 41));
        lbllen2ref->setStyleSheet(QString::fromUtf8("font: 18pt \"Ubuntu\";\n"
"background-color: rgb(0, 117, 143);\n"
"color: rgb(255, 255, 255);\n"
"font:bold;\n"
"border-radius:10px;\n"
"border:3px solid white;"));
        lbllen2ref->setAlignment(Qt::AlignCenter);
        linelens2iol1 = new QLineEdit(tab_7);
        linelens2iol1->setObjectName(QString::fromUtf8("linelens2iol1"));
        linelens2iol1->setGeometry(QRect(200, 330, 111, 41));
        linelens2iol1->setStyleSheet(QString::fromUtf8("font: 18pt \"Ubuntu\";\n"
"color: rgb(255, 255, 255);\n"
"font:bold;\n"
"border-radius:10px;\n"
"border:1px solid white;"));
        linelens2iol1->setAlignment(Qt::AlignCenter);
        linelens2ref3 = new QLineEdit(tab_7);
        linelens2ref3->setObjectName(QString::fromUtf8("linelens2ref3"));
        linelens2ref3->setGeometry(QRect(460, 380, 101, 41));
        linelens2ref3->setStyleSheet(QString::fromUtf8("font: 18pt \"Ubuntu\";\n"
"color: rgb(255, 255, 255);\n"
"font:bold;\n"
"border-radius:10px;\n"
"border:1px solid white;"));
        linelens2ref3->setAlignment(Qt::AlignCenter);
        linelens2ref4 = new QLineEdit(tab_7);
        linelens2ref4->setObjectName(QString::fromUtf8("linelens2ref4"));
        linelens2ref4->setGeometry(QRect(580, 380, 101, 41));
        linelens2ref4->setStyleSheet(QString::fromUtf8("font: 18pt \"Ubuntu\";\n"
"color: rgb(255, 255, 255);\n"
"font:bold;\n"
"border-radius:10px;\n"
"border:1px solid white;"));
        linelens2ref4->setAlignment(Qt::AlignCenter);
        linelens2iol2 = new QLineEdit(tab_7);
        linelens2iol2->setObjectName(QString::fromUtf8("linelens2iol2"));
        linelens2iol2->setGeometry(QRect(330, 330, 111, 41));
        linelens2iol2->setStyleSheet(QString::fromUtf8("font: 18pt \"Ubuntu\";\n"
"color: rgb(255, 255, 255);\n"
"font:bold;\n"
"border-radius:10px;\n"
"border:1px solid white;"));
        linelens2iol2->setAlignment(Qt::AlignCenter);
        lblemm2 = new QLabel(tab_7);
        lblemm2->setObjectName(QString::fromUtf8("lblemm2"));
        lblemm2->setGeometry(QRect(830, 330, 201, 41));
        lblemm2->setStyleSheet(QString::fromUtf8("font: 18pt \"Ubuntu\";\n"
"background-color: rgb(0, 117, 143);\n"
"color: rgb(255, 255, 255);\n"
"font:bold;\n"
"border-radius:10px;\n"
"border:3px solid white;"));
        lblemm2->setAlignment(Qt::AlignCenter);
        linelens2ref5 = new QLineEdit(tab_7);
        linelens2ref5->setObjectName(QString::fromUtf8("linelens2ref5"));
        linelens2ref5->setGeometry(QRect(700, 380, 101, 41));
        linelens2ref5->setStyleSheet(QString::fromUtf8("font: 18pt \"Ubuntu\";\n"
"color: rgb(255, 255, 255);\n"
"font:bold;\n"
"border-radius:10px;\n"
"border:1px solid white;"));
        lbllens2aconst = new QLabel(tab_7);
        lbllens2aconst->setObjectName(QString::fromUtf8("lbllens2aconst"));
        lbllens2aconst->setGeometry(QRect(310, 280, 241, 41));
        lbllens2aconst->setStyleSheet(QString::fromUtf8("font: 18pt \"Ubuntu\";\n"
"background-color: rgb(0, 117, 143);\n"
"color: rgb(255, 255, 255);\n"
"font:bold;\n"
"border-radius:10px;\n"
"border:3px solid white;"));
        lbllens2aconst->setAlignment(Qt::AlignCenter);
        combolens2 = new QComboBox(tab_7);
        combolens2->setObjectName(QString::fromUtf8("combolens2"));
        combolens2->setGeometry(QRect(0, 280, 311, 41));
        combolens2->setStyleSheet(QString::fromUtf8("font: 18pt \"Ubuntu\";\n"
"background-color: rgb(0, 117, 143);\n"
"color: rgb(255, 255, 255);\n"
"font:bold;\n"
"border-radius:10px;\n"
"border:3px solid white;"));
        lbllen2layout = new QLabel(tab_7);
        lbllen2layout->setObjectName(QString::fromUtf8("lbllen2layout"));
        lbllen2layout->setGeometry(QRect(0, 280, 1111, 151));
        lbllen2layout->setStyleSheet(QString::fromUtf8("border:1px solid white;\n"
"background-color: rgb(30, 131, 140);\n"
"border-radius:30px;"));
        linelens3ref2 = new QLineEdit(tab_7);
        linelens3ref2->setObjectName(QString::fromUtf8("linelens3ref2"));
        linelens3ref2->setGeometry(QRect(330, 540, 111, 41));
        linelens3ref2->setStyleSheet(QString::fromUtf8("font: 18pt \"Ubuntu\";\n"
"color: rgb(255, 255, 255);\n"
"font:bold;\n"
"border-radius:10px;\n"
"border:1px solid white;"));
        linelens3ref2->setAlignment(Qt::AlignCenter);
        linelens3iol4 = new QLineEdit(tab_7);
        linelens3iol4->setObjectName(QString::fromUtf8("linelens3iol4"));
        linelens3iol4->setGeometry(QRect(580, 490, 101, 41));
        linelens3iol4->setStyleSheet(QString::fromUtf8("font: 18pt \"Ubuntu\";\n"
"color: rgb(255, 255, 255);\n"
"font:bold;\n"
"border-radius:10px;\n"
"border:1px solid white;"));
        linelens3iol4->setAlignment(Qt::AlignCenter);
        linelens3ref1 = new QLineEdit(tab_7);
        linelens3ref1->setObjectName(QString::fromUtf8("linelens3ref1"));
        linelens3ref1->setGeometry(QRect(200, 540, 111, 41));
        linelens3ref1->setStyleSheet(QString::fromUtf8("font: 18pt \"Ubuntu\";\n"
"color: rgb(255, 255, 255);\n"
"font:bold;\n"
"border-radius:10px;\n"
"border:1px solid white;"));
        linelens3ref1->setAlignment(Qt::AlignCenter);
        linelens3iol3 = new QLineEdit(tab_7);
        linelens3iol3->setObjectName(QString::fromUtf8("linelens3iol3"));
        linelens3iol3->setGeometry(QRect(460, 490, 101, 41));
        linelens3iol3->setStyleSheet(QString::fromUtf8("font: 18pt \"Ubuntu\";\n"
"color: rgb(255, 255, 255);\n"
"font:bold;\n"
"border-radius:10px;\n"
"border:1px solid white;"));
        linelens3iol3->setAlignment(Qt::AlignCenter);
        linelens3aconst3 = new QLineEdit(tab_7);
        linelens3aconst3->setObjectName(QString::fromUtf8("linelens3aconst3"));
        linelens3aconst3->setGeometry(QRect(550, 440, 221, 41));
        linelens3aconst3->setStyleSheet(QString::fromUtf8("font: 18pt \"Ubuntu\";\n"
"background-color: rgb(0, 117, 143);\n"
"color: rgb(255, 255, 255);\n"
"font:bold;\n"
"border-radius:10px;\n"
"border:3px solid white;"));
        linelens3emm3 = new QLineEdit(tab_7);
        linelens3emm3->setObjectName(QString::fromUtf8("linelens3emm3"));
        linelens3emm3->setGeometry(QRect(830, 530, 201, 51));
        linelens3emm3->setStyleSheet(QString::fromUtf8("font: 18pt \"Ubuntu\";\n"
"color: rgb(255, 255, 255);\n"
"font:bold;\n"
"border-radius:10px;\n"
"border:1px solid white;"));
        linelens3iol5 = new QLineEdit(tab_7);
        linelens3iol5->setObjectName(QString::fromUtf8("linelens3iol5"));
        linelens3iol5->setGeometry(QRect(700, 490, 101, 41));
        linelens3iol5->setStyleSheet(QString::fromUtf8("font: 18pt \"Ubuntu\";\n"
"color: rgb(255, 255, 255);\n"
"font:bold;\n"
"border-radius:10px;\n"
"border:1px solid white;"));
        lbllen3iol = new QLabel(tab_7);
        lbllen3iol->setObjectName(QString::fromUtf8("lbllen3iol"));
        lbllen3iol->setGeometry(QRect(40, 490, 111, 41));
        lbllen3iol->setStyleSheet(QString::fromUtf8("font: 18pt \"Ubuntu\";\n"
"background-color: rgb(0, 117, 143);\n"
"color: rgb(255, 255, 255);\n"
"font:bold;\n"
"border-radius:10px;\n"
"border:3px solid white;"));
        lbllen3iol->setAlignment(Qt::AlignCenter);
        lbllens3ref = new QLabel(tab_7);
        lbllens3ref->setObjectName(QString::fromUtf8("lbllens3ref"));
        lbllens3ref->setGeometry(QRect(40, 540, 111, 41));
        lbllens3ref->setStyleSheet(QString::fromUtf8("font: 18pt \"Ubuntu\";\n"
"background-color: rgb(0, 117, 143);\n"
"color: rgb(255, 255, 255);\n"
"font:bold;\n"
"border-radius:10px;\n"
"border:3px solid white;"));
        lbllens3ref->setAlignment(Qt::AlignCenter);
        linelens3iol1 = new QLineEdit(tab_7);
        linelens3iol1->setObjectName(QString::fromUtf8("linelens3iol1"));
        linelens3iol1->setGeometry(QRect(200, 490, 111, 41));
        linelens3iol1->setStyleSheet(QString::fromUtf8("font: 18pt \"Ubuntu\";\n"
"color: rgb(255, 255, 255);\n"
"font:bold;\n"
"border-radius:10px;\n"
"border:1px solid white;"));
        linelens3iol1->setAlignment(Qt::AlignCenter);
        linelens3ref3 = new QLineEdit(tab_7);
        linelens3ref3->setObjectName(QString::fromUtf8("linelens3ref3"));
        linelens3ref3->setGeometry(QRect(460, 540, 101, 41));
        linelens3ref3->setStyleSheet(QString::fromUtf8("font: 18pt \"Ubuntu\";\n"
"color: rgb(255, 255, 255);\n"
"font:bold;\n"
"border-radius:10px;\n"
"border:1px solid white;"));
        linelens3ref3->setAlignment(Qt::AlignCenter);
        linelens3ref4 = new QLineEdit(tab_7);
        linelens3ref4->setObjectName(QString::fromUtf8("linelens3ref4"));
        linelens3ref4->setGeometry(QRect(580, 540, 101, 41));
        linelens3ref4->setStyleSheet(QString::fromUtf8("font: 18pt \"Ubuntu\";\n"
"color: rgb(255, 255, 255);\n"
"font:bold;\n"
"border-radius:10px;\n"
"border:1px solid white;"));
        linelens3ref4->setAlignment(Qt::AlignCenter);
        linelens3iol2 = new QLineEdit(tab_7);
        linelens3iol2->setObjectName(QString::fromUtf8("linelens3iol2"));
        linelens3iol2->setGeometry(QRect(330, 490, 111, 41));
        linelens3iol2->setStyleSheet(QString::fromUtf8("font: 18pt \"Ubuntu\";\n"
"color: rgb(255, 255, 255);\n"
"font:bold;\n"
"border-radius:10px;\n"
"border:1px solid white;"));
        linelens3iol2->setAlignment(Qt::AlignCenter);
        lblemm3 = new QLabel(tab_7);
        lblemm3->setObjectName(QString::fromUtf8("lblemm3"));
        lblemm3->setGeometry(QRect(830, 490, 201, 41));
        lblemm3->setStyleSheet(QString::fromUtf8("font: 18pt \"Ubuntu\";\n"
"background-color: rgb(0, 117, 143);\n"
"color: rgb(255, 255, 255);\n"
"font:bold;\n"
"border-radius:10px;\n"
"border:3px solid white;"));
        lblemm3->setAlignment(Qt::AlignCenter);
        linelens3ref5 = new QLineEdit(tab_7);
        linelens3ref5->setObjectName(QString::fromUtf8("linelens3ref5"));
        linelens3ref5->setGeometry(QRect(700, 540, 101, 41));
        linelens3ref5->setStyleSheet(QString::fromUtf8("font: 18pt \"Ubuntu\";\n"
"color: rgb(255, 255, 255);\n"
"font:bold;\n"
"border-radius:10px;\n"
"border:1px solid white;"));
        lbllen3aconst = new QLabel(tab_7);
        lbllen3aconst->setObjectName(QString::fromUtf8("lbllen3aconst"));
        lbllen3aconst->setGeometry(QRect(310, 440, 241, 41));
        lbllen3aconst->setStyleSheet(QString::fromUtf8("font: 18pt \"Ubuntu\";\n"
"background-color: rgb(0, 117, 143);\n"
"color: rgb(255, 255, 255);\n"
"font:bold;\n"
"border-radius:10px;\n"
"border:3px solid white;"));
        lbllen3aconst->setAlignment(Qt::AlignCenter);
        combolens3 = new QComboBox(tab_7);
        combolens3->setObjectName(QString::fromUtf8("combolens3"));
        combolens3->setGeometry(QRect(0, 440, 311, 41));
        combolens3->setStyleSheet(QString::fromUtf8("font: 18pt \"Ubuntu\";\n"
"background-color: rgb(0, 117, 143);\n"
"color: rgb(255, 255, 255);\n"
"font:bold;\n"
"border-radius:10px;\n"
"border:3px solid white;"));
        lbllen3layout = new QLabel(tab_7);
        lbllen3layout->setObjectName(QString::fromUtf8("lbllen3layout"));
        lbllen3layout->setGeometry(QRect(0, 440, 1111, 151));
        lbllen3layout->setStyleSheet(QString::fromUtf8("border:1px solid white;\n"
"background-color: rgb(30, 131, 140);\n"
"border-radius:30px;"));
        lblk1 = new QLabel(tab_7);
        lblk1->setObjectName(QString::fromUtf8("lblk1"));
        lblk1->setGeometry(QRect(50, 60, 111, 41));
        lblk1->setStyleSheet(QString::fromUtf8("font: 18pt \"Ubuntu\";\n"
"background-color: rgb(0, 117, 143);\n"
"color: rgb(255, 255, 255);\n"
"font:bold;\n"
"border-radius:10px;\n"
"border:3px solid white;"));
        lblk1->setAlignment(Qt::AlignCenter);
        linek1 = new QLineEdit(tab_7);
        linek1->setObjectName(QString::fromUtf8("linek1"));
        linek1->setGeometry(QRect(160, 60, 121, 41));
        linek1->setStyleSheet(QString::fromUtf8("font: 18pt \"Ubuntu\";\n"
"background-color: rgb(30, 131, 140);\n"
"color: rgb(255, 255, 255);\n"
"font:bold;\n"
"border-radius:10px;\n"
"border:1px solid white;"));
        linek1->setAlignment(Qt::AlignCenter);
        lblk2 = new QLabel(tab_7);
        lblk2->setObjectName(QString::fromUtf8("lblk2"));
        lblk2->setGeometry(QRect(300, 60, 111, 41));
        lblk2->setStyleSheet(QString::fromUtf8("font: 18pt \"Ubuntu\";\n"
"background-color: rgb(0, 117, 143);\n"
"color: rgb(255, 255, 255);\n"
"font:bold;\n"
"border-radius:10px;\n"
"border:3px solid white;"));
        lblk2->setAlignment(Qt::AlignCenter);
        linek2 = new QLineEdit(tab_7);
        linek2->setObjectName(QString::fromUtf8("linek2"));
        linek2->setGeometry(QRect(410, 60, 121, 41));
        linek2->setStyleSheet(QString::fromUtf8("font: 18pt \"Ubuntu\";\n"
"background-color: rgb(30, 131, 140);\n"
"color: rgb(255, 255, 255);\n"
"font:bold;\n"
"border-radius:10px;\n"
"border:1px solid white;"));
        linek2->setAlignment(Qt::AlignCenter);
        lblk = new QLabel(tab_7);
        lblk->setObjectName(QString::fromUtf8("lblk"));
        lblk->setGeometry(QRect(550, 60, 111, 41));
        lblk->setStyleSheet(QString::fromUtf8("font: 18pt \"Ubuntu\";\n"
"background-color: rgb(0, 117, 143);\n"
"color: rgb(255, 255, 255);\n"
"font:bold;\n"
"border-radius:10px;\n"
"border:3px solid white;"));
        lblk->setAlignment(Qt::AlignCenter);
        linek = new QLineEdit(tab_7);
        linek->setObjectName(QString::fromUtf8("linek"));
        linek->setGeometry(QRect(660, 60, 121, 41));
        linek->setStyleSheet(QString::fromUtf8("font: 18pt \"Ubuntu\";\n"
"background-color: rgb(30, 131, 140);\n"
"color: rgb(255, 255, 255);\n"
"font:bold;\n"
"border-radius:10px;\n"
"border:1px solid white;"));
        linek->setAlignment(Qt::AlignCenter);
        lblrx = new QLabel(tab_7);
        lblrx->setObjectName(QString::fromUtf8("lblrx"));
        lblrx->setGeometry(QRect(800, 60, 111, 41));
        lblrx->setStyleSheet(QString::fromUtf8("font: 18pt \"Ubuntu\";\n"
"background-color: rgb(0, 117, 143);\n"
"color: rgb(255, 255, 255);\n"
"font:bold;\n"
"border-radius:10px;\n"
"border:3px solid white;"));
        lblrx->setAlignment(Qt::AlignCenter);
        linerx = new QLineEdit(tab_7);
        linerx->setObjectName(QString::fromUtf8("linerx"));
        linerx->setGeometry(QRect(910, 60, 121, 41));
        linerx->setStyleSheet(QString::fromUtf8("font: 18pt \"Ubuntu\";\n"
"background-color: rgb(30, 131, 140);\n"
"color: rgb(255, 255, 255);\n"
"font:bold;\n"
"border-radius:10px;\n"
"border:1px solid white;"));
        linerx->setAlignment(Qt::AlignCenter);
        lblacd_2 = new QLabel(tab_7);
        lblacd_2->setObjectName(QString::fromUtf8("lblacd_2"));
        lblacd_2->setGeometry(QRect(1040, 60, 111, 41));
        lblacd_2->setStyleSheet(QString::fromUtf8("font: 18pt \"Ubuntu\";\n"
"background-color: rgb(0, 117, 143);\n"
"color: rgb(255, 255, 255);\n"
"font:bold;\n"
"border-radius:10px;\n"
"border:3px solid white;"));
        lblacd_2->setAlignment(Qt::AlignCenter);
        lineacd = new QLineEdit(tab_7);
        lineacd->setObjectName(QString::fromUtf8("lineacd"));
        lineacd->setGeometry(QRect(1150, 60, 121, 41));
        lineacd->setStyleSheet(QString::fromUtf8("font: 18pt \"Ubuntu\";\n"
"background-color: rgb(30, 131, 140);\n"
"color: rgb(255, 255, 255);\n"
"font:bold;\n"
"border-radius:10px;\n"
"border:1px solid white;"));
        lineacd->setAlignment(Qt::AlignCenter);
        tabWidget->addTab(tab_7, QString());
        lbllen3layout->raise();
        lbllen2layout->raise();
        ButHofferQ->raise();
        ButHolladay->raise();
        ButHaigis->raise();
        lbllen1layout->raise();
        linelens1emm->raise();
        linelens1ref4->raise();
        linelens1ref3->raise();
        lbllen1ref->raise();
        linelens1iol3->raise();
        lbllens1aconst->raise();
        lbllemm1->raise();
        linelens1ref2->raise();
        linelens1aconst->raise();
        linelens1iol5->raise();
        linelens1ref1->raise();
        lbllen1iol->raise();
        linelens1iol2->raise();
        linelens1iol1->raise();
        linelens1ref5->raise();
        linelens1iol4->raise();
        combolens1->raise();
        linelens2ref2->raise();
        linelens2iol4->raise();
        linelens2ref1->raise();
        linelens2iol3->raise();
        linelens2aconst->raise();
        linelens2emm2->raise();
        linelens2iol5->raise();
        lbllens2iol->raise();
        lbllen2ref->raise();
        linelens2iol1->raise();
        linelens2ref3->raise();
        linelens2ref4->raise();
        linelens2iol2->raise();
        lblemm2->raise();
        linelens2ref5->raise();
        lbllens2aconst->raise();
        linelens3ref2->raise();
        linelens3iol4->raise();
        linelens3ref1->raise();
        linelens3iol3->raise();
        linelens3aconst3->raise();
        linelens3emm3->raise();
        linelens3iol5->raise();
        lbllen3iol->raise();
        lbllens3ref->raise();
        linelens3iol1->raise();
        linelens3ref3->raise();
        linelens3ref4->raise();
        linelens3iol2->raise();
        lblemm3->raise();
        linelens3ref5->raise();
        lbllen3aconst->raise();
        combolens3->raise();
        combolens2->raise();
        lblk1->raise();
        linek1->raise();
        lblk2->raise();
        linek2->raise();
        lblk->raise();
        linek->raise();
        lblrx->raise();
        linerx->raise();
        lblacd_2->raise();
        lineacd->raise();
        ButSRKII->raise();
        ButSRKT->raise();
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
        linepatid = new QLineEdit(Buttons);
        linepatid->setObjectName(QString::fromUtf8("linepatid"));
        linepatid->setGeometry(QRect(160, 10, 111, 41));
        linepatid->setStyleSheet(QString::fromUtf8("font: 18pt \"Ubuntu\";\n"
"color: rgb(255, 255, 255);\n"
"font:bold;\n"
"border-radius:10px;\n"
"border:1px solid white;"));
        linepatid->setAlignment(Qt::AlignCenter);
        lblpatid = new QLabel(Buttons);
        lblpatid->setObjectName(QString::fromUtf8("lblpatid"));
        lblpatid->setGeometry(QRect(50, 10, 111, 41));
        lblpatid->setStyleSheet(QString::fromUtf8("font: 18pt \"Ubuntu\";\n"
"color: rgb(255, 255, 255);\n"
"font:bold;\n"
"border-radius:10px;\n"
"border:3px solid white;"));
        lblpatid->setAlignment(Qt::AlignCenter);
        linepatname = new QLineEdit(Buttons);
        linepatname->setObjectName(QString::fromUtf8("linepatname"));
        linepatname->setGeometry(QRect(440, 10, 111, 41));
        linepatname->setStyleSheet(QString::fromUtf8("font: 18pt \"Ubuntu\";\n"
"color: rgb(255, 255, 255);\n"
"font:bold;\n"
"border-radius:10px;\n"
"border:1px solid white;"));
        linepatname->setAlignment(Qt::AlignCenter);
        lblpatname = new QLabel(Buttons);
        lblpatname->setObjectName(QString::fromUtf8("lblpatname"));
        lblpatname->setGeometry(QRect(290, 10, 151, 41));
        lblpatname->setStyleSheet(QString::fromUtf8("font: 18pt \"Ubuntu\";\n"
"color: rgb(255, 255, 255);\n"
"font:bold;\n"
"border-radius:10px;\n"
"border:3px solid white;"));
        lblpatname->setAlignment(Qt::AlignCenter);
        linedocid = new QLineEdit(Buttons);
        linedocid->setObjectName(QString::fromUtf8("linedocid"));
        linedocid->setGeometry(QRect(670, 10, 111, 41));
        linedocid->setStyleSheet(QString::fromUtf8("font: 18pt \"Ubuntu\";\n"
"color: rgb(255, 255, 255);\n"
"font:bold;\n"
"border-radius:10px;\n"
"border:1px solid white;"));
        linedocid->setAlignment(Qt::AlignCenter);
        lbldocid = new QLabel(Buttons);
        lbldocid->setObjectName(QString::fromUtf8("lbldocid"));
        lbldocid->setGeometry(QRect(560, 10, 111, 41));
        lbldocid->setStyleSheet(QString::fromUtf8("font: 18pt \"Ubuntu\";\n"
"color: rgb(255, 255, 255);\n"
"font:bold;\n"
"border-radius:10px;\n"
"border:3px solid white;"));
        lbldocid->setAlignment(Qt::AlignCenter);
        linedocname = new QLineEdit(Buttons);
        linedocname->setObjectName(QString::fromUtf8("linedocname"));
        linedocname->setGeometry(QRect(940, 10, 111, 41));
        linedocname->setStyleSheet(QString::fromUtf8("font: 18pt \"Ubuntu\";\n"
"color: rgb(255, 255, 255);\n"
"font:bold;\n"
"border-radius:10px;\n"
"border:1px solid white;"));
        linedocname->setAlignment(Qt::AlignCenter);
        lbldocname = new QLabel(Buttons);
        lbldocname->setObjectName(QString::fromUtf8("lbldocname"));
        lbldocname->setGeometry(QRect(800, 10, 141, 41));
        lbldocname->setStyleSheet(QString::fromUtf8("font: 18pt \"Ubuntu\";\n"
"color: rgb(255, 255, 255);\n"
"font:bold;\n"
"border-radius:10px;\n"
"border:3px solid white;"));
        lbldocname->setAlignment(Qt::AlignCenter);
        tabWidget->raise();
        ButPatient->raise();
        ButDoctor->raise();
        ButLens->raise();
        ButMeasure->raise();
        ButCalculator->raise();
        ButCalibration->raise();
        ButSettings->raise();
        ButCurrent->raise();
        lblpatid->raise();
        lblpatname->raise();
        linedocid->raise();
        lbldocid->raise();
        linedocname->raise();
        lbldocname->raise();
        linepatid->raise();
        linepatname->raise();

        retranslateUi(Buttons);

        tabWidget->setCurrentIndex(4);


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
        lbllt->setText(QCoreApplication::translate("Buttons", "LT", nullptr));
        lblvit->setText(QCoreApplication::translate("Buttons", "VIT", nullptr));
        lblsd->setText(QCoreApplication::translate("Buttons", "SD", nullptr));
        lblal->setText(QCoreApplication::translate("Buttons", "AL", nullptr));
        lblacd->setText(QCoreApplication::translate("Buttons", "ACD", nullptr));
        lblavgal->setText(QCoreApplication::translate("Buttons", "AVG AL", nullptr));
        ButReading1->setText(QCoreApplication::translate("Buttons", "1", nullptr));
        ButReading2->setText(QCoreApplication::translate("Buttons", "2", nullptr));
        ButReading3->setText(QCoreApplication::translate("Buttons", "3", nullptr));
        ButReading4->setText(QCoreApplication::translate("Buttons", "4", nullptr));
        ButReading5->setText(QCoreApplication::translate("Buttons", "5", nullptr));
        ButReading6->setText(QCoreApplication::translate("Buttons", "6", nullptr));
        ButReading7->setText(QCoreApplication::translate("Buttons", "7", nullptr));
        ButReading8->setText(QCoreApplication::translate("Buttons", "8", nullptr));
        ButReading9->setText(QCoreApplication::translate("Buttons", "9", nullptr));
        ButReading10->setText(QCoreApplication::translate("Buttons", "10", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_6), QCoreApplication::translate("Buttons", "Page", nullptr));
        ButSRKT->setText(QCoreApplication::translate("Buttons", "SRKT", nullptr));
        ButSRKII->setText(QCoreApplication::translate("Buttons", "SRKII", nullptr));
        ButHofferQ->setText(QCoreApplication::translate("Buttons", "Hoffer Q", nullptr));
        ButHolladay->setText(QCoreApplication::translate("Buttons", "Holladay", nullptr));
        ButHaigis->setText(QCoreApplication::translate("Buttons", "Haigis", nullptr));
        lbllemm1->setText(QCoreApplication::translate("Buttons", "EMM", nullptr));
        lbllen1ref->setText(QCoreApplication::translate("Buttons", "REF", nullptr));
        linelens1iol1->setText(QCoreApplication::translate("Buttons", "0.12", nullptr));
        lbllen1layout->setText(QString());
        lbllen1iol->setText(QCoreApplication::translate("Buttons", "IOL", nullptr));
        lbllens1aconst->setText(QCoreApplication::translate("Buttons", "ACONST", nullptr));
        lbllens2iol->setText(QCoreApplication::translate("Buttons", "IOL", nullptr));
        lbllen2ref->setText(QCoreApplication::translate("Buttons", "REF", nullptr));
        linelens2iol1->setText(QCoreApplication::translate("Buttons", "0.12", nullptr));
        lblemm2->setText(QCoreApplication::translate("Buttons", "EMM", nullptr));
        lbllens2aconst->setText(QCoreApplication::translate("Buttons", "ACONST", nullptr));
        lbllen2layout->setText(QString());
        lbllen3iol->setText(QCoreApplication::translate("Buttons", "IOL", nullptr));
        lbllens3ref->setText(QCoreApplication::translate("Buttons", "REF", nullptr));
        linelens3iol1->setText(QCoreApplication::translate("Buttons", "0.12", nullptr));
        lblemm3->setText(QCoreApplication::translate("Buttons", "EMM", nullptr));
        lbllen3aconst->setText(QCoreApplication::translate("Buttons", "ACONST", nullptr));
        lbllen3layout->setText(QString());
        lblk1->setText(QCoreApplication::translate("Buttons", "K1(mm)", nullptr));
        linek1->setText(QString());
        lblk2->setText(QCoreApplication::translate("Buttons", "K2(mm)", nullptr));
        linek2->setText(QString());
        lblk->setText(QCoreApplication::translate("Buttons", "K", nullptr));
        linek->setText(QCoreApplication::translate("Buttons", "45.00", nullptr));
        lblrx->setText(QCoreApplication::translate("Buttons", "Rx", nullptr));
        linerx->setText(QCoreApplication::translate("Buttons", "0.00", nullptr));
        lblacd_2->setText(QCoreApplication::translate("Buttons", "AL", nullptr));
        lineacd->setText(QCoreApplication::translate("Buttons", "23.00", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_7), QCoreApplication::translate("Buttons", "Page", nullptr));
        label_6->setText(QCoreApplication::translate("Buttons", "Calibration", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_8), QCoreApplication::translate("Buttons", "Page", nullptr));
        label_7->setText(QCoreApplication::translate("Buttons", "Settings", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("Buttons", "Page", nullptr));
        ButPatient->setText(QString());
        ButCalculator->setText(QString());
        linepatid->setText(QString());
        lblpatid->setText(QCoreApplication::translate("Buttons", "Pat_ID", nullptr));
        linepatname->setText(QString());
        lblpatname->setText(QCoreApplication::translate("Buttons", "Pat_Name", nullptr));
        linedocid->setText(QString());
        lbldocid->setText(QCoreApplication::translate("Buttons", "Doc_ID", nullptr));
        linedocname->setText(QString());
        lbldocname->setText(QCoreApplication::translate("Buttons", "Doc_Name", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Buttons: public Ui_Buttons {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BUTTONS_H
