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
    connect(pat,&addPatient::updatepatsql,this,&Buttons::loadpatientsql);
    connect(pat,&addPatient::savepatsql,this,&Buttons::loadpatientsql);
    connect(doc,&AddDoctor::updatedocsql,this,&Buttons::loaddoctorsql);
    connect(doc,&AddDoctor::savedocsql,this,&Buttons::loaddoctorsql);
    connect(lens,&AddLens::updatelenssql,this,&Buttons::loadlenssql);
    connect(lens,&AddLens::savelenssql,this,&Buttons::loadlenssql);
    connect(Current,&currentDocPat::tx_main,this,&Buttons::loadpatientsql);
    connect(this,&Buttons::sendidtocurrent,Current,&currentDocPat::loadcurrentpatientid);
    connect(Current,&currentDocPat::tx_patdocnameid_main,this,&Buttons::rx_currentpatidname);
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
    ui->tableView->setGeometry(0, 60, 1280, 580);  // Example position and size
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
  ui->tableView_2->setGeometry(0,60, 1280,580);  // Example position and size
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
            ui->tableView_2->setColumnWidth(i, currentWidth + 180); // Add 10 pixels of extra width for spacing
        }

}

void Buttons::loadlenssql()
{
    QSqlDatabase db = QSqlDatabase::database();
    QSqlTableModel *model = new QSqlTableModel(this, db);
    model->setTable("ascanlens");  // Patient table name
    model->select();
  ui->tableView_3->setGeometry(0,60, 1280,580);  // Example position and size
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
            ui->tableView_3->setColumnWidth(i, currentWidth + 180); // Add 10 pixels of extra width for spacing
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
}

void Buttons::on_ButSRKII_clicked()
{
currentFormulaButton(1);
}

void Buttons::on_ButHofferQ_clicked()
{
currentFormulaButton(2);
}

void Buttons::on_ButHolladay_clicked()
{
currentFormulaButton(3);
}

void Buttons::on_ButHaigis_clicked()
{
currentFormulaButton(4);
}
