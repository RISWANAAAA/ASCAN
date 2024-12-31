#include "loaddoctor.h"
#include "ui_loaddoctor.h"

loaddoctor::loaddoctor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loaddoctor)
{
    ui->setupUi(this);

    Addp=new addPatient;
    addd=new AddDoctor;
    mydb1 = QSqlDatabase::addDatabase("QSQLITE");
     mydb1.setDatabaseName(PATH);  // Replace with your actual path

     if (!mydb1.open()) {
         qDebug() << "Failed to open the database:" << mydb1.lastError().text();
         return;
     }
     connect(addd,&AddDoctor::savedocsql,this,&loaddoctor::loaddoctorsql);
     connect(Addp,&addPatient::saveforload,this,&loaddoctor::loadpatientsql);

     ui->ButDocAdd->hide();
     ui->ButDocDelete->hide();
     ui->ButPatAdd->hide();
     ui->ButPatDelete->hide();
}

loaddoctor::~loaddoctor()
{
    delete ui;
}

void loaddoctor::loaddoctorsql()
{
     ui->tabWidget->setCurrentIndex(0);
    QSqlDatabase db = QSqlDatabase::database();
    QSqlTableModel *model = new QSqlTableModel(this, db);
    model->setTable("ascandoctor");  // Patient table name
    model->select();
  ui->tableView->setGeometry(0,0, 795,696);  // Example position and size
    ui->tableView->setModel(model);
    ui->tableView->resizeColumnsToContents();
    // Adjust position (move down by 20 pixels)
      QRect geometry = ui->tableView->geometry();
      geometry.moveTop(geometry.top() + 5);  // Move the tableView 20 pixels down
      ui->tableView->setGeometry(geometry);
      // Add spacing between columns
        int columnCount = model->columnCount();
        for (int i = 0; i < columnCount; ++i) {
            int currentWidth = ui->tableView->columnWidth(i);
            ui->tableView->setColumnWidth(i, currentWidth + 40); // Add 10 pixels of extra width for spacing
        }
        emit sendpatcurrent();


}

void loaddoctor::loadpatientsql()
{
    ui->tabWidget->setCurrentIndex(1);
    QSqlDatabase db = QSqlDatabase::database();
    QSqlTableModel *model = new QSqlTableModel(this, db);
    model->setTable("ascanpatient");  // Patient table name
    model->select();
  ui->tableView_2->setGeometry(0,0,795,696);  // Example position and size
    ui->tableView_2->setModel(model);
    ui->tableView_2->resizeColumnsToContents();
    // Adjust position (move down by 20 pixels)
      QRect geometry = ui->tableView_2->geometry();
      geometry.moveTop(geometry.top() + 5);  // Move the tableView 20 pixels down
      ui->tableView_2->setGeometry(geometry);
      // Add spacing between columns
        int columnCount = model->columnCount();
        for (int i = 0; i < columnCount; ++i) {
            int currentWidth = ui->tableView_2->columnWidth(i);
            ui->tableView_2->setColumnWidth(i, currentWidth + 60); // Add 10 pixels of extra width for spacing
        }
        emit sendpatcurrent();
}



void loaddoctor::on_ButPatTouch_clicked()
{
    patassistive=!patassistive;
    if(patassistive){
  ui->ButPatAdd->show();
  ui->ButPatDelete->show();

    }else{
        ui->ButPatAdd->hide();
        ui->ButPatDelete->hide();

    }

}

void loaddoctor::on_ButPatAdd_clicked()
{
     Addp->show();
}

void loaddoctor::on_ButDocAdd_clicked()
{
  addd->show();
}

void loaddoctor::on_ButDocTouch_clicked()
{
    docassistive=!docassistive;
    if(docassistive){
  ui->ButDocAdd->show();
  ui->ButDocDelete->show();

    }else{
        ui->ButDocAdd->hide();
        ui->ButDocDelete->hide();

}
}

void loaddoctor::on_pushButton_clicked()
{
    this->close();
}
