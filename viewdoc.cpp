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
