#include "manualmodewindow.h"



SQLController SQLController_manualMode("owners","root","SHELTER","manualMode");


manualModeWindow::manualModeWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::manualModeWindow)
{
    ui->setupUi(this);
}

manualModeWindow::~manualModeWindow()
{
    delete ui;
}

void manualModeWindow::on_pushButtonExit_clicked()
{
    this->hide();
}

void manualModeWindow::on_pushButtonConfirm_clicked()
{
    ui->textBrowser->setText("");
    ui->textBrowser->append(SQLController_manualMode.manualMode(ui->lineEditCommand->text()));
    ui->lineEditCommand->setText("");
}
