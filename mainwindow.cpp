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
     connect(this,&MainWindow::sendpatientid,but,&Buttons::rx_patidname);

     connect(ui->comboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, [this](int index) {
         if (index != -1) {
             // Get the patient ID stored in the user data for the selected index
             QString patientID = ui->comboBox->itemData(index).toString();

             // Save the patient ID to QSettings
             QSettings settings("YourCompanyName", "YourAppName");
             settings.setValue("lastSelectedPatientID", patientID);

             // Debugging: Show the saved patient ID in the output
             qDebug() << "Saved last selected patient ID:" << patientID;

             emit sendpatientid(patientID,name);
             QString selectedID = ui->comboBox->currentData().toString(); // ID from user data
             QString selectedText = ui->comboBox->currentText();          // Display text (e.g., "6_riswana")

             // Extract the name from the display text
             QStringList parts = selectedText.split("_");
             QString selectedName = parts.size() > 1 ? parts[1] : "";

             saveSelectedPatient(selectedID, selectedName);
             qDebug() << "Sent selected patient ID:" << patientID;
         }
     });
   connect(addp,&addPatient::savepatid_name,this,&MainWindow::updateComboBox);
   connect(this,&MainWindow::sendpatientsql,but,&Buttons::loadpatientsql);
   //connect(ui->comboBox, &QComboBox::currentIndexChanged, this, &MainWindow::onComboBoxSelectionChanged);

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::select_patient()
{
    qDebug() << "Loading patients into combo box...";
    QSqlDatabase db = QSqlDatabase::database("myConnection");

    if (!db.isOpen()) {
        qDebug() << "Database is not open.";
        return;
    }

    QSqlQuery query(db);
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
    }

    QSettings settings("YourCompanyName", "YourAppName");
    QString lastSelectedPatientID = settings.value("lastSelectedPatientID", "").toString();
    QString lastSelectedPatientName = settings.value("lastSelectedPatientName", "").toString();

    qDebug() << "Last selected Patient ID:" << lastSelectedPatientID;
    qDebug() << "Last selected Patient Name:" << lastSelectedPatientName;
emit sendpatientid(lastSelectedPatientID,lastSelectedPatientName);
    if (!lastSelectedPatientID.isEmpty()) {
        int index = comboBox->findData(lastSelectedPatientID); // Find ID in combo box
        if (index != -1) {
            comboBox->setCurrentIndex(index);

            // Retrieve and emit both ID and name
            QString selectedID = comboBox->currentData().toString(); // ID from user data
            QString selectedText = comboBox->currentText();          // Display text (e.g., "6_riswana")
            QStringList parts = selectedText.split("_");
            QString selectedName = parts.size() > 1 ? parts[1] : "";

            emit sendpatientid(selectedID,selectedText);
            qDebug() << "Selected Patient ID:" << selectedID;
            qDebug() << "Selected Patient Name:" << selectedName;
        } else {
            qDebug() << "Last selected Patient ID not found in combo box.";
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
