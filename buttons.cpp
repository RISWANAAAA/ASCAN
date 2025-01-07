#include "buttons.h"
#include "ui_buttons.h"
#include <QDebug>
#include<QVBoxLayout>
#include<QPushButton>
Buttons::Buttons(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Buttons),
    currentButtonIndex(0),
    swipeDirection(0)
{
    ui->setupUi(this);
    move(0, 0);
    lens=new AddLens;
    doc=new AddDoctor;
    pat=new addPatient;
    viewd=new viewdoc;
    viewp=new viewpatient;
    Current=new currentDocPat;
    formula=new CalFormula;
   mydb1 = QSqlDatabase::addDatabase("QSQLITE");
    mydb1.setDatabaseName(PATH);  // Replace with your actual path

    if (!mydb1.open()) {
        qDebug() << "Failed to open the database:" << mydb1.lastError().text();
        return;
    }

    // Initialize buttons
    buttons[0] = ui->ButPatient;
    buttons[1] = ui->ButDoctor;
    buttons[2] = ui->ButLens;
    buttons[3] = ui->ButMeasure;
    buttons[4] = ui->ButCalculator;
    buttons[5] = ui->ButCalibration;
    buttons[6] = ui->ButSettings;
    ui->ButPatAdd->hide();
    ui->ButPatDelete->hide();
    ui->ButPatEdit->hide();
    ui->ButPatView->hide();
    ui->ButLensAdd->hide();
    ui->ButLensDelete->hide();
    ui->ButLensEdit->hide();
    ui->ButDocAdd->hide();
    ui->ButDocDelete->hide();
    ui->ButDocEdit->hide();
    ui->ButDocView->hide();

    // Set the initial button state
    updateButtonState();
    loadpatientsql();
    loaddoctorsql();
    loadlenssql();
    loadLastDoctor();
    connect(pat,&addPatient::updatepatsql,this,&Buttons::loadpatientsql);
    connect(pat,&addPatient::savepatsql,this,&Buttons::loadpatientsql);
    connect(doc,&AddDoctor::updatedocsql,this,&Buttons::loaddoctorsql);
    connect(doc,&AddDoctor::savedocsql,this,&Buttons::loaddoctorsql);
    connect(lens,&AddLens::updatelenssql,this,&Buttons::loadlenssql);
    connect(lens,&AddLens::savelenssql,this,&Buttons::loadlenssql);
    connect(lens,&AddLens::tx_insertiol,this,&Buttons::rx_insertiol_addlens);
    connect(Current,&currentDocPat::tx_main,this,&Buttons::loadpatientsql);
    connect(this,&Buttons::sendidtocurrent,Current,&currentDocPat::loadcurrentpatientid);
    connect(Current,&currentDocPat::tx_patdocnameid_main,this,&Buttons::rx_currentpatidname);
    connect(Current,&currentDocPat::tx_docidname_button,this,&Buttons::rx_currentButton);
    connect(ui->linedocid, &QLineEdit::textChanged, this, &Buttons::onDoctorDetailsChanged);
      connect(ui->linedocname, &QLineEdit::textChanged, this, &Buttons::onDoctorDetailsChanged);
    connect(this,&Buttons::tx_docidtocurrent,Current,&currentDocPat::loadcurrentdoctorid);
    connect(doc,&AddDoctor::lastupdatedocid_buttons,this,&Buttons::rx_lastdoctid);
    // In your constructor

    ui->tableView->viewport()->installEventFilter(this);
    ui->tableView_2->viewport()->installEventFilter(this);
    ui->tableView_3->viewport()->installEventFilter(this);
    // Create a vertical layout for the scroll area's content widget
    QVBoxLayout *layout = new QVBoxLayout;

    // Add buttons to the layout dynamically
    QPushButton *buttons[] = {
        ui->ButReading1,
        ui->ButReading2,
        ui->ButReading3,
        ui->ButReading4,
        ui->ButReading5,
        ui->ButReading6,
        ui->ButReading7,
        ui->ButReading8,
        ui->ButReading9,
        ui->ButReading10
    };

    for (auto button : buttons) {
        button->setFixedSize(170, 121); // Set a fixed size for each button
        layout->addWidget(button);     // Add each button to the layout
    }

    // Ensure the layout has proper spacing and alignment
    layout->setSpacing(10);            // Spacing between buttons
    layout->setAlignment(Qt::AlignTop); // Align buttons to the top

    // Apply the layout to the content widget of the scroll area
    ui->scrollAreaWidgetContents->setLayout(layout);
    currentFormulaButton(1);
    emit tx_docidtocurrent(ui->linedocid->text());
    getlens();
on_ButSRKT_clicked();
}

Buttons::~Buttons()
{
    delete ui;
}
void Buttons::rx_patidname(const QString &id,const QString &name)
{
    qDebug()<<"the received patient id and name is"<<id<<name;

ui->linepatid->setText(id);
ui->linepatname->setText(name);
qDebug()<<"the received patient id and name is"<<id<<name;
emit sendidtocurrent(id);



}

void Buttons::rx_currentpatidname(const QString &id, const QString &name)
{
    ui->linepatid->setText(id);
    ui->linepatname->setText(name);
    qDebug()<<"the received from the current doctor & patient id and name is"<<id<<name;
    emit tx_currentpatdoc_main(id);

}
bool Buttons::eventFilter(QObject *obj, QEvent *event)
{
    // Check if the event is coming from one of the table views
    if (obj == ui->tableView->viewport() ||
        obj == ui->tableView_2->viewport() ||
        obj == ui->tableView_3->viewport())
    {
        if (event->type() == QEvent::MouseButtonPress) {
            QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);
            lastMousePosition = mouseEvent->pos();
           // qDebug() << "Mouse press detected on table view";
            return false; // Allow QTableView to handle the event as well
        } else if (event->type() == QEvent::MouseMove) {
            QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);
            int deltaX = mouseEvent->pos().x() - lastMousePosition.x();

            if (deltaX > 10) { // Swipe right
                swipeDirection = -1;
                //qDebug() << "Swipe right detected on table view";
            } else if (deltaX < -10) { // Swipe left
                swipeDirection = 1;
               // qDebug() << "Swipe left detected on table view";
            }
            lastMousePosition = mouseEvent->pos();
            return false; // Allow QTableView to handle the event as well
        } else if (event->type() == QEvent::MouseButtonRelease) {
            QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);
            mouseReleaseEvent(mouseEvent);
            return false; // Allow QTableView to handle the event as well
        }
    }

    // Pass unhandled events to the base class
    return QWidget::eventFilter(obj, event);
}
void Buttons::mousePressEvent(QMouseEvent *event)
{
    lastMousePosition = event->pos();
    //qDebug() << "Mouse pressed";
}

