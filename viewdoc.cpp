#include "viewdoc.h"
#include "ui_viewdoc.h"

viewdoc::viewdoc(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::viewdoc)
{
    ui->setupUi(this);
}

viewdoc::~viewdoc()
{
    delete ui;
}

void viewdoc::viewdocdetails(const QString &id, const QString &name, const QString &lens1, const QString &lens2, const QString &lens3, const QString &formula)
{
    ui->linedocid->setText(id);
    ui->linedocname->setText(name);
    ui->linedocpre1->setText(lens1);
    ui->linedocpre2->setText(lens2);
    ui->linedocpre3->setText(lens3);
    ui->linedocformula->setText(formula);
}

void viewdoc::on_BUTOK_clicked()
{
    this->close();
}
