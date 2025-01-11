#include "intkeypad.h"
#include "ui_intkeypad.h"

intkeypad::intkeypad(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::intkeypad)
{
    ui->setupUi(this);
    QPushButton* buttons[] = {
        ui->But0, ui->ButOne, ui->ButTwo, ui->But3,
        ui->But4, ui->But5, ui->But6, ui->But7,
        ui->But8, ui->But9
    };

    // Connect all numeric buttons to entertext slot
    for (QPushButton* button : buttons) {
        connect(button, &QPushButton::clicked, this, &intkeypad::entertext);
    }

    // Array of buttons for enterenter
    QPushButton* enterButtons[] = {
    ui->ButEnter

    };

    // Connect all enter buttons to enterenter slot
    for (QPushButton* button : enterButtons) {
        connect(button, &QPushButton::clicked, this, &intkeypad::enterenter);
    }
    connect(ui->ButBack,&QPushButton::clicked,this,&intkeypad::enterback);
}

intkeypad::~intkeypad()
{
    delete ui;
}

void intkeypad::entertext()
{
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    if (button) {
        QString digit = button->text();
        emit textsignal(digit);
    }
}

void intkeypad::enterenter()
{
    emit entersignal();

}

void intkeypad::enterback()
{
    emit backsignal();

}

void intkeypad::on_ButEnter_2_clicked()
{
   emit clearsignal();
}