void Buttons::mouseMoveEvent(QMouseEvent *event)
{
    // Detect swipe direction
    if (event->buttons() & Qt::LeftButton) {
        int deltaX = event->pos().x() - lastMousePosition.x();

        if (deltaX > 10) { // Swipe right
            swipeDirection = -1;
           // qDebug() << "Swiped right";
        } else if (deltaX < -10) { // Swipe left
            swipeDirection = 1;
           // qDebug() << "Swiped left";
        }
    }
    lastMousePosition = event->pos();
}

void Buttons::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event); // Suppress unused parameter warning

    // Update button index based on swipe direction
    if (swipeDirection == -1) { // Swipe right
        currentButtonIndex = (currentButtonIndex < 6) ? currentButtonIndex + 1 : 0;
      //  qDebug() << "Swiped right, new index:" << currentButtonIndex;
    } else if (swipeDirection == 1) { // Swipe left
        currentButtonIndex = (currentButtonIndex > 0) ? currentButtonIndex - 1 : 6;
       // qDebug() << "Swiped left, new index:" << currentButtonIndex;
    }

    updateButtonState();
    swipeDirection = 0; // Reset swipe direction
}
void Buttons::updateButtonState()
{
    for (int i = 0; i < 7; i++) {
        if (i == currentButtonIndex) {
            buttons[i]->setEnabled(true);
            buttons[i]->resize(181, 161); // Selected button size
            // Move the selected button to a specific (x, y) position
            switch (i) {
                case 0:
                    buttons[i]->move(0, 590); // ButPatient
                    break;
                case 1:
                    buttons[i]->move(180, 590); // ButDoctor
                    break;
                case 2:
                    buttons[i]->move(380, 590); // ButLens
                    break;
                case 3:
                    buttons[i]->move(580, 590); // ButMeasure
                    break;
                case 4:
                    buttons[i]->move(780, 590); // ButCalculator
                    break;
                case 5:
                   buttons[i]->move(950, 590); // ButCalibration
                    break;
                case 6:
                    buttons[i]->move(1110, 590); // ButSettings
                    break;
            }
        } else {
            buttons[i]->setEnabled(false); // Keep enabled for other buttons
            buttons[i]->resize(181, 131); // Non-selected button size (only reduce height)

            // Move the non-selected buttons to a different (x, y) position
            switch (i) {
                case 0:
                    buttons[i]->move(0, 610); // ButPatient
                    break;
                case 1:
                    buttons[i]->move(180,610); // ButDoctor
                    break;
                case 2:
                    buttons[i]->move(380, 610); // ButLens
                    break;
                case 3:
                    buttons[i]->move(580, 610); // ButMeasure
                    break;
                case 4:
                    buttons[i]->move(780,610); // ButCalculator
                    break;
                case 5:
                    buttons[i]->move(950, 610); // ButCalibration
                    break;
                case 6:
                    buttons[i]->move(1110, 610); // ButSettings
                    break;
            }
        }

        qDebug() << "Button" << i << "enabled:" << (i == currentButtonIndex);
    }

    // Simulate button click for the currently active button
    buttons[currentButtonIndex]->click();
}

void Buttons::loadpatientsql()
{
    QSqlDatabase db = QSqlDatabase::database();
    QSqlTableModel *model = new QSqlTableModel(this, db);
    model->setTable("ascanpatient");  // Patient table name
    model->setSort(model->fieldIndex("id"), Qt::AscendingOrder);  // Sort by 'id' in ascending order
    model->select();
    ui->tableView->setGeometry(0, 60, 1280, 550);  // Example position and size
    ui->tableView->setModel(model);
    ui->tableView->resizeColumnsToContents();

    // Adjust position (move down by 5 pixels)
    QRect geometry = ui->tableView->geometry();
    geometry.moveTop(geometry.top() + 5);  // Move the tableView 5 pixels down
    ui->tableView->setGeometry(geometry);

    // Add spacing between columns
    int columnCount = model->columnCount();
    for (int i = 0; i < columnCount; ++i) {
        int currentWidth = ui->tableView->columnWidth(i);
        ui->tableView->setColumnWidth(i, currentWidth + 10); // Add 10 pixels of extra width for spacing
    }

    // Find and select the most recently updated row (assuming 'lastupdate' column exists)
    QString lastUpdatedColumn = "lastupdate"; // Replace with your actual column name
    if (model->rowCount() > 0) {
        QSqlQuery query(db);
        query.prepare(QString("SELECT ROWID FROM ascanpatient ORDER BY id ASC LIMIT 1"));
        if (query.exec() && query.next()) {
            int lastUpdatedRowId = query.value(0).toInt() - 1; // Convert to 0-based index
            QModelIndex lastUpdatedIndex = model->index(lastUpdatedRowId, 0); // Assuming the first column is safe
            ui->tableView->scrollTo(lastUpdatedIndex);
            ui->tableView->selectRow(lastUpdatedRowId); // Highlight the row
        }
    }
}



void Buttons::loaddoctorsql()
{

    QSqlDatabase db = QSqlDatabase::database();
    QSqlTableModel *model = new QSqlTableModel(this, db);
    model->setTable("ascandoctor");  // Patient table name
    model->select();
  ui->tableView_2->setGeometry(0,60, 1280,550);  // Example position and size
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
            ui->tableView_2->setColumnWidth(i, currentWidth + 130); // Add 10 pixels of extra width for spacing
        }

}

void Buttons::loadlenssql()
{
    QSqlDatabase db = QSqlDatabase::database();
    QSqlTableModel *model = new QSqlTableModel(this, db);
    model->setTable("ascanlensss");  // Patient table name
    model->select();
  ui->tableView_3->setGeometry(0,60, 1280,550);  // Example position and size
    ui->tableView_3->setModel(model);
    ui->tableView_3->resizeColumnsToContents();
    // Adjust position (move down by 20 pixels)
      QRect geometry = ui->tableView_3->geometry();
      geometry.moveTop(geometry.top() + 5);  // Move the tableView 20 pixels down
      ui->tableView_3->setGeometry(geometry);
      // Add spacing between columns
        int columnCount = model->columnCount();
        for (int i = 0; i < columnCount; ++i) {
            int currentWidth = ui->tableView_3->columnWidth(i);
            ui->tableView_3->setColumnWidth(i, currentWidth + 130); // Add 10 pixels of extra width for spacing
        }
}




