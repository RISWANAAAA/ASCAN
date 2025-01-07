#include "adddoctor.h"
#include "ui_adddoctor.h"

AddDoctor::AddDoctor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddDoctor)
{
    ui->setupUi(this);
getlens();
l=new AddLens;
text=new textkeypad;
key=new intkeypad;
    // Open the database connection
    mydb1 = QSqlDatabase::addDatabase("QSQLITE");
    mydb1.setDatabaseName(PATH);  // Replace with your actual database path

    if (!mydb1.open()) {
        qDebug() << "Failed to open the database:" << mydb1.lastError().text();
        return;
    }
    qDebug() << "Database opened successfully.";
    connect(l,&AddLens::tx_insertiol,this,&AddDoctor::getinsertiol);

}

AddDoctor::~AddDoctor()
{
    delete ui;
}

void AddDoctor::getlens()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(PATH);  // Ensure PATH is correctly defined

    if (!db.open()) {
        qWarning() << "Failed to open database:" << db.lastError().text();
        return;
    }

    QSqlQuery query("SELECT IOL FROM ascanlensss");  // Correct table name
    QStringList lensTypes;

    if (query.exec()) {
        while (query.next()) {
            lensTypes << query.value(0).toString();  // Collect lens types
        }

        // Update combo boxes with lens types
        ui->comboBox->clear();
        ui->comboBox_2->clear();
        ui->comboBox_3->clear();

        ui->comboBox->addItems(lensTypes);
        ui->comboBox_2->addItems(lensTypes);
        ui->comboBox_3->addItems(lensTypes);

        qDebug() << "Lens types retrieved from SQL:" << lensTypes;
    } else {
        qWarning() << "Database error:" << query.lastError().text();
    }
}

void AddDoctor::getinsertiol(const QString &text)
{

        qDebug() << text << "those are new inserted IOL////////////////////////////////////";

        // Add the received text to the combo boxes
        ui->comboBox->addItem(text);
        ui->comboBox_2->addItem(text);
        ui->comboBox_3->addItem(text);


}


void AddDoctor::doctoreditdetails(const QString &id, const QString &name, const QString &lens1, const QString &lens2, const QString &lens3, const QString &formula)
{
    ui->linedocid->setText(id);
    ui->linedocname->setText(name);
    ui->comboBox->setCurrentText(lens1);
    ui->comboBox_2->setCurrentText(lens2);
    ui->comboBox_3->setCurrentText(lens3);
    ui->comboBox_4->setCurrentText(formula);
}

void AddDoctor::on_ButDocBack_clicked()
{
    this->close();
}





void AddDoctor::on_ButDocSave_clicked()
{
    QString docid=ui->linedocid->text();
    QString docname=ui->linedocname->text();
    QString lens1=ui->comboBox->currentText();
    QString lens2=ui->comboBox_2->currentText();
    QString lens3=ui->comboBox_3->currentText();
    QString formula=ui->comboBox_4->currentText();
    QSqlQuery query;

    // Check if record exists
    query.prepare("SELECT COUNT(*) FROM ascandoctor WHERE Doctorid = :id");
    query.bindValue(":id", docid);
    if (!query.exec()) {
        qDebug() << "Failed to execute record existence check:" << query.lastError().text();
        return;
    }

    bool recordExists = false;
    if (query.next()) {
        if (query.value(0).toInt() > 0) {
            recordExists = true;  // ID exists
        }
    } else {
        qDebug() << "Failed to fetch record existence result:" << query.lastError().text();
        return;
    }

    // Save to database
    if (recordExists) {
        // Update existing record
        query.prepare("UPDATE ascandoctor SET Name = :name, "
                      "Lens1 = :lens1, Lens2 = :lens2, Lens3 = :lens3, "
                      "Formula = :formula "
                      "WHERE Doctorid = :id");
    } else {
        // Add new record
        query.prepare("INSERT INTO ascandoctor (Doctorid, Name, Lens1, Lens2, Lens3, Formula) "
                      "VALUES (:id, :name, :lens1, :lens2, :lens3, :formula)");
    }

    // Bind values to query
    query.bindValue(":id", docid);
    query.bindValue(":name", docname);
    query.bindValue(":lens1", lens1);
    query.bindValue(":lens2", lens2);
    query.bindValue(":lens3", lens3);
    query.bindValue(":formula", formula);

    if (!query.exec()) {
        qDebug() << "Failed to execute query:" << query.lastError().text();
    } else {
        if (recordExists) {
            qDebug() << "Record updated successfully for ID:" << docid;
             emit updatedocsql();
        } else {
            qDebug() << "New record added successfully with ID:" << docid;
            emit lastupdatedocid_buttons(docid,docname);
emit savedocsql();
        }
    }

}
