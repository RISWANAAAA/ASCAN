#include "addpatient.h"
#include "ui_addpatient.h"

addPatient::addPatient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addPatient)
{
    ui->setupUi(this);
    key=new intkeypad;
    text=new textkeypad;
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
    connect(key,&intkeypad::textsignal,this,&addPatient::on_clicked);

    connect(key,&intkeypad::entersignal,this,&addPatient::on_clickedenter);
         connect(key,&intkeypad::backsignal,this,&addPatient::on_clickedenter);
       connect(key,&intkeypad::clearsignal,this,&addPatient::handleClearSignal);
       connect(text,&textkeypad::textsignal,this,&addPatient::on_clicked);
      connect(text,&textkeypad::entersignal,this,&addPatient::on_clickedenter);
 connect(text,&textkeypad::backsignal,this,&addPatient::handleClearSignal);
 connect(text,&textkeypad::spacesignal,this,&addPatient::spaceclicked);

    ui->linepatid->installEventFilter(this);
    ui->linepatname->installEventFilter(this);
    ui->linepatage->installEventFilter(this);
    ui->linepatphone->installEventFilter(this);
    ui->linepatkr->installEventFilter(this);
    ui->linepatkr1->installEventFilter(this);
    ui->linepatkr2->installEventFilter(this);
    ui->linepatkl->installEventFilter(this);
    ui->linepatkl1->installEventFilter(this);
    ui->linepatkl2->installEventFilter(this);

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

bool addPatient::eventFilter(QObject *object, QEvent *event)
{
    if(object == ui->linepatid && event->type() == QEvent::MouseButtonPress) {
      QMouseEvent *k = static_cast<QMouseEvent *> (event);
      if( k->button() == Qt::LeftButton ) {

//          key->resize(321,271);
//          key->move(280,320);
          key->show();
          ui->linepatid->setFocus();
          ui->linepatname->clearFocus();
          ui->linepatage->clearFocus();
          ui->linepatphone->clearFocus();
          ui->linepatkl1->clearFocus();
          ui->linepatkl2->clearFocus();
          ui->linepatkl->clearFocus();
          ui->linepatkr->clearFocus();
          ui->linepatkr1->clearFocus();
          ui->linepatkr2->clearFocus();
          ui->linepatid->setText("");

      } else if ( k->button() == Qt::RightButton ) {
      }
}
    else if(object == ui->linepatname && event->type() == QEvent::MouseButtonPress) {
      QMouseEvent *k = static_cast<QMouseEvent *> (event);
      if( k->button() == Qt::LeftButton ) {
             text->show();
          ui->linepatname->setFocus();
          ui->linepatid->clearFocus();
          ui->linepatage->clearFocus();
          ui->linepatphone->clearFocus();
          ui->linepatkl1->clearFocus();
          ui->linepatkl2->clearFocus();
          ui->linepatkl->clearFocus();
          ui->linepatkr->clearFocus();
          ui->linepatkr1->clearFocus();
          ui->linepatkr2->clearFocus();
          ui->linepatname->setText("");

      } else if ( k->button() == Qt::RightButton ) {
      }
}
    else if(object == ui->linepatage && event->type() == QEvent::MouseButtonPress) {
      QMouseEvent *k = static_cast<QMouseEvent *> (event);
      if( k->button() == Qt::LeftButton ) {
  key->show();
          ui->linepatage->setFocus();
          ui->linepatid->clearFocus();
          ui->linepatname->clearFocus();
          ui->linepatphone->clearFocus();
          ui->linepatkl1->clearFocus();
          ui->linepatkl2->clearFocus();
          ui->linepatkl->clearFocus();
          ui->linepatkr->clearFocus();
          ui->linepatkr1->clearFocus();
          ui->linepatkr2->clearFocus();
          ui->linepatage->setText("");

      } else if ( k->button() == Qt::RightButton ) {
      }
}
    else if(object == ui->linepatphone && event->type() == QEvent::MouseButtonPress) {
      QMouseEvent *k = static_cast<QMouseEvent *> (event);
      if( k->button() == Qt::LeftButton ) {
          key->show();
          ui->linepatphone->setFocus();
          ui->linepatid->clearFocus();
          ui->linepatage->clearFocus();
          ui->linepatname->clearFocus();
          ui->linepatkl1->clearFocus();
          ui->linepatkl2->clearFocus();
          ui->linepatkl->clearFocus();
          ui->linepatkr->clearFocus();
          ui->linepatkr1->clearFocus();
          ui->linepatkr2->clearFocus();
          ui->linepatphone->setText("");

      } else if ( k->button() == Qt::RightButton ) {
      }
}
    else if(object == ui->linepatkl1 && event->type() == QEvent::MouseButtonPress) {
      QMouseEvent *k = static_cast<QMouseEvent *> (event);
      if( k->button() == Qt::LeftButton ) {
  key->show();
          ui->linepatkl1->setFocus();
          ui->linepatid->clearFocus();
          ui->linepatage->clearFocus();
          ui->linepatphone->clearFocus();
          ui->linepatname->clearFocus();
          ui->linepatkl2->clearFocus();
          ui->linepatkl->clearFocus();
          ui->linepatkr->clearFocus();
          ui->linepatkr1->clearFocus();
          ui->linepatkr2->clearFocus();
          ui->linepatkl1->setText("");

      } else if ( k->button() == Qt::RightButton ) {
      }
}
    else if(object == ui->linepatkl2 && event->type() == QEvent::MouseButtonPress) {
      QMouseEvent *k = static_cast<QMouseEvent *> (event);
      if( k->button() == Qt::LeftButton ) {
  key->show();
          ui->linepatkl2->setFocus();
          ui->linepatid->clearFocus();
          ui->linepatage->clearFocus();
          ui->linepatphone->clearFocus();
          ui->linepatkl1->clearFocus();
          ui->linepatname->clearFocus();
          ui->linepatkl->clearFocus();
          ui->linepatkr->clearFocus();
          ui->linepatkr1->clearFocus();
          ui->linepatkr2->clearFocus();
          ui->linepatkl2->setText("");

      } else if ( k->button() == Qt::RightButton ) {
      }
}
    else if(object == ui->linepatkl && event->type() == QEvent::MouseButtonPress) {
      QMouseEvent *k = static_cast<QMouseEvent *> (event);
      if( k->button() == Qt::LeftButton ) {
  key->show();
          ui->linepatkl->setFocus();
          ui->linepatid->clearFocus();
          ui->linepatage->clearFocus();
          ui->linepatphone->clearFocus();
          ui->linepatkl1->clearFocus();
          ui->linepatkl2->clearFocus();
          ui->linepatname->clearFocus();
          ui->linepatkr->clearFocus();
          ui->linepatkr1->clearFocus();
          ui->linepatkr2->clearFocus();
          ui->linepatkl->setText("");

      } else if ( k->button() == Qt::RightButton ) {
      }
}
    else if(object == ui->linepatkr1 && event->type() == QEvent::MouseButtonPress) {
      QMouseEvent *k = static_cast<QMouseEvent *> (event);
      if( k->button() == Qt::LeftButton ) {
  key->show();
          ui->linepatkr1->setFocus();
          ui->linepatid->clearFocus();
          ui->linepatage->clearFocus();
          ui->linepatphone->clearFocus();
          ui->linepatkl1->clearFocus();
          ui->linepatkl2->clearFocus();
          ui->linepatname->clearFocus();
          ui->linepatkr->clearFocus();
          ui->linepatkl->clearFocus();
          ui->linepatkr2->clearFocus();
          ui->linepatkr1->setText("");

      } else if ( k->button() == Qt::RightButton ) {
      }
}
    else if(object == ui->linepatkr2 && event->type() == QEvent::MouseButtonPress) {
      QMouseEvent *k = static_cast<QMouseEvent *> (event);
      if( k->button() == Qt::LeftButton ) {
  key->show();
          ui->linepatkr2->setFocus();
          ui->linepatid->clearFocus();
          ui->linepatage->clearFocus();
          ui->linepatphone->clearFocus();
          ui->linepatkl1->clearFocus();
          ui->linepatkl2->clearFocus();
          ui->linepatname->clearFocus();
          ui->linepatkr->clearFocus();
          ui->linepatkr1->clearFocus();
          ui->linepatkl->clearFocus();
          ui->linepatkr2->setText("");

      } else if ( k->button() == Qt::RightButton ) {
      }
    }
      else if(object == ui->linepatkr && event->type() == QEvent::MouseButtonPress) {
        QMouseEvent *k = static_cast<QMouseEvent *> (event);
        if( k->button() == Qt::LeftButton ) {
  key->show();
            ui->linepatkr->setFocus();
            ui->linepatid->clearFocus();
            ui->linepatage->clearFocus();
            ui->linepatphone->clearFocus();
            ui->linepatkl1->clearFocus();
            ui->linepatkl2->clearFocus();
            ui->linepatname->clearFocus();
            ui->linepatkr2->clearFocus();
            ui->linepatkr1->clearFocus();
            ui->linepatkl->clearFocus();
            ui->linepatkr->setText("");

        } else if ( k->button() == Qt::RightButton ) {
        }
}
    else if(object == ui->linepatkl && event->type() == QEvent::MouseButtonPress) {
      QMouseEvent *k = static_cast<QMouseEvent *> (event);
      if( k->button() == Qt::LeftButton ) {
            key->show();
          ui->linepatkl->setFocus();
          ui->linepatid->clearFocus();
          ui->linepatage->clearFocus();
          ui->linepatphone->clearFocus();
          ui->linepatkl1->clearFocus();
          ui->linepatkl2->clearFocus();
          ui->linepatname->clearFocus();
          ui->linepatkr->clearFocus();
          ui->linepatkr1->clearFocus();
          ui->linepatkr2->clearFocus();
          ui->linepatkl->setText("");

      } else if ( k->button() == Qt::RightButton ) {
      }
}
    return  false;

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
        return;
    }

    bool recordExists = false;
    if (query.next()) {
        if (query.value(0).toInt() > 0) {
            recordExists = true;  // ID exists
        }
    } else {
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
    } else {
        if (recordExists) {
            emit updatepatsql();

        } else {
            emit savepatsql();
            emit saveforload();
            emit savepatid_name(id,Name);

        }
    }

}