void Buttons::currentFormulaButton(int button)
{
    QString SelectFormula = "QPushButton {"
                            "image: url(:/image/selectformula.png);"
                            "color: rgb(0,0,0);"
                            "font: italic bold 20pt 'Ubuntu';"
                            "background-color: transparent;"
                            "border: none;"
                            "Max-width: 311px;"   // Added 'px' for pixel units
                            "Min-width:311px;"
                            "Max-height: 111px;"  // Added 'px' for pixel units
                            "Min-height:111px;"
                            "}";



    QString UnSelectFormula = "QPushButton {"
                            "image: url(:/image/unselectformula.png);"
                            "color: rgb(0,0,0);"
                            "font: italic bold 20pt 'Ubuntu';"
                            "background-color: transparent;"
                            "border: none;"
                              "Max-width: 171px;"   // Added 'px' for pixel units
                              "Min-width:171px;"
                              "Max-height: 71px;"  // Added 'px' for pixel units
                              "Min-height:71px;"
                            "}";
    ui->ButSRKT->setStyleSheet(UnSelectFormula);
    ui->ButSRKII->setStyleSheet(UnSelectFormula);
    ui->ButHofferQ->setStyleSheet(UnSelectFormula);
    ui->ButHolladay->setStyleSheet(UnSelectFormula);
    ui->ButHaigis->setStyleSheet(UnSelectFormula);
    ui->ButSRKT->move(1100,120);
    ui->ButSRKII->move(1100,220);
    ui->ButHofferQ->move(1100,320);
    ui->ButHolladay->move(1100,420);
    ui->ButHaigis->move(1100,520);

    if(button==0){
        ui->ButSRKT->setStyleSheet(SelectFormula);
        ui->ButSRKT->move(1030,100);
    }
    if(button==1){
        ui->ButSRKII->setStyleSheet(SelectFormula);
        ui->ButSRKII->move(1030,200);

    }
    if(button == 2){
        ui->ButHofferQ->setStyleSheet(SelectFormula);
        ui->ButHofferQ->move(1030,300);
    }
    if(button == 3){
        ui->ButHolladay->setStyleSheet(SelectFormula);
        ui->ButHolladay->move(1030,400);
    }
    if(button == 4){
        ui->ButHaigis->setStyleSheet(SelectFormula);
        ui->ButHaigis->move(1030,500);
    }

}





// Tab switching slots
void Buttons::on_ButPatient_clicked()      {
    ui->tabWidget->setCurrentIndex(0);
    //ui->ButPatient->move(0,590);
}
void Buttons::on_ButDoctor_clicked()       {
    ui->tabWidget->setCurrentIndex(1);
}
void Buttons::on_ButLens_clicked()         {
    ui->tabWidget->setCurrentIndex(2);
}
void Buttons::on_ButMeasure_clicked()      {
    ui->tabWidget->setCurrentIndex(3);
}
void Buttons::on_ButCalculator_clicked()   {
    ui->tabWidget->setCurrentIndex(4);
}
void Buttons::on_ButCalibration_clicked()  {
    ui->tabWidget->setCurrentIndex(5);
}
void Buttons::on_ButSettings_clicked()     {
    ui->tabWidget->setCurrentIndex(6);
}

void Buttons::on_ButPatTouch_clicked()
{
    patassistive=!patassistive;
    if(patassistive){
  ui->ButPatAdd->show();
  ui->ButPatDelete->show();
  ui->ButPatEdit->show();
  ui->ButPatView->show();
    }else{
        ui->ButPatAdd->hide();
        ui->ButPatDelete->hide();
        ui->ButPatEdit->hide();
        ui->ButPatView->hide();
    }
}

void Buttons::on_ButLensTouch_clicked()
{
    lensassistive=!lensassistive;
    if(lensassistive){
  ui->ButLensAdd->show();
  ui->ButLensDelete->show();
  ui->ButLensEdit->show();
    }else{
        ui->ButLensAdd->hide();
        ui->ButLensDelete->hide();
        ui->ButLensEdit->hide();
    }
}

void Buttons::on_ButDocTouch_clicked()
{
    docassistive=!docassistive;
    if(docassistive){
  ui->ButDocAdd->show();
  ui->ButDocDelete->show();
  ui->ButDocEdit->show();
  ui->ButDocView->show();
    }else{
        ui->ButDocAdd->hide();
        ui->ButDocDelete->hide();
        ui->ButDocEdit->hide();
        ui->ButDocView->hide();
    }
}

void Buttons::on_ButPatAdd_clicked()
{
    pat->show();

}

void Buttons::on_ButDocAdd_clicked()
{
    doc->show();
}

void Buttons::on_ButLensAdd_clicked()
{
    lens->show();
}
void Buttons::loadLastDoctor()
{
    QSqlQuery query(mydb1);

    // Retrieve the most recently updated or inserted doctor
    QString queryStr = R"(
        SELECT Doctorid, Name
        FROM ascandoctor
        WHERE lastupdate = (SELECT MAX(lastupdate) FROM ascandoctor)
           OR Doctorid = (SELECT MAX(Doctorid) FROM ascandoctor)
        ORDER BY lastupdate DESC, Doctorid DESC
        LIMIT 1
    )";

    if (!query.exec(queryStr)) {
        qDebug() << "Database query failed:" << query.lastError().text();
        return;
    }

    if (query.next()) {
        QString doctorId = query.value(0).toString();
        QString doctorName = query.value(1).toString();
        ui->linedocid->setText(doctorId);
        ui->linedocname->setText(doctorName);
        qDebug() << "Last updated or inserted doctor loaded: ID -" << doctorId << ", Name -" << doctorName;
    } else {
        qDebug() << "Query executed but no rows returned.";
        ui->linedocid->clear();
        ui->linedocname->clear();
    }
}
void Buttons::onDoctorDetailsChanged()
{
    QString doctorId = ui->linedocid->text();
    QString doctorName = ui->linedocname->text();

    if (doctorId.isEmpty() || doctorName.isEmpty()) {
        return; // Do nothing if any field is empty
    }

    QSqlQuery query(mydb1);
    QString updateStr = QString(R"(
        UPDATE ascandoctor
        SET Name = :doctorName, lastupdate = CURRENT_TIMESTAMP
        WHERE Doctorid = :doctorId
    )");

    query.prepare(updateStr);
    query.bindValue(":doctorId", doctorId);
    query.bindValue(":doctorName", doctorName);

    if (!query.exec()) {
        qDebug() << "Failed to update doctor details:" << query.lastError().text();
    } else {
        qDebug() << "Doctor details updated: ID -" << doctorId << ", Name -" << doctorName;
    }
}

