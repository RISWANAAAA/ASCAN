#include "textkeypad.h"
#include "ui_textkeypad.h"

textkeypad::textkeypad(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::textkeypad)
{
    ui->setupUi(this);

    QPushButton* buttons[] = {
        ui->But0, ui->ButOne, ui->ButTwo, ui->But3,
        ui->But4, ui->But5, ui->But6, ui->But7,
        ui->But8, ui->But9, ui->ButZ, ui->ButX,
        ui->ButC,ui->ButV,ui->ButB,ui->ButN,ui->ButM,ui->ButA,ui->ButS,
        ui->ButD,ui->ButF,ui->ButF,ui->ButG,ui->ButH,ui->ButJ,ui->ButK,ui->ButL,
        ui->ButQ,ui->ButW,ui->ButE,ui->ButR,ui->ButT,ui->ButY,ui->ButU,ui->ButI,
        ui->ButO,ui->ButP,ui->ButQues,ui->ButDot,ui->Butcomma
    };

    // Connect all numeric buttons to entertext slot
    for (QPushButton* button : buttons) {
        connect(button, &QPushButton::clicked, this, &textkeypad::entertext);
    }

    // Connect special function buttons
    connect(ui->ButBack, &QPushButton::clicked, this, &textkeypad::enterback);
    connect(ui->ButEnter, &QPushButton::clicked, this, &textkeypad::enterenter);
    //connect(ui->ButBackSpace, &QPushButton::clicked, this, &textkeypad::spaceenter);
}

textkeypad::~textkeypad()
{
    delete ui;
}
void textkeypad::entertext()
{
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    if (button)
    {
        QString digit = button->text();
        // Emit the signal to update the text in MainWindow
        emit textsignal(digit);
    }
}

void textkeypad::enterback()
{
    emit backsignal();
}



void textkeypad::enterenter()
{
    emit entersignal();
}

void textkeypad::on_ButUpper_Lower_clicked()
{

}
