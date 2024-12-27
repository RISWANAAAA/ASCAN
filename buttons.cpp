#include "buttons.h"
#include "ui_buttons.h"
#include <QDebug>

Buttons::Buttons(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Buttons),
    currentButtonIndex(0),
    swipeDirection(0)
{
    ui->setupUi(this);
    move(0, 0);
    QSqlDatabase mydb1 = QSqlDatabase::addDatabase("QSQLITE");
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
}

Buttons::~Buttons()
{
    delete ui;
}

void Buttons::mousePressEvent(QMouseEvent *event)
{
    lastMousePosition = event->pos();
    qDebug() << "Mouse pressed";
}

void Buttons::mouseMoveEvent(QMouseEvent *event)
{
    // Detect swipe direction
    if (event->buttons() & Qt::LeftButton) {
        int deltaX = event->pos().x() - lastMousePosition.x();

        if (deltaX > 10) { // Swipe right
            swipeDirection = 1;
            qDebug() << "Swiped right";
        } else if (deltaX < -10) { // Swipe left
            swipeDirection = -1;
            qDebug() << "Swiped left";
        }
    }
    lastMousePosition = event->pos();
}

void Buttons::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event); // Suppress unused parameter warning

    // Update button index based on swipe direction
    if (swipeDirection == 1) { // Swipe right
        currentButtonIndex = (currentButtonIndex < 6) ? currentButtonIndex + 1 : 0;
        qDebug() << "Swiped right, new index:" << currentButtonIndex;
    } else if (swipeDirection == -1) { // Swipe left
        currentButtonIndex = (currentButtonIndex > 0) ? currentButtonIndex - 1 : 6;
        qDebug() << "Swiped left, new index:" << currentButtonIndex;
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
        model->select();
      ui->tableView->setGeometry(0,30, 1280,600);  // Example position and size
        ui->tableView->setModel(model);
        ui->tableView->resizeColumnsToContents();
        // Adjust position (move down by 20 pixels)
          QRect geometry = ui->tableView->geometry();
          geometry.moveTop(geometry.top() + 5);  // Move the tableView 20 pixels down
          ui->tableView->setGeometry(geometry);
          // Add spacing between columns
            int columnCount = model->columnCount();
            for (int i = 0; i < columnCount; ++i) {
                int currentWidth = ui->tableView->columnWidth(i);
                ui->tableView->setColumnWidth(i, currentWidth + 10); // Add 10 pixels of extra width for spacing
            }

}

void Buttons::loaddoctorsql()
{

    QSqlDatabase db = QSqlDatabase::database();
    QSqlTableModel *model = new QSqlTableModel(this, db);
    model->setTable("ascandoctor");  // Patient table name
    model->select();
  ui->tableView_2->setGeometry(0,30, 1280,600);  // Example position and size
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
  ui->tableView_3->setGeometry(0,30, 1280,600);  // Example position and size
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