void Buttons::updateLineEdit(QComboBox *comboBox, QLineEdit *lineEdit)
{
    QString selectedName = comboBox->currentText();

    // SQL query to fetch data based on the selected value
    QSqlQuery query;
    query.prepare("SELECT ASRKT FROM ascanlensss WHERE IOL = :value");
    query.bindValue(":value", selectedName);

    if (query.exec()) {
        if (query.next()) {
            // Retrieve the ASRKT value
            QString asrktValue = query.value("ASRKT").toString();

            // Display the fetched value in the specified line edit
            lineEdit->setText(asrktValue);
        } else {
            qDebug() << "No data found for the selected lens type!";
            lineEdit->clear(); // Clear the line edit if no data is found
        }
    } else {
        // Log the query error
        qDebug() << "SQL Query Error:" << query.lastError().text();
    }
}

void Buttons::updateLineEditSRKT(QComboBox *comboBox, QLineEdit *lineEdit)
{
    QString selectedName = comboBox->currentText();

    // SQL query to fetch data based on the selected value
    QSqlQuery query;
    query.prepare("SELECT ASRKII FROM ascanlensss WHERE IOL = :value");
    query.bindValue(":value", selectedName);

    if (query.exec()) {
        if (query.next()) {
            // Retrieve the ASRKT value
            QString asrktValue = query.value("ASRKII").toString();

            // Display the fetched value in the specified line edit
            lineEdit->setText(asrktValue);
        } else {
            qDebug() << "No data found for the selected lens type!";
            lineEdit->clear(); // Clear the line edit if no data is found
        }
    } else {
        // Log the query error
        qDebug() << "SQL Query Error:" << query.lastError().text();
    }
}

void Buttons::updateLineEditHOFFERQ(QComboBox *comboBox, QLineEdit *lineEdit)
{
    QString selectedName = comboBox->currentText();

    // SQL query to fetch data based on the selected value
    QSqlQuery query;
    query.prepare("SELECT ACD FROM ascanlensss WHERE IOL = :value");
    query.bindValue(":value", selectedName);

    if (query.exec()) {
        if (query.next()) {
            // Retrieve the ASRKT value
            QString asrktValue = query.value("ACD").toString();

            // Display the fetched value in the specified line edit
            lineEdit->setText(asrktValue);
        } else {
            qDebug() << "No data found for the selected lens type!";
            lineEdit->clear(); // Clear the line edit if no data is found
        }
    } else {
        // Log the query error
        qDebug() << "SQL Query Error:" << query.lastError().text();
    }
}

void Buttons::updateLineEditHOLLADAY(QComboBox *comboBox, QLineEdit *lineEdit)
{
    QString selectedName = comboBox->currentText();

    // SQL query to fetch data based on the selected value
    QSqlQuery query;
    query.prepare("SELECT SF FROM ascanlensss WHERE IOL = :value");
    query.bindValue(":value", selectedName);

    if (query.exec()) {
        if (query.next()) {
            // Retrieve the ASRKT value
            QString asrktValue = query.value("SF").toString();

            // Display the fetched value in the specified line edit
            lineEdit->setText(asrktValue);
        } else {
            qDebug() << "No data found for the selected lens type!";
            lineEdit->clear(); // Clear the line edit if no data is found
        }
    } else {
        // Log the query error
        qDebug() << "SQL Query Error:" << query.lastError().text();
    }
}

void Buttons::updateLineEditHAIGIS(QComboBox *comboBox, QLineEdit *lineEdit)
{
    QString selectedName = comboBox->currentText();

    // SQL query to fetch data based on the selected value
    QSqlQuery query;
    query.prepare("SELECT a0 FROM ascanlensss WHERE IOL = :value");
    query.bindValue(":value", selectedName);

    if (query.exec()) {
        if (query.next()) {
            // Retrieve the ASRKT value
            QString asrktValue = query.value("a0").toString();

            // Display the fetched value in the specified line edit
            lineEdit->setText(asrktValue);
        } else {
            qDebug() << "No data found for the selected lens type!";
            lineEdit->clear(); // Clear the line edit if no data is found
        }
    } else {
        // Log the query error
        qDebug() << "SQL Query Error:" << query.lastError().text();
    }
}
void Buttons::rx_lastdoctid(const QString &id,const QString &docname)
{
    ui->linedocid->setText(id);
    ui->linedocname->setText(docname);
    emit tx_docidtocurrent(ui->linedocid->text());
}

void Buttons::rx_currentButton(const QString &id, const QString &docname)
{
    ui->linedocid->setText(id);
    ui->linedocname->setText(docname);
    loaddoctorsql();
}

void Buttons::rx_insertiol_addlens(const QString &text)
{
   doc->getinsertiol(text);
}


void Buttons::on_ButPatDelete_clicked()
{
    QModelIndexList selectedRows = ui->tableView->selectionModel()->selectedRows();

       if (selectedRows.isEmpty()) {
           return;
       }

       int row = selectedRows.first().row();
       QString id = ui->tableView->model()->index(row, 0).data().toString(); // Assuming 'id' is in the first column

       QSqlQuery query;
       query.prepare("DELETE FROM ascanpatient WHERE id = :id");
       query.bindValue(":id", id);

       if (query.exec()) {
           loadpatientsql();
       }
}

void Buttons::on_ButPatEdit_clicked()
{
    QModelIndexList selectedRows = ui->tableView->selectionModel()->selectedRows();
    int row = selectedRows.first().row();
    QString id = ui->tableView->model()->index(row,0).data().toString();
    QString name = ui->tableView->model()->index(row, 1).data().toString();
    QString age = ui->tableView->model()->index(row, 2).data().toString();
    QString gender=ui->tableView->model()->index(row,3).data().toString();
    QString number = ui->tableView->model()->index(row, 4).data().toString();
    QString operatingmode=ui->tableView->model()->index(row,6).data().toString();
    QString operatingmethod=ui->tableView->model()->index(row,5).data().toString();
    QString operatingeye=ui->tableView->model()->index(row,7).data().toString();
    QString keratol1=ui->tableView->model()->index(row,8).data().toString();
    QString keratol2=ui->tableView->model()->index(row,9).data().toString();
    QString keratol=ui->tableView->model()->index(row,10).data().toString();
    QString kerator1=ui->tableView->model()->index(row,11).data().toString();
    QString kerator2=ui->tableView->model()->index(row,12).data().toString();
    QString kerator=ui->tableView->model()->index(row,13).data().toString();

    pat->setpatientDetails(id, name,age,gender,number,operatingmethod,operatingmode,operatingeye,keratol1,keratol2,keratol,kerator1,kerator2,kerator);
    pat->show();
}

