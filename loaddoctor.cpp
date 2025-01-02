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
    model->setTable("ascandoctor");  // Doctor table name
    model->select();
    ui->tableView->setGeometry(0, 0, 581, 601);  // Example position and size

    // Set the model for the table view
    ui->tableView->setModel(model);

    // Hide all columns initially
    for (int col = 0; col < model->columnCount(); ++col) {
        ui->tableView->setColumnHidden(col, true);
    }

    // Column names as strings
    QString idDocColumnName = "doctorid";
    QString nameDocColumnName = "name";

    // Get the indices of the columns using their names
    int idDocColumn = model->fieldIndex(idDocColumnName);
    int nameDocColumn = model->fieldIndex(nameDocColumnName);

    // Check if the columns exist and make them visible
    if (idDocColumn != -1) {
        ui->tableView->setColumnHidden(idDocColumn, false);
    }

    if (nameDocColumn != -1) {
        ui->tableView->setColumnHidden(nameDocColumn, false);
    }

    // Resize the columns to fit their content
    ui->tableView->resizeColumnsToContents();

    // Adjust the table view's position (move down by 80 pixels)
    QRect geometry = ui->tableView->geometry();
    geometry.moveTop(geometry.top() + 80);  // Move the top of the table view down by 80 pixels
    ui->tableView->setGeometry(geometry);

    // Adjust the spacing of the visible columns
    if (idDocColumn != -1) {
        int idColumnWidth = ui->tableView->columnWidth(idDocColumn);  // Get the current width of the "doctorid" column
        ui->tableView->setColumnWidth(idDocColumn, idColumnWidth + 180);  // Add 180 pixels to the width
    }

    if (nameDocColumn != -1) {
        int nameColumnWidth = ui->tableView->columnWidth(nameDocColumn);  // Get the current width of the "name" column
        ui->tableView->setColumnWidth(nameDocColumn, nameColumnWidth + 180);  // Add 180 pixels to the width
    }

    // Connect the signal to retrieve the doctorid from the selected row
    connect(ui->tableView, &QTableView::clicked, this, [=](const QModelIndex &index) {
        if (idDocColumn != -1) {
            QString doctorid = model->data(model->index(index.row(), idDocColumn)).toString();
            qDebug() << "Selected Doctor ID:" << doctorid;
idDocColumn1=doctorid;
        }
    });

    emit sendpatcurrent();
}


void loaddoctor::loadpatientsql()
{
    ui->tabWidget->setCurrentIndex(1);


    QSqlTableModel *model = new QSqlTableModel(this, mydb1);
    model->setTable("ascanpatient");  // Patient table name
    model->select();

    // Configure the table view
    ui->tableView_2->setModel(model);

    // Hide all columns initially
    for (int col = 0; col < model->columnCount(); ++col) {
        ui->tableView_2->setColumnHidden(col, true);
    }

    // Show only specific columns (e.g., "id" and "name")
    QString idPatColumnName = "id";          // Column name for ID
    QString namePatColumnName = "name";      // Column name for Name
    int idPatColumn = model->fieldIndex(idPatColumnName);
    int namePatColumn = model->fieldIndex(namePatColumnName);

    if (idPatColumn != -1) {
        ui->tableView_2->setColumnHidden(idPatColumn, false);
    }

    if (namePatColumn != -1) {
        ui->tableView_2->setColumnHidden(namePatColumn, false);
    }

    ui->tableView_2->resizeColumnsToContents();

    // Connect the signal to retrieve the ID from the selected row
    connect(ui->tableView_2, &QTableView::clicked, this, [=](const QModelIndex &index) {
        if (idPatColumn != -1) {
            QString id = model->data(model->index(index.row(), idPatColumn)).toString();
            qDebug() << "Selected ID:" << id;
         idPatColumn1=id;
         emit loadpatid(idPatColumn1);
this->close();
        }
    });

    // Emit signal to indicate data is loaded
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

void loaddoctor::on_ButDocLoad_clicked()
{

   emit loaddocid(idDocColumn1);


}


void loaddoctor::on_ButPatLoad_clicked()
{

}
