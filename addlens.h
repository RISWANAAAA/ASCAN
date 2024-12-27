#ifndef ADDLENS_H
#define ADDLENS_H

#include <QDialog>

namespace Ui {
class AddLens;
}

class AddLens : public QDialog
{
    Q_OBJECT

public:
    explicit AddLens(QWidget *parent = nullptr);
    ~AddLens();

private:
    Ui::AddLens *ui;
};

#endif // ADDLENS_H