void Buttons::on_ButPatView_clicked()
{
    QModelIndexList selectedRows = ui->tableView->selectionModel()->selectedRows();

    if (selectedRows.isEmpty()) {
        return;
    }

    int row = selectedRows.first().row();
    QString id = ui->tableView->model()->index(row, 0).data().toString();
    QString name = ui->tableView->model()->index(row, 1).data().toString();
    QString age = ui->tableView->model()->index(row, 2).data().toString();
    QString gender = ui->tableView->model()->index(row, 3).data().toString();
QString number = ui->tableView->model()->index(row, 4).data().toString();
QString operatingmode=ui->tableView->model()->index(row,6).data().toString();
QString operatingmethod=ui->tableView->model()->index(row,5).data().toString();
QString operatingeye=ui->tableView->model()->index(row,7).data().toString();
viewp->viewPatdata(id,name,age,gender,number,operatingmethod,operatingmode,operatingeye);
viewp->show();
}

void Buttons::on_ButDocDelete_clicked()
{
    QModelIndexList selectedRows = ui->tableView_2->selectionModel()->selectedRows();

       if (selectedRows.isEmpty()) {
           return;
       }

       int row = selectedRows.first().row();
       QString id = ui->tableView_2->model()->index(row, 0).data().toString(); // Assuming 'id' is in the first column

       QSqlQuery query;
       query.prepare("DELETE FROM ascandoctor WHERE Doctorid = :id");
       query.bindValue(":id", id);

       if (query.exec()) {
           loaddoctorsql();
       }
}

void Buttons::on_ButDocEdit_clicked()
{
    QModelIndexList selectedRows = ui->tableView_2->selectionModel()->selectedRows();
    int row = selectedRows.first().row();
    QString id = ui->tableView_2->model()->index(row,0).data().toString();
    QString name = ui->tableView_2->model()->index(row, 1).data().toString();
    QString lens1 = ui->tableView_2->model()->index(row, 2).data().toString();
    QString lens2=ui->tableView_2->model()->index(row,3).data().toString();
    QString lens3 = ui->tableView_2->model()->index(row, 4).data().toString();
    QString formula=ui->tableView_2->model()->index(row,6).data().toString();


    doc->doctoreditdetails(id,name,lens1,lens2,lens3,formula);
    doc->show();
}

void Buttons::on_ButDocView_clicked()
{
    QModelIndexList selectedRows = ui->tableView_2->selectionModel()->selectedRows();
    int row = selectedRows.first().row();
    QString id = ui->tableView_2->model()->index(row,0).data().toString();
    QString name = ui->tableView_2->model()->index(row, 1).data().toString();
    QString lens1 = ui->tableView_2->model()->index(row, 2).data().toString();
    QString lens2=ui->tableView_2->model()->index(row,3).data().toString();
    QString lens3 = ui->tableView_2->model()->index(row, 4).data().toString();
    QString formula=ui->tableView_2->model()->index(row,6).data().toString();

    viewd->viewdocdetails(id,name,lens1,lens2,lens3,formula);
    viewd->show();
}

void Buttons::on_ButLensDelete_clicked()
{
    QModelIndexList selectedRows = ui->tableView_3->selectionModel()->selectedRows();

       if (selectedRows.isEmpty()) {
           return;
       }

       int row = selectedRows.first().row();
       QString iol = ui->tableView_3->model()->index(row, 0).data().toString(); // Assuming 'id' is in the first column

       QSqlQuery query;
       query.prepare("DELETE FROM ascanlens WHERE IOL = :iol");
       query.bindValue(":iol", iol);

       if (query.exec()) {
           loadlenssql();
       }
}

void Buttons::on_ButLensEdit_clicked()
{
    QModelIndexList selectedRows = ui->tableView_3->selectionModel()->selectedRows();
    int row = selectedRows.first().row();
    QString iol = ui->tableView_3->model()->index(row,0).data().toString();
    QString type = ui->tableView_3->model()->index(row, 1).data().toString();
    QString asrkt = ui->tableView_3->model()->index(row, 2).data().toString();
    QString asrkii=ui->tableView_3->model()->index(row,3).data().toString();
    QString acd = ui->tableView_3->model()->index(row, 4).data().toString();
    QString sf=ui->tableView_3->model()->index(row,6).data().toString();
    QString a0=ui->tableView_3->model()->index(row,7).data().toString();
    QString a1=ui->tableView_3->model()->index(row,8).data().toString();
    QString a2=ui->tableView_3->model()->index(row,9).data().toString();

   lens->editlensdetails(iol,type,asrkt,asrkii,acd,sf,a0,a1,a2);
   lens->show();

}

void Buttons::on_ButCurrent_clicked()
{
    Current->show();
}

