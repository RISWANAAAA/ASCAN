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
    connect(load,&loaddoctor::loadpatid,this,&currentDocPat::loadcurrentpatientid);

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

void currentDocPat::loadcurrentpatientid(const QString &id)
{
  ui->lblpatidvalue->setText(id);
    QSqlQuery query(mydb1);

    query.prepare("SELECT ID, Name, KeratoL1, KeratoL2, KeratoL, KeratoR1, KeratoR2, KeratoR FROM ascanpatient WHERE ID = :id");
    query.bindValue(":id", id);

    if (!query.exec()) {
        qDebug() << "Error executing query:" << query.lastError().text();
        return;
    }

    if (query.next()) {
        QString lastPatientID = query.value(0).toString();
        QString lastPatientName = query.value(1).toString();
        QString keratoL1 = query.value(2).toString();
        QString keratoL2 = query.value(3).toString();
        QString keratoL = query.value(4).toString();
        QString keratoR1 = query.value(5).toString();
        QString keratoR2 = query.value(6).toString();
        QString keratoR = query.value(7).toString();
ui->ButPatSql->setText(lastPatientName);
ui->linelk->setText(keratoL);
ui->linelk1->setText(keratoL1);
ui->linelk2->setText(keratoL2);
ui->linerk->setText(keratoR);
ui->linerk1->setText(keratoR1);
ui->linerk2->setText(keratoR2);


//        currentpatient(lastPatientID, lastPatientName, keratoL1, keratoL2, keratoL, keratoR1, keratoR2, keratoR);
        QSettings settings("YourCompany", "YourApp");
        settings.setValue("lastLoadedPatientID", lastPatientID);
//            emit sendpatientidmain(lastPatientID);
            emit tx_patdocnameid_main(lastPatientID,lastPatientName);

        qDebug()<<"values are sended to mainwindow id......................................"<<lastPatientID;
    }

        mydb1.close();

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
