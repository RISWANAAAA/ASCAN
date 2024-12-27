#include "adddoctor.h"
#include "ui_adddoctor.h"

AddDoctor::AddDoctor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddDoctor)
{
    ui->setupUi(this);
}

AddDoctor::~AddDoctor()
{
    delete ui;
}
