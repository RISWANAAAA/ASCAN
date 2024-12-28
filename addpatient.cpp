#include "addpatient.h"
#include "ui_addpatient.h"

addPatient::addPatient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addPatient)
{
    ui->setupUi(this);
    mydb1 = QSqlDatabase::addDatabase("QSQLITE");
       mydb1.setDatabaseName("your_database_path_here");  // Replace with your actual database path
       if (!mydb1.open()) {
           qDebug() << "Failed to open the database:" << mydb1.lastError().text();
           return;
       }

    connect(ui->CheckMale, &QCheckBox::toggled, this, [this]() {
        if (ui->CheckMale->isChecked()) {
            ui->CheckFemale->setChecked(false);
            ui->CheckOther->setChecked(false);
        }
    });

    connect(ui->CheckFemale, &QCheckBox::toggled, this, [this]() {
        if (ui->CheckFemale->isChecked()) {
            ui->CheckMale->setChecked(false);
            ui->CheckOther->setChecked(false);
        }
    });

    connect(ui->CheckOther, &QCheckBox::toggled, this, [this]() {
        if (ui->CheckOther->isChecked()) {
            ui->CheckMale->setChecked(false);
            ui->CheckFemale->setChecked(false);
        }
    });

    // Group 1: Method
    connect(ui->CheckApakic, &QCheckBox::toggled, this, [this]() {
        if (ui->CheckApakic->isChecked()) {
            ui->CheckPhakic->setChecked(false);
            ui->CheckDense->setChecked(false);
        }
    });

    connect(ui->CheckPhakic, &QCheckBox::toggled, this, [this]() {
        if (ui->CheckPhakic->isChecked()) {
            ui->CheckApakic->setChecked(false);
            ui->CheckDense->setChecked(false);
        }
    });

    connect(ui->CheckDense, &QCheckBox::toggled, this, [this]() {
        if (ui->CheckDense->isChecked()) {
            ui->CheckApakic->setChecked(false);
            ui->CheckPhakic->setChecked(false);
        }
    });

    // Group 2: Mode
    connect(ui->CheckContact, &QCheckBox::toggled, this, [this]() {
        if (ui->CheckContact->isChecked()) {
            ui->CheckImmersion->setChecked(false);
        }
    });

    connect(ui->CheckImmersion, &QCheckBox::toggled, this, [this]() {
        if (ui->CheckImmersion->isChecked()) {
            ui->CheckContact->setChecked(false);
        }
    });

    // Group 3: Eye
    connect(ui->CheckLeft, &QCheckBox::toggled, this, [this]() {
        if (ui->CheckLeft->isChecked()) {
            ui->CheckRight->setChecked(false);
        }
    });

    connect(ui->CheckRight, &QCheckBox::toggled, this, [this]() {
        if (ui->CheckRight->isChecked()) {
            ui->CheckLeft->setChecked(false);
        }
    });

}

addPatient::~addPatient()
{
    delete ui;
}

