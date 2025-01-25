#ifndef TEXTKEYPAD_H
#define TEXTKEYPAD_H

#include <QDialog>
#include<QLineEdit>
namespace Ui {
class textkeypad;
}

class textkeypad : public QDialog
{
    Q_OBJECT

public:
    explicit textkeypad(QWidget *parent = nullptr);
    ~textkeypad();
    QString digit;


signals:
   void textsignal(const QString& digit);
   void backsignal();
  void spacesignal();
   void entersignal();
private slots:
    void entertext();
    void enterback();
 //   void spaceenter(QLineEdit* lineEdit);
    void enterenter();
    void on_ButUpper_Lower_clicked();

    void on_ButEnter_clicked();

    void on_ButBack_clicked();

    void on_ButBackSpace_clicked();

private:
    Ui::textkeypad *ui;
    bool isLowercaseMode;
bool isFirstClick = true;
QString currentText = "";
};

#endif // TEXTKEYPAD_H
