#include "addlens.h"
#include "ui_addlens.h"

AddLens::AddLens(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddLens)
{
    ui->setupUi(this);
}

AddLens::~AddLens()
{
    delete ui;
}

void AddLens::on_ButLensBack_clicked()
{
    this->close();
}
