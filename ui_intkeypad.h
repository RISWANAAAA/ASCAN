/********************************************************************************
** Form generated from reading UI file 'intkeypad.ui'
**
** Created by: Qt User Interface Compiler version 5.15.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INTKEYPAD_H
#define UI_INTKEYPAD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_intkeypad
{
public:
    QPushButton *But8;
    QPushButton *But0;
    QPushButton *ButEnter;
    QLabel *label;
    QPushButton *ButTwo;
    QPushButton *But6;
    QPushButton *But4;
    QPushButton *But5;
    QPushButton *But7;
    QPushButton *But9;
    QPushButton *ButBack;
    QPushButton *But3;
    QPushButton *ButOne;
    QPushButton *ButEnter_2;

    void setupUi(QDialog *intkeypad)
    {
        if (intkeypad->objectName().isEmpty())
            intkeypad->setObjectName(QString::fromUtf8("intkeypad"));
        intkeypad->resize(419, 328);
        But8 = new QPushButton(intkeypad);
        But8->setObjectName(QString::fromUtf8("But8"));
        But8->setGeometry(QRect(110, 10, 71, 71));
        But8->setStyleSheet(QString::fromUtf8("image: url(:/image/textbutton.png);\n"
"font: 75 17pt \"Ubuntu\";\n"
"font:bold;\n"
"border:none;"));
        But0 = new QPushButton(intkeypad);
        But0->setObjectName(QString::fromUtf8("But0"));
        But0->setGeometry(QRect(110, 250, 71, 71));
        But0->setStyleSheet(QString::fromUtf8("image: url(:/image/textbutton.png);\n"
"font: 75 17pt \"Ubuntu\";\n"
"font:bold;\n"
"border:none;"));
        ButEnter = new QPushButton(intkeypad);
        ButEnter->setObjectName(QString::fromUtf8("ButEnter"));
        ButEnter->setGeometry(QRect(270, 100, 161, 71));
        ButEnter->setStyleSheet(QString::fromUtf8("border:none;\n"
"image: url(:/image/enterbutton.png);\n"
"font: 75 17pt \"Ubuntu\";\n"
"font:bold;\n"
"border:none;"));
        label = new QLabel(intkeypad);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 421, 331));
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(3, 96, 126);"));
        ButTwo = new QPushButton(intkeypad);
        ButTwo->setObjectName(QString::fromUtf8("ButTwo"));
        ButTwo->setGeometry(QRect(110, 170, 71, 71));
        ButTwo->setStyleSheet(QString::fromUtf8("image: url(:/image/textbutton.png);\n"
"font: 75 17pt \"Ubuntu\";\n"
"font:bold;\n"
"border:none;"));
        But6 = new QPushButton(intkeypad);
        But6->setObjectName(QString::fromUtf8("But6"));
        But6->setGeometry(QRect(200, 90, 71, 71));
        But6->setStyleSheet(QString::fromUtf8("image: url(:/image/textbutton.png);\n"
"font: 75 17pt \"Ubuntu\";\n"
"font:bold;\n"
"border:none;"));
        But4 = new QPushButton(intkeypad);
        But4->setObjectName(QString::fromUtf8("But4"));
        But4->setGeometry(QRect(20, 90, 71, 71));
        But4->setStyleSheet(QString::fromUtf8("image: url(:/image/textbutton.png);\n"
"font: 75 17pt \"Ubuntu\";\n"
"font:bold;\n"
"border:none;"));
        But5 = new QPushButton(intkeypad);
        But5->setObjectName(QString::fromUtf8("But5"));
        But5->setGeometry(QRect(110, 90, 71, 71));
        But5->setStyleSheet(QString::fromUtf8("image: url(:/image/textbutton.png);\n"
"font: 75 17pt \"Ubuntu\";\n"
"font:bold;\n"
"border:none;"));
        But7 = new QPushButton(intkeypad);
        But7->setObjectName(QString::fromUtf8("But7"));
        But7->setGeometry(QRect(20, 10, 71, 71));
        But7->setStyleSheet(QString::fromUtf8("image: url(:/image/textbutton.png);\n"
"font: 75 17pt \"Ubuntu\";\n"
"font:bold;\n"
"border:none;"));
        But9 = new QPushButton(intkeypad);
        But9->setObjectName(QString::fromUtf8("But9"));
        But9->setGeometry(QRect(200, 10, 71, 71));
        But9->setStyleSheet(QString::fromUtf8("image: url(:/image/textbutton.png);\n"
"font: 75 17pt \"Ubuntu\";\n"
"font:bold;\n"
"border:none;"));
        ButBack = new QPushButton(intkeypad);
        ButBack->setObjectName(QString::fromUtf8("ButBack"));
        ButBack->setGeometry(QRect(290, 10, 121, 71));
        ButBack->setStyleSheet(QString::fromUtf8("font: 75 17pt \"Ubuntu\";\n"
"image: url(:/image/enterbutton.png);\n"
"font:bold;\n"
"border:none;"));
        But3 = new QPushButton(intkeypad);
        But3->setObjectName(QString::fromUtf8("But3"));
        But3->setGeometry(QRect(200, 170, 71, 71));
        But3->setStyleSheet(QString::fromUtf8("image: url(:/image/textbutton.png);\n"
"font: 75 17pt \"Ubuntu\";\n"
"font:bold;\n"
"border:none;"));
        ButOne = new QPushButton(intkeypad);
        ButOne->setObjectName(QString::fromUtf8("ButOne"));
        ButOne->setGeometry(QRect(20, 170, 71, 71));
        ButOne->setStyleSheet(QString::fromUtf8("image: url(:/image/textbutton.png);\n"
"font: 75 17pt \"Ubuntu\";\n"
"font:bold;\n"
"border:none;"));
        ButEnter_2 = new QPushButton(intkeypad);
        ButEnter_2->setObjectName(QString::fromUtf8("ButEnter_2"));
        ButEnter_2->setGeometry(QRect(270, 200, 161, 71));
        ButEnter_2->setStyleSheet(QString::fromUtf8("border:none;\n"
"image: url(:/image/enterbutton.png);\n"
"font: 75 17pt \"Ubuntu\";\n"
"font:bold;\n"
"border:none;"));
        label->raise();
        ButTwo->raise();
        But6->raise();
        But4->raise();
        But5->raise();
        But7->raise();
        But9->raise();
        ButBack->raise();
        But3->raise();
        ButOne->raise();
        ButEnter->raise();
        But0->raise();
        But8->raise();
        ButEnter_2->raise();

        retranslateUi(intkeypad);

        QMetaObject::connectSlotsByName(intkeypad);
    } // setupUi

    void retranslateUi(QDialog *intkeypad)
    {
        intkeypad->setWindowTitle(QCoreApplication::translate("intkeypad", "Dialog", nullptr));
        But8->setText(QCoreApplication::translate("intkeypad", "8", nullptr));
        But0->setText(QCoreApplication::translate("intkeypad", "0", nullptr));
        ButEnter->setText(QCoreApplication::translate("intkeypad", "1", nullptr));
        label->setText(QString());
        ButTwo->setText(QCoreApplication::translate("intkeypad", "2", nullptr));
        But6->setText(QCoreApplication::translate("intkeypad", "6", nullptr));
        But4->setText(QCoreApplication::translate("intkeypad", "4", nullptr));
        But5->setText(QCoreApplication::translate("intkeypad", "5", nullptr));
        But7->setText(QCoreApplication::translate("intkeypad", "7", nullptr));
        But9->setText(QCoreApplication::translate("intkeypad", "9", nullptr));
        ButBack->setText(QString());
        But3->setText(QCoreApplication::translate("intkeypad", "3", nullptr));
        ButOne->setText(QCoreApplication::translate("intkeypad", "1", nullptr));
        ButEnter_2->setText(QCoreApplication::translate("intkeypad", "1", nullptr));
    } // retranslateUi

};

namespace Ui {
    class intkeypad: public Ui_intkeypad {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTKEYPAD_H
