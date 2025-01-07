#ifndef INTKEYPAD_H
#define INTKEYPAD_H

#include <QDialog>

namespace Ui {
class intkeypad;
}

class intkeypad : public QDialog
{
    Q_OBJECT

public:
    explicit intkeypad(QWidget *parent = nullptr);
    ~intkeypad();
    QString digit;
    QString text1;
signals:
    void textsignal(const QString& digit);
    //void backsignal();
    void entersignal();
    void backsignal();

private slots:
    void entertext();
    //void enterback();
    void enterenter();
    void enterback();

private:
    Ui::intkeypad *ui;
    QString inputText;

};

#endif // INTKEYPAD_H
