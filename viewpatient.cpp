#include "viewpatient.h"
#include "ui_viewpatient.h"

viewpatient::viewpatient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::viewpatient)
{
    ui->setupUi(this);
}

viewpatient::~viewpatient()
{
    delete ui;
}

void viewpatient::viewPatdata(const QString &id, const QString &name, const QString &age, const QString &gender, const QString &number, const QString &opmethod, const QString &opmode, const QString &eye)
{
    ui->linepatid->setText(id);
    ui->linepatname->setText(name);
    ui->linepatage->setText(age);
    ui->linepatgender->setText(gender);
    ui->linepatphone->setText(number);
    ui->linepatopmethod->setText(opmethod);
    ui->linepatopmode->setText(opmode);
    ui->linepatopeye->setText(eye);
}


void viewpatient::on_ButOk_clicked()
{
    this->close();
}
