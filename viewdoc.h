#ifndef VIEWDOC_H
#define VIEWDOC_H

#include <QDialog>

namespace Ui {
class viewdoc;
}

class viewdoc : public QDialog
{
    Q_OBJECT

public:
    explicit viewdoc(QWidget *parent = nullptr);
    ~viewdoc();

private:
    Ui::viewdoc *ui;
};

#endif // VIEWDOC_H
