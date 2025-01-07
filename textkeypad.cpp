#include "textkeypad.h"
#include "ui_textkeypad.h"

textkeypad::textkeypad(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::textkeypad)
{
    ui->setupUi(this);

    // Connect all number and character buttons
    for (int i = 1; i <= 41; ++i) {
        QPushButton *button = findChild<QPushButton *>(QString("pushButton_%1").arg(i));
        if (button) {
            connect(button, &QPushButton::clicked, this, &textkeypad::entertext);
        }
    }

    // Connect special function buttons
    connect(ui->ButBack, &QPushButton::clicked, this, &textkeypad::enterback);
    connect(ui->ButEnter, &QPushButton::clicked, this, &textkeypad::enterenter);
    connect(ui->ButBackSpace, &QPushButton::clicked, this, &textkeypad::spaceenter);
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

void textkeypad::spaceenter()
{
    emit spacesignal();
}

void textkeypad::enterenter()
{
    emit entersignal();
}

void textkeypad::on_ButUpper_Lower_clicked()
{
    // Toggle the mode
    isLowercaseMode = !isLowercaseMode;

    // Update the text of number and character buttons based on the current mode
    for (int i = 1; i <= 41; ++i) {
        QPushButton *button = findChild<QPushButton *>(QString("pushButton_%1").arg(i));
        if (button) {
            QString currentText = button->text();
            if (isLowercaseMode) {
                button->setText(currentText.toLower()); // Convert to lowercase
            } else {
                button->setText(currentText.toUpper()); // Convert to uppercase
            }
        }
    }
}