void Buttons::on_ButSRKT_clicked()
{
    currentFormulaButton(0);
    ui->lbllens1aconst->setText("ACONST");
    ui->lbllens2aconst->setText("ACONST");
    ui->lbllen3aconst->setText("ACONST");
    setupconnectionsSRKT();
    updateLineEditSRKT(ui->combolens1,ui->linelens1aconst);
    updateLineEditSRKT(ui->combolens2,ui->linelens2aconst);
    updateLineEditSRKT(ui->combolens3,ui->linelens3aconst3);
    double aconst = ui->linelens1aconst->text().toDouble();
    double aconst1 = ui->linelens2aconst->text().toDouble();
    double aconst2 = ui->linelens3aconst3->text().toDouble();

    // Remove the previous connections to avoid multiple signal-slot connections
    disconnect(ui->linelens1aconst, &QLineEdit::textChanged, this, &Buttons::on_ButSRKT_clicked);
    disconnect(ui->linelens2aconst, &QLineEdit::textChanged, this, &Buttons::on_ButSRKT_clicked);
    disconnect(ui->linelens3aconst3, &QLineEdit::textChanged, this, &Buttons::on_ButSRKT_clicked);
    disconnect(ui->linerx, &QLineEdit::textChanged, this, &Buttons::on_ButSRKT_clicked);
    disconnect(ui->lineacd, &QLineEdit::textChanged, this, &Buttons::on_ButSRKT_clicked);
    disconnect(ui->linek, &QLineEdit::textChanged, this, &Buttons::on_ButSRKT_clicked);

    // Connect the textChanged signals
    connect(ui->linelens1aconst, &QLineEdit::textChanged, this, &Buttons::on_ButSRKT_clicked);
    connect(ui->linelens2aconst, &QLineEdit::textChanged, this, &Buttons::on_ButSRKT_clicked);
    connect(ui->linelens3aconst3, &QLineEdit::textChanged, this, &Buttons::on_ButSRKT_clicked);
    connect(ui->linerx, &QLineEdit::textChanged, this, &Buttons::on_ButSRKT_clicked);
    connect(ui->lineacd, &QLineEdit::textChanged, this, &Buttons::on_ButSRKT_clicked);
    connect(ui->linek, &QLineEdit::textChanged, this, &Buttons::on_ButSRKT_clicked);
    rx_value = ui->linerx->text().toDouble();
    axial_length = ui->lineacd->text().toDouble();
    keratometer = ui->linek->text().toDouble();
    QLineEdit *emm1 = ui->linelens1emm;
    QLineEdit *emm2 = ui->linelens2emm2;
    QLineEdit *emm3 = ui->linelens3emm3;

    // Perform SRKII calculations for Lens 1
    QLineEdit* lineEditsPower[5] = {ui->linelens1iol1, ui->linelens1iol2, ui->linelens1iol3, ui->linelens1iol4, ui->linelens1iol5};
    QLineEdit* lineEditsError[5] = {ui->linelens1ref1, ui->linelens1ref2, ui->linelens1ref3, ui->linelens1ref4, ui->linelens1ref5};
    formula->SRKTCalc(axial_length, aconst, keratometer, rx_value, lineEditsPower, lineEditsError, emm1);

    // Perform SRKII calculations for Lens 2
    QLineEdit* lineEditsPower2[5] = {ui->linelens2iol1, ui->linelens2iol2, ui->linelens2iol3, ui->linelens2iol4, ui->linelens2iol5};
    QLineEdit* lineEditsError2[5] = {ui->linelens2ref1, ui->linelens2ref2, ui->linelens2ref3, ui->linelens2ref4, ui->linelens2ref5};
    formula->SRKTCalc(axial_length, aconst1, keratometer, rx_value, lineEditsPower2, lineEditsError2, emm2);

    // Perform SRKII calculations for Lens 3
    QLineEdit* lineEditsPower3[5] = {ui->linelens3iol1, ui->linelens3iol2, ui->linelens3iol3, ui->linelens3iol4, ui->linelens3iol5};
    QLineEdit* lineEditsError3[5] = {ui->linelens3ref1, ui->linelens3ref2, ui->linelens3ref3, ui->linelens3ref4, ui->linelens3ref5};
    formula->SRKTCalc(axial_length, aconst2, keratometer, rx_value, lineEditsPower3, lineEditsError3, emm3);
}

void Buttons::on_ButSRKII_clicked()
{
    currentFormulaButton(1);

    // Re-read the updated A-constant values from the QLineEdit widgets
    double aconst = ui->linelens1aconst->text().toDouble();
    double aconst1 = ui->linelens2aconst->text().toDouble();
    double aconst2 = ui->linelens3aconst3->text().toDouble();

    // Remove the previous connections to avoid multiple signal-slot connections
    disconnect(ui->linelens1aconst, &QLineEdit::textChanged, this, &Buttons::on_ButSRKII_clicked);
    disconnect(ui->linelens2aconst, &QLineEdit::textChanged, this, &Buttons::on_ButSRKII_clicked);
    disconnect(ui->linelens3aconst3, &QLineEdit::textChanged, this, &Buttons::on_ButSRKII_clicked);
    disconnect(ui->linerx, &QLineEdit::textChanged, this, &Buttons::on_ButSRKII_clicked);
    disconnect(ui->lineacd, &QLineEdit::textChanged, this, &Buttons::on_ButSRKII_clicked);
    disconnect(ui->linek, &QLineEdit::textChanged, this, &Buttons::on_ButSRKII_clicked);

    // Connect the textChanged signals
    connect(ui->linelens1aconst, &QLineEdit::textChanged, this, &Buttons::on_ButSRKII_clicked);
    connect(ui->linelens2aconst, &QLineEdit::textChanged, this, &Buttons::on_ButSRKII_clicked);
    connect(ui->linelens3aconst3, &QLineEdit::textChanged, this, &Buttons::on_ButSRKII_clicked);
    connect(ui->linerx, &QLineEdit::textChanged, this, &Buttons::on_ButSRKII_clicked);
    connect(ui->lineacd, &QLineEdit::textChanged, this, &Buttons::on_ButSRKII_clicked);
    connect(ui->linek, &QLineEdit::textChanged, this, &Buttons::on_ButSRKII_clicked);

    rx_value = ui->linerx->text().toDouble();
    axial_length = ui->lineacd->text().toDouble();
    keratometer = ui->linek->text().toDouble();

    // Update the labels
    ui->lbllens1aconst->setText("ACONST");
    ui->lbllens2aconst->setText("ACONST");
    ui->lbllen3aconst->setText("ACONST");

    // Setup connections and update the line edits
    setupconnectionsSRKT();
    updateLineEdit(ui->combolens1, ui->linelens1aconst);
    updateLineEdit(ui->combolens2, ui->linelens2aconst);
    updateLineEdit(ui->combolens3, ui->linelens3aconst3);

    QLineEdit *emm1 = ui->linelens1emm;
    QLineEdit *emm2 = ui->linelens2emm2;
    QLineEdit *emm3 = ui->linelens3emm3;

    // Perform SRKII calculations for Lens 1
    QLineEdit* lineEditsPower[5] = {ui->linelens1iol1, ui->linelens1iol2, ui->linelens1iol3, ui->linelens1iol4, ui->linelens1iol5};
    QLineEdit* lineEditsError[5] = {ui->linelens1ref1, ui->linelens1ref2, ui->linelens1ref3, ui->linelens1ref4, ui->linelens1ref5};
    formula->SRKIICalc(axial_length, aconst, keratometer, rx_value, lineEditsPower, lineEditsError, emm1);

    // Perform SRKII calculations for Lens 2
    QLineEdit* lineEditsPower2[5] = {ui->linelens2iol1, ui->linelens2iol2, ui->linelens2iol3, ui->linelens2iol4, ui->linelens2iol5};
    QLineEdit* lineEditsError2[5] = {ui->linelens2ref1, ui->linelens2ref2, ui->linelens2ref3, ui->linelens2ref4, ui->linelens2ref5};
    formula->SRKIICalc(axial_length, aconst1, keratometer, rx_value, lineEditsPower2, lineEditsError2, emm2);

    // Perform SRKII calculations for Lens 3
    QLineEdit* lineEditsPower3[5] = {ui->linelens3iol1, ui->linelens3iol2, ui->linelens3iol3, ui->linelens3iol4, ui->linelens3iol5};
    QLineEdit* lineEditsError3[5] = {ui->linelens3ref1, ui->linelens3ref2, ui->linelens3ref3, ui->linelens3ref4, ui->linelens3ref5};
    formula->SRKIICalc(axial_length, aconst2, keratometer, rx_value, lineEditsPower3, lineEditsError3, emm3);

    // Uncomment if needed for additional behavior
    // srkiilinechanged();
}



