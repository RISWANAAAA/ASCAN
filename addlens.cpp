#include "addlens.h"
#include "ui_addlens.h"

AddLens::AddLens(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddLens)
{
    ui->setupUi(this);
    mydb1 = QSqlDatabase::addDatabase("QSQLITE");
       mydb1.setDatabaseName("your_database_path_here");  // Replace with your actual database path
       if (!mydb1.open()) {
           qDebug() << "Failed to open the database:" << mydb1.lastError().text();
           return;
       }

}

AddLens::~AddLens()
{
    delete ui;
}

void AddLens::editlensdetails(const QString &iol, const QString &type, const QString &asrkt, const QString &asrkii, const QString &acd, const QString &sf, const QString &a0, const QString &a1, const QString &a2)
{
    ui->lineiol->setText(iol);
    ui->comboBox->setCurrentText(type);
    ui->lineASRKT->setText(asrkt);
    ui->lineASRKII->setText(asrkii);
    ui->lineSF->setText(sf);
    ui->lineACD->setText(acd);
    ui->linea0->setText(a0);
    ui->linea1->setText(a1);
    ui->linea2->setText(a2);
}

void AddLens::on_ButLensBack_clicked()
{
    this->close();
}

void AddLens::on_ButLensSave_clicked()
{
    QString iol=ui->lineiol->text();
    QString type=ui->comboBox->currentText();
    QString ASRKT=ui->lineASRKT->text();
    QString ASRKII=ui->lineASRKII->text();
    QString ACD=ui->lineACD->text();
    QString SF=ui->lineSF->text();
    QString a0=ui->linea0->text();
    QString a1=ui->linea1->text();
    QString a2=ui->linea2->text();


    QSqlQuery query;

    // Check if record exists
    query.prepare("SELECT COUNT(*) FROM ascanlens WHERE IOL = :iol");
    query.bindValue(":iol", iol);
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
        query.prepare("UPDATE ascanlens SET Type = :type, "
                      "ASRKT = :ASRKT, ASRKII = :ASRKII, ACD = :ACD, SF = :SF, a0 = :a0, a1 = :a1, a2 = :a2 "
                      "WHERE IOL = :iol");
    } else {
        // Add new record
        query.prepare("INSERT INTO ascanlens (IOL, Type, ASRKT, ASRKII, ACD, SF, a0, a1, a2) "
                      "VALUES (:iol, :type, :ASRKT, :ASRKII, :ACD, :SF, :a0, :a1, :a2)");
    }

    // Bind values to query
    query.bindValue(":iol", iol);
    query.bindValue(":type", type);
    query.bindValue(":ASRKT", ASRKT);
    query.bindValue(":ASRKII", ASRKII);
    query.bindValue(":ACD", ACD);
    query.bindValue(":SF", SF);
    query.bindValue(":a0", a0);
    query.bindValue(":a1", a1);
    query.bindValue(":a2", a2);


    if (!query.exec()) {
        qDebug() << "Failed to execute query:" << query.lastError().text();
    } else {
        if (recordExists) {
            qDebug() << "Record updated successfully for ID:" << iol;
            emit updatelenssql();

        } else {
            qDebug() << "New record added successfully with ID:" << iol;
            emit savelenssql();

        }
    }

}
