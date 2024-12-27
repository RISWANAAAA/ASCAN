#ifndef ADDDOCTOR_H
#define ADDDOCTOR_H

#include <QDialog>

namespace Ui {
class AddDoctor;
}

class AddDoctor : public QDialog
{
    Q_OBJECT

public:
    explicit AddDoctor(QWidget *parent = nullptr);
    ~AddDoctor();

private:
    Ui::AddDoctor *ui;
};

#endif // ADDDOCTOR_H
