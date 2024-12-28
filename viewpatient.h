#ifndef VIEWPATIENT_H
#define VIEWPATIENT_H

#include <QDialog>

namespace Ui {
class viewpatient;
}

class viewpatient : public QDialog
{
    Q_OBJECT

public:
    explicit viewpatient(QWidget *parent = nullptr);
    ~viewpatient();
    void viewPatdata(const QString &id,const QString &name,const QString &age,const QString &gender,const QString &number,const QString &opmethod,const QString &opmode,const QString &eye);

private slots:
    void on_ButOk_clicked();

private:
    Ui::viewpatient *ui;
};

#endif // VIEWPATIENT_H
