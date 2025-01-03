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
    connect(load,&loaddoctor::loaddocid,this,&currentDocPat::loadcurrentdoctorid);
    connect(ui->tabWidget, &QTabWidget::currentChanged, this, &currentDocPat::onTabChanged);
      onTabChanged(0);
    mydb1 = QSqlDatabase::addDatabase("QSQLITE");
     mydb1.setDatabaseName(PATH);  // Replace with your actual path
     if (!mydb1.open()) {
         qDebug() << "Failed to open the database:" << mydb1.lastError().text();
         return;
     }

     ui->tabWidget->setCurrentIndex(0);
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
  qDebug()<<id<<"the id is reterved from the button<<>><<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<";
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

void currentDocPat::loadcurrentdoctorid(const QString &id)
{
    ui->lbldocidvalue->setText(id);
    qDebug()<<"the id"<<id;
      QSqlQuery query(mydb1);

      query.prepare("SELECT Doctorid, Name, Lens1, Lens2, Lens3, Formula FROM ascandoctor WHERE Doctorid = :id");
      query.bindValue(":id", id);

      if (!query.exec()) {
          qDebug() << "Error executing query:" << query.lastError().text();
          return;
      }

      if (query.next()) {
          QString lastDoctorID = query.value(0).toString();
          QString lastDoctorName = query.value(1).toString();
          QString Lens1 = query.value(2).toString();
          QString Lens2 = query.value(3).toString();
          QString Lens3 = query.value(4).toString();
          QString Formula = query.value(5).toString();

  ui->ButDocSql->setText(lastDoctorName);
  ui->lbldocformulaValue->setText(Formula);
  //ui->lineEdit_9->setText()
  ui->tabWidget->setTabText(0,Lens1);
  ui->tabWidget->setTabText(1,Lens2);
  ui->tabWidget->setTabText(2,Lens3);
  onTabChanged(0);
  //        currentpatient(lastPatientID, lastPatientName, keratoL1, keratoL2, keratoL, keratoR1, keratoR2, keratoR);
          QSettings settings("YourCompany", "YourApp");
          settings.setValue("lastLoadedPatientID", lastDoctorID);
  //            emit sendpatientidmain(lastPatientID);
             // emit tx_patdocnameid_main(lastPatientID,lastPatientName);
             emit tx_docidname_button(lastDoctorID,lastDoctorName);
          //qDebug()<<"values are sended to mainwindow id......................................"<<lastPatientID;
      }

          mydb1.close();

}

void currentDocPat::onTabChanged(int index) {
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(PATH);  // Ensure PATH is correctly defined

    if (!db.open()) {
        qWarning() << "Failed to open database:" << db.lastError().text();
        return;
    }
qDebug()<<"the current indec of tabwidget"<<index<<"...................................................";
    // Get the current tab's name (the lens name)
    QString lensName = ui->tabWidget->tabText(index);
    qDebug() << "Lens Name:" << lensName;

    // Perform the SQL query to retrieve values for the selected lens
    QSqlQuery query(db);
    query.prepare("SELECT ASRKT, ASRKII, ACD, SF, a0, a1, a2 FROM ascanlensss WHERE IOL = :lensname");
    query.bindValue(":lensname", lensName);
    qDebug() << "Executing query:" << query.executedQuery();

    if (query.exec()) {
        if (query.next()) {
            // Update the line edits with the fetched data
            ui->lineasrkt->setText(query.value(0).toString());
            ui->lineasrkii->setText(query.value(1).toString());
            ui->lineacd->setText(query.value(2).toString());
            ui->linesf->setText(query.value(3).toString());
            ui->linea0->setText(query.value(4).toString());
            ui->linea1->setText(query.value(5).toString());
            ui->linea2->setText(query.value(6).toString());
        } else {
            // Handle case where no data is found
            qDebug() << "No data found for lens: " << lensName;
        }
    } else {
        // Handle SQL query error
        qDebug() << "Error fetching lens data: " << query.lastError().text();
    }
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

void currentDocPat::on_Butok_clicked()
{
    this->close();
}