void Buttons::on_ButHofferQ_clicked()
{
currentFormulaButton(2);
ui->lbllens1aconst->setText("ACD");
ui->lbllens2aconst->setText("ACD");
ui->lbllen3aconst->setText("ACD");
setupconnectionsHOFFERQ();
updateLineEditHOFFERQ(ui->combolens1,ui->linelens1aconst);
updateLineEditHOFFERQ(ui->combolens2,ui->linelens2aconst);
updateLineEditHOFFERQ(ui->combolens3,ui->linelens3aconst3);
// Re-read the updated A-constant values from the QLineEdit widgets
double ACD = ui->linelens1aconst->text().toDouble();
double ACD1 = ui->linelens2aconst->text().toDouble();
double ACD2 = ui->linelens3aconst3->text().toDouble();

// Remove the previous connections to avoid multiple signal-slot connections
disconnect(ui->linelens1aconst, &QLineEdit::textChanged, this, &Buttons::on_ButHofferQ_clicked);
disconnect(ui->linelens2aconst, &QLineEdit::textChanged, this, &Buttons::on_ButHofferQ_clicked);
disconnect(ui->linelens3aconst3, &QLineEdit::textChanged, this, &Buttons::on_ButHofferQ_clicked);
disconnect(ui->linerx, &QLineEdit::textChanged, this, &Buttons::on_ButHofferQ_clicked);
disconnect(ui->lineacd, &QLineEdit::textChanged, this, &Buttons::on_ButHofferQ_clicked);
disconnect(ui->linek, &QLineEdit::textChanged, this, &Buttons::on_ButHofferQ_clicked);

// Connect the textChanged signals
connect(ui->linelens1aconst, &QLineEdit::textChanged, this, &Buttons::on_ButHofferQ_clicked);
connect(ui->linelens2aconst, &QLineEdit::textChanged, this, &Buttons::on_ButHofferQ_clicked);
connect(ui->linelens3aconst3, &QLineEdit::textChanged, this, &Buttons::on_ButHofferQ_clicked);
connect(ui->linerx, &QLineEdit::textChanged, this, &Buttons::on_ButHofferQ_clicked);
connect(ui->lineacd, &QLineEdit::textChanged, this, &Buttons::on_ButHofferQ_clicked);
connect(ui->linek, &QLineEdit::textChanged, this, &Buttons::on_ButHofferQ_clicked);

rx_value = ui->linerx->text().toDouble();
axial_length = ui->lineacd->text().toDouble();
keratometer = ui->linek->text().toDouble();
QLineEdit *emm1 = ui->linelens1emm;
QLineEdit *emm2 = ui->linelens2emm2;
QLineEdit *emm3 = ui->linelens3emm3;

// Perform SRKII calculations for Lens 1
QLineEdit* lineEditsPower[5] = {ui->linelens1iol1, ui->linelens1iol2, ui->linelens1iol3, ui->linelens1iol4, ui->linelens1iol5};
QLineEdit* lineEditsError[5] = {ui->linelens1ref1, ui->linelens1ref2, ui->linelens1ref3, ui->linelens1ref4, ui->linelens1ref5};
formula->HofferCalc(axial_length, ACD, keratometer, rx_value, lineEditsPower, lineEditsError, emm1);

// Perform SRKII calculations for Lens 2
QLineEdit* lineEditsPower2[5] = {ui->linelens2iol1, ui->linelens2iol2, ui->linelens2iol3, ui->linelens2iol4, ui->linelens2iol5};
QLineEdit* lineEditsError2[5] = {ui->linelens2ref1, ui->linelens2ref2, ui->linelens2ref3, ui->linelens2ref4, ui->linelens2ref5};
formula->HofferCalc(axial_length, ACD1, keratometer, rx_value, lineEditsPower2, lineEditsError2, emm2);

// Perform SRKII calculations for Lens 3
QLineEdit* lineEditsPower3[5] = {ui->linelens3iol1, ui->linelens3iol2, ui->linelens3iol3, ui->linelens3iol4, ui->linelens3iol5};
QLineEdit* lineEditsError3[5] = {ui->linelens3ref1, ui->linelens3ref2, ui->linelens3ref3, ui->linelens3ref4, ui->linelens3ref5};
formula->HofferCalc(axial_length, ACD2, keratometer, rx_value, lineEditsPower3, lineEditsError3, emm3);

}