void addPatient::on_ButPatBack_clicked()
{
    this->close();
}
void addPatient::setpatientDetails(const QString &id, const QString &name, const QString &age, const QString &gender,const QString &number,const QString &method,const QString &mode,const QString &eye,const QString &keratol1,QString keratol2,const QString &keratol,const QString kerator1,const QString kerator2,const QString kerator)
{
    // Set text in QLineEdit widgets
    ui->linepatid->setText(id);  // Set the ID for editing
    ui->linepatname->setText(name);
    ui->linepatage->setText(age);
    ui->linepatphone->setText(number);
    ui->linepatkl1->setText(keratol1);
    ui->linepatkl2->setText(keratol2);
    ui->linepatkl->setText(keratol);
    ui->linepatkr1->setText(kerator1);
    ui->linepatkr2->setText(kerator2);
    ui->linepatkr->setText(kerator);

    // Set text for QCheckBox widgets based on their state
    ui->CheckMale->setChecked(gender == "Male");
    ui->CheckFemale->setChecked(gender == "Female");
    ui->CheckOther->setChecked(gender == "Other");

    ui->CheckApakic->setChecked(method == "Aphakic");
    ui->CheckPhakic->setChecked(method == "Phakic");
    ui->CheckDense->setChecked(method == "Dense");

    ui->CheckContact->setChecked(mode == "Contact");
    ui->CheckImmersion->setChecked(mode == "Immerse");

    ui->CheckLeft->setChecked(eye == "Left");
    ui->CheckRight->setChecked(eye == "Right");

}
void addPatient::on_ButPatSave_clicked()
{
    QString id=ui->linepatid->text();
    QString Name=ui->linepatname->text();
    QString age=ui->linepatage->text();
    QString phone=ui->linepatphone->text();
    QString keratol1=ui->linepatkl1->text();
    QString keratol2=ui->linepatkl2->text();
    QString keratol=ui->linepatkl->text();
    QString kerator1=ui->linepatkr1->text();
    QString kerator2=ui->linepatkr2->text();
    QString kerator=ui->linepatkr->text();
    QString gender;
    if (ui->CheckMale->isChecked()) {
        gender = "Male";

    } else if (ui->CheckFemale->isChecked()) {
        gender = "Female";

    } else if(ui->CheckOther->isChecked()) {
        gender = "Other"; // Default or handle as needed

    }else{
        gender = "";
    }


    // Determine method

    // Determine mode
    QString method;
    if (ui->CheckApakic->isChecked()) {
        method = "Aphakic";
    } else if (ui->CheckPhakic->isChecked()) {
        method = "Phakic";
    } else if (ui->CheckDense->isChecked()) {
        method = "Dense";
    } else {
        method = "";
    }

    QString mode;
    if (ui->CheckContact->isChecked()) {
        mode = "Contact";
    } else if (ui->CheckImmersion->isChecked()) {
        mode = "Immerse";
    } else {
        mode = "";
    }

    QString eye;
    if (ui->CheckLeft->isChecked()) {
        eye = "Left";
    } else if (ui->CheckRight->isChecked()) {
        eye = "Right";
    } else {
        eye = "";
    }

    QSqlQuery query;

    // Check if record exists
    query.prepare("SELECT COUNT(*) FROM ascanpatient WHERE ID = :id");
    query.bindValue(":id", id);
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
        query.prepare("UPDATE ascanpatient SET Name = :name, Age = :age, Phone = :number, Gender = :gender, "
                      "Operating_method = :method, Operating_mode = :mode, Operating_eye = :eye, "
                      "KeratoL1 = :keratol1, KeratoL2 = :keratol2, KeratoL = :keratol, "
                      "KeratoR1 = :kerator1, KeratoR2 = :kerator2, KeratoR = :kerator "
                      "WHERE ID = :id");
    } else {
        // Add new record
        query.prepare("INSERT INTO ascanpatient (ID, Name, Age, Phone, Gender, Operating_method, Operating_mode, Operating_eye, "
                      "KeratoL1, KeratoL2, KeratoL, KeratoR1, KeratoR2, KeratoR) "
                      "VALUES (:id, :name, :age, :number, :gender, :method, :mode, :eye, "
                      ":keratol1, :keratol2, :keratol, :kerator1, :kerator2, :kerator)");
    }

    // Bind values to query
    query.bindValue(":id", id);
    query.bindValue(":name", Name);
    query.bindValue(":age", age);
    query.bindValue(":number", phone);
    query.bindValue(":gender", gender);
    query.bindValue(":method", method);
    query.bindValue(":mode", mode);
    query.bindValue(":eye", eye);
    query.bindValue(":keratol1", keratol1);
    query.bindValue(":keratol2", keratol2);
    query.bindValue(":keratol", keratol);
    query.bindValue(":kerator1", kerator1);
    query.bindValue(":kerator2", kerator2);
    query.bindValue(":kerator", kerator);

    if (!query.exec()) {
        qDebug() << "Failed to execute query:" << query.lastError().text();
    } else {
        if (recordExists) {
            qDebug() << "Record updated successfully for ID:" << id;
            emit updatepatsql();

        } else {
            qDebug() << "New record added successfully with ID:" << id;
            emit savepatsql();

        }
    }

}
