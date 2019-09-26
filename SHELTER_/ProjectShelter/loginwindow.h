#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QDialog>
#include "ui_loginwindow.h"
#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>


struct LoginData
{
  QString login;
  QString password;

  bool operator ==(const LoginData & ld)
  {
      if(( password == ld.password ) &&( login == ld.login ) )
           return true;
      else
           return false;

  }

};









namespace Ui {
class loginWindow;
}

class loginWindow : public QDialog
{
    Q_OBJECT

public:
    explicit loginWindow(QWidget *parent = 0);
    ~loginWindow();


private slots:
    void on_pushButtonLogin_clicked();

    void on_pushButtonExit_clicked();

private:
    Ui::loginWindow *ui;

    LoginData correct;
    LoginData toCheck;


};

#endif // LOGINWINDOW_H
