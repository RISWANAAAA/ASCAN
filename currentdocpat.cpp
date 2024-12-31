#include "currentdocpat.h"
#include "ui_currentdocpat.h"

currentDocPat::currentDocPat(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::currentDocPat)
{
    ui->setupUi(this);
    load=new loaddoctor;
    connect(this,&currentDocPat::loadpatsqldatabase,load,&loaddoctor::loadpatientsql);
    connect(this,&currentDocPat::loaddocsqldatabase,load,&loaddoctor::loaddoctorsql);
    connect(load,&loaddoctor::sendpatcurrent,this,&currentDocPat::rx_fromloaddoc);
    mydb1 = QSqlDatabase::addDatabase("QSQLITE");
     mydb1.setDatabaseName(PATH);  // Replace with your actual path

     if (!mydb1.open()) {
         qDebug() << "Failed to open the database:" << mydb1.lastError().text();
         return;
     }
}

currentDocPat::~currentDocPat()
{
    delete ui;
}

void currentDocPat::rx_fromloaddoc()
{
    emit tx_main();
}

void currentDocPat::loadlastpatient()
{



}

void currentDocPat::on_ButDocSql_clicked()
{
  load->show();
  emit loaddocsqldatabase();
}

void currentDocPat::on_ButPatSql_clicked()
{
  load->show();
  emit loadpatsqldatabase();
}
