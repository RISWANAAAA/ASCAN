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
  void viewdocdetails(const QString &id,const QString &name,const QString &lens1,const QString &lens2,const QString &lens3,const QString &formula);

private slots:
  void on_BUTOK_clicked();

private:
    Ui::viewdoc *ui;
};

#endif // VIEWDOC_H
