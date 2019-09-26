#include "adoptionwindow.h"

SQLController SQLController_adoption("owners","root","SHELTER", "adoptionWindow");



adoptionWindow::adoptionWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adoptionWindow)
{
    ui->setupUi(this);
}

adoptionWindow::~adoptionWindow()
{
    delete ui;
}

void adoptionWindow::on_pushButtonCancel_clicked()
{
    this->hide();
}

void adoptionWindow::on_pushButtonConfirm_clicked()
{





    if(ui->lineEditCID->text().isEmpty()) QMessageBox::information(this,"BŁĄD!","Nie podano CID!");
    else if(ui->lineEditName->text().isEmpty()) QMessageBox::information(this,"BŁĄD!","Nie podano imienia adoptująceco!");
    else if(ui->lineEditSurname->text().isEmpty()) QMessageBox::information(this,"BŁĄD!","Nie podano nazwiska adoptującego!");
    else if(ui->lineEditPhoneNumber->text().isEmpty()) QMessageBox::information(this,"BŁĄD!","Nie podano numeru telefonu!");

    else
    {

        if(!SQLController_adoption.getNumberOf("cid",ui->lineEditCID->text().toInt()))
            QMessageBox::information(this,"BŁĄD!","Nie ma takiego CID!");
        else
        {
            Owner adoptionOwner(ui->lineEditCID->text(),ui->lineEditName->text(),ui->lineEditSurname->text(),ui->lineEditPhoneNumber->text());
            adoptionOwner.sendToBase();

            this->hide();
        }
    }






}
