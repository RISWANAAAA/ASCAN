#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    but=new Buttons;
    addp=new addPatient;
    move(0,0);
    mydb1 = QSqlDatabase::addDatabase("QSQLITE");
     mydb1.setDatabaseName(PATH);  // Replace with your actual path

     if (!mydb1.open()) {
         qDebug() << "Failed to open the database:" << mydb1.lastError().text();
         return;
     }
     loadlastpatient();
     //select_patient();

     connect(ui->comboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, [this](int index) {
         if (index != -1) {
             // Get the patient ID stored in the user data for the selected index
             QString patientID = ui->comboBox->itemData(index).toString();

             // Extract the display text from the combo box
             QString selectedText = ui->comboBox->currentText(); // Display text (e.g., "6_riswana")

             // Extract the name from the display text
             QStringList parts = selectedText.split("_");
             QString selectedName = parts.size() > 1 ? parts[1] : ""; // Extract the name after "_"

             // Save the patient ID and name to QSettings
             QSettings settings("YourCompanyName", "YourAppName");
             settings.setValue("lastSelectedPatientID", patientID);
             settings.setValue("lastSelectedPatientName", selectedName);

             // Save the selected patient details using a helper function
             saveSelectedPatient(patientID, selectedName);
             emit sendpatientid(patientID, selectedName);

             // Debugging: Log the sent patient ID
             qDebug() << "Sent selected patient ID:" << patientID;

         }
     });

   connect(addp,&addPatient::savepatid_name,this,&MainWindow::updateComboBox);
   connect(this,&MainWindow::sendpatientsql,but,&Buttons::loadpatientsql);
   // In MainWindow constructor or initialization
   connect(this, SIGNAL(sendpatientid(QString, QString)),
           but, SLOT(rx_patidname(QString, QString)));
   connect(this,&MainWindow::emitpatientidname,but,&Buttons::rx_patidname);
   //connect(ui->comboBox, &QComboBox::currentIndexChanged, this, &MainWindow::onComboBoxSelectionChanged);
  emit emitpatientidname(lastSelectedPatientID,lastSelectedPatientName);
connect(but,&Buttons::tx_currentpatdoc_main,this,&MainWindow::onPatientSelected);

//connect(but, SIGNAL(tx_currentpatdoc_main(QString, QString)),
//        this, SLOT(updateComboBox1(QString, QString)));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::onPatientSelected(const QString &id) {
    qDebug() << "Received new ID:" << id;

      // Query the database to get the new patient name
      QSqlQuery query;
      query.prepare("SELECT Name FROM ascanpatient WHERE ID = :id");
      query.bindValue(":id", id);

      if (query.exec() && query.next()) {
          QString patientName = query.value(0).toString();
          QString updatedName = id + "_" + patientName;



          // Update the combo box
          bool found = false;
          for (int i = 0; i < ui->comboBox->count(); ++i) {
              if (ui->comboBox->itemData(i).toString() == id) {
                  found = true;
                  ui->comboBox->setItemText(i, updatedName); // Update the displayed name
                  ui->comboBox->setCurrentIndex(i); // Optionally set the current index
                  break;
              }
          }

          // If not found, you can choose to add the new item
          if (!found) {
              ui->comboBox->setCurrentText(updatedName); // Set the current text
          }
      } else {
          qDebug() << "Error fetching patient name:" << query.lastError().text();
      }
}


void MainWindow::select_patient()
{

    QSqlQuery query(mydb1);
    if (!query.exec("SELECT ID, Name FROM ascanpatient")) {
        return;
    }

    QComboBox *comboBox = ui->comboBox;
    if (!comboBox) {
        qDebug() << "ComboBox is null.";
        return;
    }

    comboBox->clear();

    while (query.next()) {
        QString id = query.value(0).toString();
        QString name = query.value(1).toString();
        QString itemText = QString("%1_%2").arg(id).arg(name);
        comboBox->addItem(itemText, id);  // Store ID as user data
        emit sendpatientid(id,name);
    }


}
void MainWindow::saveSelectedPatient(const QString &id, const QString &name)
{
    QSettings settings("YourCompanyName", "YourAppName");
    settings.setValue("lastSelectedPatientID", id);
    settings.setValue("lastSelectedPatientName", name); // Save the name
    qDebug() << "Saved Patient ID:" << id;
    qDebug() << "Saved Patient Name:" << name;
}
void MainWindow::onComboBoxSelectionChanged()
{

}
void MainWindow::loadlastpatient()
{
    QSqlQuery query(mydb1);
    if (!query.exec("SELECT ID, Name FROM ascanpatient")) {
        qDebug() << "Database query failed:" << query.lastError().text();
        return;
    }

    QComboBox *comboBox = ui->comboBox;
    if (!comboBox) {
        qDebug() << "ComboBox not found in UI.";
        return;
    }

    comboBox->clear();

    while (query.next()) {
        QString id = query.value(0).toString();
        QString name = query.value(1).toString();
        QString itemText = QString("%1_%2").arg(id).arg(name);
        comboBox->addItem(itemText, id); // ID as user data
      //  emit sendpatientid(id, name); // Emit ID and Name while adding to combo box
    }

    // Load the last selected patient ID and Name from settings
    QSettings settings("YourCompanyName", "YourAppName");
  lastSelectedPatientID = settings.value("lastSelectedPatientID", "").toString();
  lastSelectedPatientName = settings.value("lastSelectedPatientName", "").toString();
    qDebug() << "The last selected patient ID and name:" << lastSelectedPatientID << ".............."<<"last"<<"............................" << lastSelectedPatientName;

    // Ensure comboBox_2 and comboBox_3 have the correct values
    if (!lastSelectedPatientID.isEmpty() && !lastSelectedPatientName.isEmpty()) {
        // Format the ID_Name string for matching
        QString formattedText = QString("%1_%2").arg(lastSelectedPatientID).arg(lastSelectedPatientName);


        // Find and set the last selected patient ID and Name in the main combo box
        int index = comboBox->findText(formattedText); // Look for the ID_Name format
        if (index != -1) {
            comboBox->setCurrentIndex(index); // Set the current index based on the formatted text
            qDebug() << "The patient ID and Name have been selected: " << formattedText;

            // Emit the selected patient ID and name
            //emit sendpatientid(lastSelectedPatientID, lastSelectedPatientName);
        } else {
            qDebug() << "Formatted patient text not found in combo box.";
        }
    }
}




void MainWindow::updateComboBox(const QString id, const QString &name)
{
    // Assuming you want to add the new patient to the existing items
    QString itemText = QString("%1 - %2").arg(id).arg(name);
    ui->comboBox->addItem(itemText, id);
   ui->comboBox->setCurrentText(itemText);
  emit sendpatientsql();



}

void MainWindow::updateComboBox1(const QString id, const QString &name)
{
    // Assuming you want to add the new patient to the existing items
    QString itemText = QString("%1 - %2").arg(id).arg(name);
    ui->comboBox->addItem(itemText, id);
   ui->comboBox->setCurrentText(itemText);
  emit sendpatientsql();
   qDebug()<<"the value will be "<<id<<name;



}
void MainWindow::on_pushButton_clicked()
{
    but->show();

}

void MainWindow::on_pushButton_2_clicked()
{
    addp->show();
}

void MainWindow::on_pushButton_3_clicked()
{

}
