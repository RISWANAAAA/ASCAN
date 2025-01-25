#include "addlens.h"
#include "ui_addlens.h"

AddLens::AddLens(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddLens)
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
       ui->lineiol->installEventFilter(this);
       ui->lineASRKT->installEventFilter(this);
       ui->lineASRKII->installEventFilter(this);
       ui->lineACD->installEventFilter(this);
       ui->lineSF->installEventFilter(this);
       ui->linea0->installEventFilter(this);
       ui->linea1->installEventFilter(this);
       ui->linea2->installEventFilter(this);
       connect(key,&intkeypad::entersignal,this,&AddLens::on_clickedenter);
            connect(key,&intkeypad::backsignal,this,&AddLens::on_clickedenter);
          connect(key,&intkeypad::clearsignal,this,&AddLens::handleClearSignal);
          connect(text,&textkeypad::textsignal,this,&AddLens::on_clicked);
         connect(text,&textkeypad::entersignal,this,&AddLens::on_clickedenter);
    connect(text,&textkeypad::backsignal,this,&AddLens::handleClearSignal);
    connect(text,&textkeypad::spacesignal,this,&AddLens::spaceclicked);

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

bool AddLens::eventFilter(QObject *object, QEvent *event)
{
    if(object == ui->lineiol && event->type() == QEvent::MouseButtonPress) {
      QMouseEvent *k = static_cast<QMouseEvent *> (event);
      if( k->button() == Qt::LeftButton ) {
   text->show();
//          key->resize(321,271);
//          key->move(280,320);
          ui->lineiol->setFocus();
          ui->lineASRKT->clearFocus();
          ui->lineASRKII->clearFocus();
          ui->lineACD->clearFocus();
          ui->lineSF->clearFocus();
          ui->linea1->clearFocus();
          ui->linea2->clearFocus();
          ui->linea0->clearFocus();

          ui->lineiol->setText("");

      } else if ( k->button() == Qt::RightButton ) {
      }
}
    if(object == ui->lineASRKT&& event->type() == QEvent::MouseButtonPress) {
      QMouseEvent *k = static_cast<QMouseEvent *> (event);
      if( k->button() == Qt::LeftButton ) {

//          key->resize(321,271);
//          key->move(280,320);
          key->show();
          ui->lineASRKT->setFocus();
          ui->lineiol->clearFocus();
          ui->lineASRKII->clearFocus();
          ui->lineACD->clearFocus();
          ui->lineSF->clearFocus();
          ui->linea1->clearFocus();
          ui->linea2->clearFocus();
          ui->linea0->clearFocus();

          ui->lineASRKT->setText("");

      } else if ( k->button() == Qt::RightButton ) {
      }
}
    if(object == ui->lineASRKII && event->type() == QEvent::MouseButtonPress) {
      QMouseEvent *k = static_cast<QMouseEvent *> (event);
      if( k->button() == Qt::LeftButton ) {

//          key->resize(321,271);
//          key->move(280,320);
          key->show();
          ui->lineASRKII->setFocus();
          ui->lineASRKT->clearFocus();
          ui->lineiol->clearFocus();
          ui->lineACD->clearFocus();
          ui->lineSF->clearFocus();
          ui->linea1->clearFocus();
          ui->linea2->clearFocus();
          ui->linea0->clearFocus();

          ui->lineASRKII->setText("");

      } else if ( k->button() == Qt::RightButton ) {
      }
}
    if(object == ui->lineACD && event->type() == QEvent::MouseButtonPress) {
      QMouseEvent *k = static_cast<QMouseEvent *> (event);
      if( k->button() == Qt::LeftButton ) {

//          key->resize(321,271);
//          key->move(280,320);
          key->show();
          ui->lineACD->setFocus();
          ui->lineASRKT->clearFocus();
          ui->lineASRKII->clearFocus();
          ui->lineiol->clearFocus();
          ui->lineSF->clearFocus();
          ui->linea1->clearFocus();
          ui->linea2->clearFocus();
          ui->linea0->clearFocus();

          ui->lineACD->setText("");

      } else if ( k->button() == Qt::RightButton ) {
      }
}
    if(object == ui->lineSF && event->type() == QEvent::MouseButtonPress) {
      QMouseEvent *k = static_cast<QMouseEvent *> (event);
      if( k->button() == Qt::LeftButton ) {

//          key->resize(321,271);
//          key->move(280,320);
          key->show();
          ui->lineSF->setFocus();
          ui->lineASRKT->clearFocus();
          ui->lineASRKII->clearFocus();
          ui->lineACD->clearFocus();
          ui->lineiol->clearFocus();
          ui->linea1->clearFocus();
          ui->linea2->clearFocus();
          ui->linea0->clearFocus();

          ui->lineSF->setText("");

      } else if ( k->button() == Qt::RightButton ) {
      }
}
    if(object == ui->linea0 && event->type() == QEvent::MouseButtonPress) {
      QMouseEvent *k = static_cast<QMouseEvent *> (event);
      if( k->button() == Qt::LeftButton ) {

//          key->resize(321,271);
//          key->move(280,320);
          key->show();
          ui->linea0->setFocus();
          ui->lineASRKT->clearFocus();
          ui->lineASRKII->clearFocus();
          ui->lineACD->clearFocus();
          ui->lineSF->clearFocus();
          ui->linea1->clearFocus();
          ui->linea2->clearFocus();
          ui->lineiol->clearFocus();

          ui->linea0->setText("");

      } else if ( k->button() == Qt::RightButton ) {
      }
}
    if(object == ui->linea1 && event->type() == QEvent::MouseButtonPress) {
      QMouseEvent *k = static_cast<QMouseEvent *> (event);
      if( k->button() == Qt::LeftButton ) {

//          key->resize(321,271);
//          key->move(280,320);
          key->show();
          ui->linea1->setFocus();
          ui->lineASRKT->clearFocus();
          ui->lineASRKII->clearFocus();
          ui->lineACD->clearFocus();
          ui->lineSF->clearFocus();
          ui->linea0->clearFocus();
          ui->linea2->clearFocus();
          ui->lineiol->clearFocus();

          ui->linea1->setText("");

      } else if ( k->button() == Qt::RightButton ) {
      }
}
    if(object == ui->linea2 && event->type() == QEvent::MouseButtonPress) {
      QMouseEvent *k = static_cast<QMouseEvent *> (event);
      if( k->button() == Qt::LeftButton ) {

//          key->resize(321,271);
//          key->move(280,320);
          key->show();
          ui->linea2->setFocus();
          ui->lineASRKT->clearFocus();
          ui->lineASRKII->clearFocus();
          ui->lineACD->clearFocus();
          ui->lineSF->clearFocus();
          ui->linea1->clearFocus();
          ui->linea0->clearFocus();
          ui->lineiol->clearFocus();

          ui->linea2->setText("");

      } else if ( k->button() == Qt::RightButton ) {
      }
}
    return false;
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
    query.prepare("SELECT COUNT(*) FROM ascanlensss WHERE IOL = :iol");
    query.bindValue(":iol", iol);
    if (!query.exec()) {
        return;
    }

    bool recordExists = false;
    if (query.next()) {
        if (query.value(0).toInt() > 0) {
            recordExists = true;  // ID exists
        }
    }

    // Save to database
    if (recordExists) {
        // Update existing record
        query.prepare("UPDATE ascanlensss SET Type = :type, "
                      "ASRKT = :ASRKT, ASRKII = :ASRKII, ACD = :ACD, SF = :SF, a0 = :a0, a1 = :a1, a2 = :a2 "
                      "WHERE IOL = :iol");
    } else {
        // Add new record
        query.prepare("INSERT INTO ascanlensss (IOL, Type, ASRKT, ASRKII, ACD, SF, a0, a1, a2) "
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
    } else {
        if (recordExists) {
            emit updatelenssql();

        } else {
            emit savelenssql();
            emit tx_insertiol(iol);

        }
    }
    // Close the database connection
      QSqlDatabase::database().close();

}

void AddLens::on_clicked(const QString &digit)
{

    if (ui->lineiol->focusWidget()) {

        ui->lineASRKT->clearFocus();
        ui->lineASRKII->clearFocus();
        ui->lineACD->clearFocus();
        ui->lineSF->clearFocus();
        ui->linea0->clearFocus();
        ui->linea1->clearFocus();
        ui->linea2->clearFocus();
        // Append digit to the current text and update lineEdit_3
        QString text = ui->lineiol->text();

        ui->lineiol->setText(text+digit);
       // on_enterbackclicked(ui->linepatid);
    }
    if (ui->lineASRKT->focusWidget()) {

        ui->lineiol->clearFocus();
        ui->lineASRKII->clearFocus();
        ui->lineACD->clearFocus();
        ui->lineSF->clearFocus();
        ui->linea0->clearFocus();
        ui->linea1->clearFocus();
        ui->linea2->clearFocus();
        // Append digit to the current text and update lineEdit_3
        QString text = ui->lineASRKT->text();

        ui->lineASRKT->setText(text+digit);
       // on_enterbackclicked(ui->linepatid);
    }
    if (ui->lineASRKII->focusWidget()) {

        ui->lineASRKT->clearFocus();
        ui->lineiol->clearFocus();
        ui->lineACD->clearFocus();
        ui->lineSF->clearFocus();
        ui->linea0->clearFocus();
        ui->linea1->clearFocus();
        ui->linea2->clearFocus();
        // Append digit to the current text and update lineEdit_3
        QString text = ui->lineASRKII->text();

        ui->lineASRKII->setText(text+digit);
       // on_enterbackclicked(ui->linepatid);
    }
    if (ui->lineACD->focusWidget()) {

        ui->lineASRKT->clearFocus();
        ui->lineASRKII->clearFocus();
        ui->lineiol->clearFocus();
        ui->lineSF->clearFocus();
        ui->linea0->clearFocus();
        ui->linea1->clearFocus();
        ui->linea2->clearFocus();
        // Append digit to the current text and update lineEdit_3
        QString text = ui->lineACD->text();

        ui->lineACD->setText(text+digit);
       // on_enterbackclicked(ui->linepatid);
    }
    if (ui->lineSF->focusWidget()) {

        ui->lineASRKT->clearFocus();
        ui->lineASRKII->clearFocus();
        ui->lineACD->clearFocus();
        ui->lineiol->clearFocus();
        ui->linea0->clearFocus();
        ui->linea1->clearFocus();
        ui->linea2->clearFocus();
        // Append digit to the current text and update lineEdit_3
        QString text = ui->lineSF->text();

        ui->lineSF->setText(text+digit);
       // on_enterbackclicked(ui->linepatid);
    }
    if (ui->linea0->focusWidget()) {

        ui->lineASRKT->clearFocus();
        ui->lineASRKII->clearFocus();
        ui->lineACD->clearFocus();
        ui->lineSF->clearFocus();
        ui->lineiol->clearFocus();
        ui->linea1->clearFocus();
        ui->linea2->clearFocus();
        // Append digit to the current text and update lineEdit_3
        QString text = ui->linea0->text();

        ui->linea0->setText(text+digit);
       // on_enterbackclicked(ui->linepatid);
    }
    if (ui->linea1->focusWidget()) {

        ui->lineASRKT->clearFocus();
        ui->lineASRKII->clearFocus();
        ui->lineACD->clearFocus();
        ui->lineSF->clearFocus();
        ui->linea0->clearFocus();
        ui->lineiol->clearFocus();
        ui->linea2->clearFocus();
        // Append digit to the current text and update lineEdit_3
        QString text = ui->linea1->text();

        ui->linea1->setText(text+digit);
       // on_enterbackclicked(ui->linepatid);
    }
    if (ui->linea2->focusWidget()) {

        ui->lineASRKT->clearFocus();
        ui->lineASRKII->clearFocus();
        ui->lineACD->clearFocus();
        ui->lineSF->clearFocus();
        ui->linea0->clearFocus();
        ui->linea1->clearFocus();
        ui->lineiol->clearFocus();
        // Append digit to the current text and update lineEdit_3
        QString text = ui->linea2->text();

        ui->linea2->setText(text+digit);
       // on_enterbackclicked(ui->linepatid);
    }

}

void AddLens::on_clickedenter()
{
    key->hide();
    text->hide();
    QList<QLineEdit*> lineEdits1 = {
        ui->lineASRKT, ui->lineASRKII,
        ui->lineACD, ui->lineSF, ui->linea0, ui->linea1,
         ui->linea2
    };
    QList<QLineEdit*> lineEdits2 = {
        ui->lineiol
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

void AddLens::spaceclicked()
{
    ui->lineiol->setText(ui->lineiol->text() + " ");  // Append a space to the QLineEdit

}

void AddLens::handleClearSignal()
{
    if (ui->lineiol->focusWidget()) {


        QString text = ui->lineiol->text();

               // Chop the last character if text is not empty
               if (!text.isEmpty()) {
                   text.chop(1);
                 ui->lineiol->setText(text);
               }
    }
    if (ui->lineASRKT->focusWidget()) {


        QString text = ui->lineASRKT->text();

               // Chop the last character if text is not empty
               if (!text.isEmpty()) {
                   text.chop(1);
                 ui->lineASRKT->setText(text);
               }
    }
    if (ui->lineASRKII->focusWidget()) {


        QString text = ui->lineASRKII->text();

               // Chop the last character if text is not empty
               if (!text.isEmpty()) {
                   text.chop(1);
                 ui->lineASRKII->setText(text);
               }
    }
    if (ui->lineACD->focusWidget()) {


        QString text = ui->lineACD->text();

               // Chop the last character if text is not empty
               if (!text.isEmpty()) {
                   text.chop(1);
                 ui->lineACD->setText(text);
               }
    }
    if (ui->lineSF->focusWidget()) {


        QString text = ui->lineSF->text();

               // Chop the last character if text is not empty
               if (!text.isEmpty()) {
                   text.chop(1);
                 ui->lineSF->setText(text);
               }
    }
    if (ui->linea0->focusWidget()) {


        QString text = ui->linea0->text();

               // Chop the last character if text is not empty
               if (!text.isEmpty()) {
                   text.chop(1);
                 ui->linea0->setText(text);
               }
    }
    if (ui->linea1->focusWidget()) {


        QString text = ui->linea1->text();

               // Chop the last character if text is not empty
               if (!text.isEmpty()) {
                   text.chop(1);
                 ui->linea1->setText(text);
               }
    }
    if (ui->linea2->focusWidget()) {


        QString text = ui->linea2->text();

               // Chop the last character if text is not empty
               if (!text.isEmpty()) {
                   text.chop(1);
                 ui->linea2->setText(text);
               }
    }
}