void addPatient::on_clicked(const QString &digit)
{
    if (ui->linepatid->focusWidget()) {

        ui->linepatage->clearFocus();
        ui->linepatphone->clearFocus();
        ui->linepatkl->clearFocus();
        ui->linepatkl1->clearFocus();
        ui->linepatkl2->clearFocus();
        ui->linepatkr->clearFocus();
        ui->linepatkr2->clearFocus();
        ui->linepatkr1->clearFocus();


        // Append digit to the current text and update lineEdit_3
        QString text = ui->linepatid->text();

        ui->linepatid->setText(text+digit);
       // on_enterbackclicked(ui->linepatid);
    }
    if (ui->linepatname->focusWidget()) {

        ui->linepatage->clearFocus();
        ui->linepatphone->clearFocus();
        ui->linepatkl->clearFocus();
        ui->linepatkl1->clearFocus();
        ui->linepatkl2->clearFocus();
        ui->linepatkr->clearFocus();
        ui->linepatkr2->clearFocus();
        ui->linepatkr1->clearFocus();
        ui->linepatid->clearFocus();



        // Append digit to the current text and update lineEdit_3
        QString text = ui->linepatname->text();

        ui->linepatname->setText(text+digit);
       // on_enterbackclicked(ui->linepatid);
    }
    if (ui->linepatage->focusWidget()) {

        ui->linepatid->clearFocus();
        ui->linepatphone->clearFocus();
        ui->linepatkl->clearFocus();
        ui->linepatkl1->clearFocus();
        ui->linepatkl2->clearFocus();
        ui->linepatkr->clearFocus();
        ui->linepatkr2->clearFocus();
        ui->linepatkr1->clearFocus();


        // Append digit to the current text and update lineEdit_3
        QString text = ui->linepatage->text();

        ui->linepatage->setText(text+digit);
    }
    if (ui->linepatphone->focusWidget()) {

        ui->linepatage->clearFocus();
        ui->linepatid->clearFocus();
        ui->linepatkl->clearFocus();
        ui->linepatkl1->clearFocus();
        ui->linepatkl2->clearFocus();
        ui->linepatkr->clearFocus();
        ui->linepatkr2->clearFocus();
        ui->linepatkr1->clearFocus();


        // Append digit to the current text and update lineEdit_3
        QString text = ui->linepatphone->text();

        ui->linepatphone->setText(text+digit);
    }
    if (ui->linepatkl1->focusWidget()) {

        ui->linepatage->clearFocus();
        ui->linepatphone->clearFocus();
        ui->linepatkl->clearFocus();
        ui->linepatid->clearFocus();
        ui->linepatkl2->clearFocus();
        ui->linepatkr->clearFocus();
        ui->linepatkr2->clearFocus();
        ui->linepatkr1->clearFocus();


        // Append digit to the current text and update lineEdit_3
        QString text = ui->linepatkl1->text();

        ui->linepatkl1->setText(text+digit);
    }
    if (ui->linepatkl2->focusWidget()) {

        ui->linepatage->clearFocus();
        ui->linepatphone->clearFocus();
        ui->linepatkl->clearFocus();
        ui->linepatkl1->clearFocus();
        ui->linepatid->clearFocus();
        ui->linepatkr->clearFocus();
        ui->linepatkr2->clearFocus();
        ui->linepatkr1->clearFocus();


        // Append digit to the current text and update lineEdit_3
        QString text = ui->linepatkl2->text();

        ui->linepatkl2->setText(text+digit);
    }
    if (ui->linepatkl->focusWidget()) {

        ui->linepatage->clearFocus();
        ui->linepatphone->clearFocus();
        ui->linepatid->clearFocus();
        ui->linepatkl1->clearFocus();
        ui->linepatkl2->clearFocus();
        ui->linepatkr->clearFocus();
        ui->linepatkr2->clearFocus();
        ui->linepatkr1->clearFocus();


        // Append digit to the current text and update lineEdit_3
        QString text = ui->linepatkl->text();

        ui->linepatkl->setText(text+digit);
    }
    if (ui->linepatkr->focusWidget()) {

        ui->linepatage->clearFocus();
        ui->linepatphone->clearFocus();
        ui->linepatkl->clearFocus();
        ui->linepatkl1->clearFocus();
        ui->linepatkl2->clearFocus();
        ui->linepatid->clearFocus();
        ui->linepatkr2->clearFocus();
        ui->linepatkr1->clearFocus();


        // Append digit to the current text and update lineEdit_3
        QString text = ui->linepatkr->text();

        ui->linepatkr->setText(text+digit);
    }
    if (ui->linepatkr1->focusWidget()) {

        ui->linepatage->clearFocus();
        ui->linepatphone->clearFocus();
        ui->linepatkl->clearFocus();
        ui->linepatkl1->clearFocus();
        ui->linepatkl2->clearFocus();
        ui->linepatkr->clearFocus();
        ui->linepatkr2->clearFocus();
        ui->linepatid->clearFocus();


        // Append digit to the current text and update lineEdit_3
        QString text = ui->linepatkr1->text();

        ui->linepatkr1->setText(text+digit);
    }
    if (ui->linepatkr->focusWidget()) {

        ui->linepatage->clearFocus();
        ui->linepatphone->clearFocus();
        ui->linepatkl->clearFocus();
        ui->linepatkl1->clearFocus();
        ui->linepatkl2->clearFocus();
        ui->linepatid->clearFocus();
        ui->linepatkr2->clearFocus();
        ui->linepatkr1->clearFocus();


        // Append digit to the current text and update lineEdit_3
        QString text = ui->linepatkr->text();

        ui->linepatkr->setText(text+digit);
    }
}

