#include "loginwindow.h"

#include <QFile>
#include <QTextStream>
#include <fstream>



loginWindow::loginWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loginWindow)
{
    ui->setupUi(this);
}

loginWindow::~loginWindow()
{
    delete ui;
}

void loginWindow::on_pushButtonLogin_clicked()
{

//     QFile passwordFile("/Users/tobing/Desktop/login.txt");
//     if(!passwordFile.open(QIODevice::ReadOnly))
//         QMessageBox::information(this,"BŁĄD!","Błąd odczytu pliku!");
//     QTextStream in(&passwordFile);

//     correct.login=in.readLine();
//     correct.password=in.readLine();

     correct.login="root";
     correct.password="root";

     toCheck.login=ui->lineEditLogin->text();
     toCheck.password=ui->lineEditPassword->text();





     if(toCheck == correct)
     {
         passwordFile.close();
         this->hide(); // hide loginWindow
         mainWindow mainWindow_;
         mainWindow_.exec();
     }
     else
     {
         QMessageBox::information(this,"BŁĄD!","Niepoprawne dane logowania!");
         ui->lineEditLogin->setText("");
         ui->lineEditPassword->setText("");
     }


}

void loginWindow::on_pushButtonExit_clicked()
{
    this->close();
}
