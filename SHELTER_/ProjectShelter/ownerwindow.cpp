#include "ownerwindow.h"


SQLController SQLController_owner("owners","root","SHELTER", "ownerWindow");


ownerWindow::ownerWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ownerWindow)
{
    ui->setupUi(this);
}

ownerWindow::~ownerWindow()
{
    delete ui;
}

void ownerWindow::on_pushButtonCancel_clicked()
{
    this->hide();
}

void ownerWindow::on_pushButtonConfirm_clicked()
{

    Owner ownerBuffer;
    SQLController_owner.getOwnerData(ui->lineEditCID->text(),ownerBuffer);

    ui->labelName->setText(ownerBuffer.name);
    ui->labelSurname->setText(ownerBuffer.surname);
    ui->labelPhone->setText(ownerBuffer.phone);

}