void addPatient::on_clickedenter()
{
    key->hide();
    text->hide();
    QList<QLineEdit*> lineEdits1 = {
        ui->linepatid, ui->linepatage,
        ui->linepatphone, ui->linepatkr, ui->linepatkr1, ui->linepatkr2,
         ui->linepatkl, ui->linepatkl1, ui->linepatkl2
    };
    QList<QLineEdit*> lineEdits2 = {
        ui->linepatname
    };
    for (QLineEdit* lineEdit2 : lineEdits2) {
        QString currentText2 = lineEdit2->text().trimmed();

        if (!currentText2.isEmpty()) {
            // For string inputs, simply trim and store the text
            lineEdit2->setText(currentText2);
            lastValidValues1[lineEdit2] = currentText2;  // Store the last valid string
        } else {
            // Restore the last valid string if input is empty
            if (lastValidValues1.contains(lineEdit2)) {
                lineEdit2->setText(lastValidValues1[lineEdit2]);
            }
        }
    }
    for (QLineEdit* lineEdit1 : lineEdits1) {
        QString currentText1 = lineEdit1->text().trimmed();

        if (!currentText1.isEmpty()) {
            int input1 = currentText1.toInt();
           // int output1 = decreasebutton(input1);  // Process the input to get the desired output
            lineEdit1->setText(QString::number(input1));
            lastValidValues[lineEdit1] = input1;  // Update the last valid value
        } else {
            // Restore the last valid value if input is empty
            if (lastValidValues.contains(lineEdit1)) {
                lineEdit1->setText(QString::number(lastValidValues[lineEdit1]));
            }
        }
    }

}

