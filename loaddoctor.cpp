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

    // Set the model for the table view
    ui->tableView->setModel(model);

    // Configure the table view
    ui->tableView->setGeometry(0, 10, 581, 601);  // Set position and size
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);

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

    // Adjust the spacing of the visible columns
    if (idDocColumn != -1) {
        int idColumnWidth = ui->tableView->columnWidth(idDocColumn);
        ui->tableView->setColumnWidth(idDocColumn, idColumnWidth + 250);  // Increase width
    }

    if (nameDocColumn != -1) {
        int nameColumnWidth = ui->tableView->columnWidth(nameDocColumn);
        ui->tableView->setColumnWidth(nameDocColumn, nameColumnWidth + 280);  // Increase width
    }

    // Connect the signal to retrieve the doctorid from the selected row
    connect(ui->tableView->selectionModel(), &QItemSelectionModel::currentRowChanged,
            this, [=](const QModelIndex &current, const QModelIndex &) {
                if (current.isValid()) {
                    selectedRow = current.row();  // Store selected row index
                    selectedID = model->data(model->index(selectedRow, idDocColumn)).toString();
                } else {
                    selectedRow = -1;  // Reset if no row is selected
                }
            });
}


void loaddoctor::loadpatientsql()
{
    ui->tabWidget->setCurrentIndex(1);

    QSqlTableModel *model = new QSqlTableModel(this, mydb1);
    model->setTable("ascanpatient");  // Patient table name
    model->select();

    // Configure the table view
    ui->tableView_2->setModel(model);
    ui->tableView_2->setGeometry(0, 0, 581, 601);

    // Enable row selection
    ui->tableView_2->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView_2->setSelectionBehavior(QAbstractItemView::SelectRows);

    // Hide all columns initially
    for (int col = 0; col < model->columnCount(); ++col) {
        ui->tableView_2->setColumnHidden(col, true);
    }

    // Show relevant columns
    int idPatColumn = model->fieldIndex("id");
    int namePatColumn = model->fieldIndex("name");

    if (idPatColumn != -1) {
        ui->tableView_2->setColumnHidden(idPatColumn, false);
    }
    if (namePatColumn != -1) {
        ui->tableView_2->setColumnHidden(namePatColumn, false);
    }

    // Resize columns
    ui->tableView_2->resizeColumnsToContents();
        ui->tableView_2->resizeColumnsToContents();

        // Adjust the table view's position (move down by 80 pixels)
        QRect geometry = ui->tableView_2->geometry();
        geometry.moveTop(geometry.top() + 10);  // Move the top of the table view down by 80 pixels
        ui->tableView_2->setGeometry(geometry);

        // Adjust the spacing of the visible columns
        if (idPatColumn != -1) {
            int idColumnWidth = ui->tableView_2->columnWidth(idPatColumn);  // Get the current width of the "doctorid" column
            ui->tableView_2->setColumnWidth(idPatColumn, idColumnWidth + 250);  // Add 180 pixels to the width
        }

        if (nameDocColumn != -1) {
            int nameColumnWidth = ui->tableView_2->columnWidth(namePatColumn);  // Get the current width of the "name" column
            ui->tableView_2->setColumnWidth(namePatColumn, nameColumnWidth + 280);  // Add 180 pixels to the width
        }
    // Track row selection
    connect(ui->tableView_2->selectionModel(), &QItemSelectionModel::currentRowChanged,
            this, [=](const QModelIndex &current, const QModelIndex &) {
                if (current.isValid()) {
                    selectedRow = current.row();  // Store selected row index
                    selectedID = model->data(model->index(selectedRow, idPatColumn)).toString();
                } else {
                    selectedRow = -1;  // Reset if no row is selected
                }
            });
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
    if (selectedRow == -1) {
            return;
        }

        // Process the selected row
        qDebug() << "Loading selected row with ID:" << selectedID;

        emit loaddocid(selectedID);
        this->close();  // Close the window after processing

}


void loaddoctor::on_ButPatLoad_clicked()
{
    if (selectedRow == -1) {
            return;
        }

        // Process the selected row
        qDebug() << "Loading selected row with ID:" << selectedID;

        emit loadpatid(selectedID);
        this->close();  // Close the window after processing
}