void Buttons::on_ButHolladay_clicked()
{
currentFormulaButton(3);
ui->lbllens1aconst->setText("SF");
ui->lbllens2aconst->setText("SF");
ui->lbllen3aconst->setText("SF");
double SF = ui->linelens1aconst->text().toDouble();
double SF1 = ui->linelens2aconst->text().toDouble();
double SF2 = ui->linelens3aconst3->text().toDouble();

setupconnectionsHOLLADAY();
updateLineEditHOLLADAY(ui->combolens1,ui->linelens1aconst);
updateLineEditHOLLADAY(ui->combolens2,ui->linelens2aconst);
updateLineEditHOLLADAY(ui->combolens3,ui->linelens3aconst3);
disconnect(ui->linelens1aconst, &QLineEdit::textChanged, this, &Buttons::on_ButHolladay_clicked);
disconnect(ui->linelens2aconst, &QLineEdit::textChanged, this, &Buttons::on_ButHolladay_clicked);
disconnect(ui->linelens3aconst3, &QLineEdit::textChanged, this, &Buttons::on_ButHolladay_clicked);
disconnect(ui->linerx, &QLineEdit::textChanged, this, &Buttons::on_ButHolladay_clicked);
disconnect(ui->lineacd, &QLineEdit::textChanged, this, &Buttons::on_ButHolladay_clicked);
disconnect(ui->linek, &QLineEdit::textChanged, this, &Buttons::on_ButHolladay_clicked);

// Connect the textChanged signals
connect(ui->linelens1aconst, &QLineEdit::textChanged, this, &Buttons::on_ButHolladay_clicked);
connect(ui->linelens2aconst, &QLineEdit::textChanged, this, &Buttons::on_ButHolladay_clicked);
connect(ui->linelens3aconst3, &QLineEdit::textChanged, this, &Buttons::on_ButHolladay_clicked);
connect(ui->linerx, &QLineEdit::textChanged, this, &Buttons::on_ButHolladay_clicked);
connect(ui->lineacd, &QLineEdit::textChanged, this, &Buttons::on_ButHolladay_clicked);
connect(ui->linek, &QLineEdit::textChanged, this, &Buttons::on_ButHolladay_clicked);

rx_value = ui->linerx->text().toDouble();
axial_length = ui->lineacd->text().toDouble();
keratometer = ui->linek->text().toDouble();
QLineEdit *emm1 = ui->linelens1emm;
QLineEdit *emm2 = ui->linelens2emm2;
QLineEdit *emm3 = ui->linelens3emm3;

// Perform SRKII calculations for Lens 1
QLineEdit* lineEditsPower[5] = {ui->linelens1iol1, ui->linelens1iol2, ui->linelens1iol3, ui->linelens1iol4, ui->linelens1iol5};
QLineEdit* lineEditsError[5] = {ui->linelens1ref1, ui->linelens1ref2, ui->linelens1ref3, ui->linelens1ref4, ui->linelens1ref5};
formula->HolladayCalc(axial_length, SF, keratometer, rx_value, lineEditsPower, lineEditsError, emm1);

// Perform SRKII calculations for Lens 2
QLineEdit* lineEditsPower2[5] = {ui->linelens2iol1, ui->linelens2iol2, ui->linelens2iol3, ui->linelens2iol4, ui->linelens2iol5};
QLineEdit* lineEditsError2[5] = {ui->linelens2ref1, ui->linelens2ref2, ui->linelens2ref3, ui->linelens2ref4, ui->linelens2ref5};
formula->HolladayCalc(axial_length, SF1, keratometer, rx_value, lineEditsPower2, lineEditsError2, emm2);

// Perform SRKII calculations for Lens 3
QLineEdit* lineEditsPower3[5] = {ui->linelens3iol1, ui->linelens3iol2, ui->linelens3iol3, ui->linelens3iol4, ui->linelens3iol5};
QLineEdit* lineEditsError3[5] = {ui->linelens3ref1, ui->linelens3ref2, ui->linelens3ref3, ui->linelens3ref4, ui->linelens3ref5};
formula->HolladayCalc(axial_length, SF2, keratometer, rx_value, lineEditsPower3, lineEditsError3, emm3);

}

void Buttons::on_ButHaigis_clicked()
{
currentFormulaButton(4);
ui->lbllens1aconst->setText("a0");
ui->lbllens2aconst->setText("a0");
ui->lbllen3aconst->setText("a0");
setupconnectionsHAIGIS();
updateLineEditHAIGIS(ui->combolens1,ui->linelens1aconst);
updateLineEditHAIGIS(ui->combolens2,ui->linelens2aconst);
updateLineEditHAIGIS(ui->combolens3,ui->linelens3aconst3);
}
void Buttons::getlens()
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
        ui->combolens1->clear();
        ui->combolens2->clear();
        ui->combolens3->clear();

        ui->combolens1->addItems(lensTypes);
        ui->combolens2->addItems(lensTypes);
        ui->combolens3->addItems(lensTypes);

        qDebug() << "Lens types retrieved from SQL:" << lensTypes;
    } else {
        qWarning() << "Database error:" << query.lastError().text();
    }
}

void Buttons::setupConnections()
{
    connect(ui->combolens1, &QComboBox::currentTextChanged, this, [this](const QString &text) {
        updateLineEdit(ui->combolens1, ui->linelens1aconst);
    });
    connect(ui->combolens2, &QComboBox::currentTextChanged, this, [this](const QString &text) {
        updateLineEdit(ui->combolens2, ui->linelens2aconst);
    });
    connect(ui->combolens3, &QComboBox::currentTextChanged, this, [this](const QString &text) {
        updateLineEdit(ui->combolens3, ui->linelens3aconst3);
    });
}

void Buttons::setupconnectionsSRKT()
{
    connect(ui->combolens1, &QComboBox::currentTextChanged, this, [this](const QString &text) {
        updateLineEditSRKT(ui->combolens1, ui->linelens1aconst);
    });

    connect(ui->combolens2, &QComboBox::currentTextChanged, this, [this](const QString &text) {
        updateLineEditSRKT(ui->combolens2, ui->linelens2aconst);
    });

    connect(ui->combolens3, &QComboBox::currentTextChanged, this, [this](const QString &text) {
        updateLineEditSRKT(ui->combolens3, ui->linelens3aconst3);
    });
}

void Buttons::setupconnectionsHOFFERQ()
{
    connect(ui->combolens1, &QComboBox::currentTextChanged, this, [this](const QString &text) {
        updateLineEditHOFFERQ(ui->combolens1, ui->linelens1aconst);
    });

    connect(ui->combolens2, &QComboBox::currentTextChanged, this, [this](const QString &text) {
        updateLineEditHOFFERQ(ui->combolens2, ui->linelens2aconst);
    });

    connect(ui->combolens3, &QComboBox::currentTextChanged, this, [this](const QString &text) {
        updateLineEditHOFFERQ(ui->combolens3, ui->linelens3aconst3);
    });
}

void Buttons::setupconnectionsHOLLADAY()
{
    connect(ui->combolens1, &QComboBox::currentTextChanged, this, [this](const QString &text) {
        updateLineEditHOLLADAY(ui->combolens1, ui->linelens1aconst);
    });

    connect(ui->combolens2, &QComboBox::currentTextChanged, this, [this](const QString &text) {
        updateLineEditHOLLADAY(ui->combolens2, ui->linelens2aconst);
    });

    connect(ui->combolens3, &QComboBox::currentTextChanged, this, [this](const QString &text) {
        updateLineEditHOLLADAY(ui->combolens3, ui->linelens3aconst3);
    });
}

void Buttons::setupconnectionsHAIGIS()
{
    connect(ui->combolens1, &QComboBox::currentTextChanged, this, [this](const QString &text) {
        updateLineEditHAIGIS(ui->combolens1, ui->linelens1aconst);
    });

    connect(ui->combolens2, &QComboBox::currentTextChanged, this, [this](const QString &text) {
        updateLineEditHAIGIS(ui->combolens2, ui->linelens2aconst);
    });

    connect(ui->combolens3, &QComboBox::currentTextChanged, this, [this](const QString &text) {
        updateLineEditHAIGIS(ui->combolens3, ui->linelens3aconst3);
    });

}

void Buttons::srkiilinechanged()
{

}