void addPatient::spaceclicked()
{
    ui->linepatname->setText(ui->linepatname->text() + " ");  // Append a space to the QLineEdit

}


void addPatient::handleClearSignal()
{
    if (ui->linepatid->focusWidget()) {


        QString text = ui->linepatid->text();

               // Chop the last character if text is not empty
               if (!text.isEmpty()) {
                   text.chop(1);
                 ui->linepatid->setText(text);
               }
    }
    else if (ui->linepatname->focusWidget()) {


        QString text = ui->linepatname->text();

               // Chop the last character if text is not empty
               if (!text.isEmpty()) {
                   text.chop(1);
                 ui->linepatname->setText(text);
               }
    }
    else if (ui->linepatage->focusWidget()) {


        QString text = ui->linepatage->text();

               // Chop the last character if text is not empty
               if (!text.isEmpty()) {
                   text.chop(1);
                 ui->linepatage->setText(text);
               }
    }
    else if (ui->linepatkl1->focusWidget()) {


        QString text = ui->linepatkl1->text();

               // Chop the last character if text is not empty
               if (!text.isEmpty()) {
                   text.chop(1);
                 ui->linepatkl1->setText(text);
               }
    }
    else if (ui->linepatkl2->focusWidget()) {


        QString text = ui->linepatkl2->text();

               // Chop the last character if text is not empty
               if (!text.isEmpty()) {
                   text.chop(1);
                 ui->linepatkl2->setText(text);
               }
    }
    else if (ui->linepatkl->focusWidget()) {


        QString text = ui->linepatkl->text();

               // Chop the last character if text is not empty
               if (!text.isEmpty()) {
                   text.chop(1);
                 ui->linepatkl->setText(text);
               }
    }
    else if (ui->linepatkr->focusWidget()) {


        QString text = ui->linepatkr->text();

               // Chop the last character if text is not empty
               if (!text.isEmpty()) {
                   text.chop(1);
                 ui->linepatkr->setText(text);
               }
    }
    else if (ui->linepatkr1->focusWidget()) {


        QString text = ui->linepatkr1->text();

               // Chop the last character if text is not empty
               if (!text.isEmpty()) {
                   text.chop(1);
                 ui->linepatkr1->setText(text);
               }
    }
    else if (ui->linepatkr2->focusWidget()) {


        QString text = ui->linepatkr2->text();

               // Chop the last character if text is not empty
               if (!text.isEmpty()) {
                   text.chop(1);
                 ui->linepatkr2->setText(text);
               }
    }
    else if (ui->linepatkr->focusWidget()) {


        QString text = ui->linepatkr->text();

               // Chop the last character if text is not empty
               if (!text.isEmpty()) {
                   text.chop(1);
                 ui->linepatkr->setText(text);
               }
    }
}


