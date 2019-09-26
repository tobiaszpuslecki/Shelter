#include "mainwindow.h"

SQLController SQLController_("owners","root","SHELTER", "mainWindowBase");


mainWindow::mainWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mainWindow)
{
    ui->setupUi(this);

    ui->labelVersionNumber->setText("ver. 1.0a");
    ui->labelCompilationDate->setText(__DATE__);

    if(SQLController_.getIsOpen())
    {
       ui->labelBaseConnectionStatus->setText("<font color='green'>OK</font>");

       ui->lcdNumberDogs->display(SQLController_.getNumberOf("dogs"));
       ui->lcdNumberCats->display(SQLController_.getNumberOf("cats"));
    }
    else
    {
        disabledAllButtons();

        ui->labelBaseConnectionStatus->setText("<font color='red'>BŁĄD!</font>");
    }

}

mainWindow::~mainWindow()
{
    delete ui;
}

void mainWindow::on_pushButtonExit_clicked()
{
    this->close();
}

void mainWindow::on_pushButtonFound_clicked()
{
    newAnimalWindow newAnimalWindow_;
    newAnimalWindow_.exec();
}

void mainWindow::on_pushButtonAdoption_clicked()
{
    adoptionWindow adoptionWindow_;
    adoptionWindow_.exec();
}

void mainWindow::disabledAllButtons()
{
    ui->pushButtonAdoption->setEnabled(false);
    ui->pushButtonFilterSearch->setEnabled(false);
    ui->pushButtonFound->setEnabled(false);
    ui->pushButtonOwner->setEnabled(false);
    ui->pushButtonManualMode->setEnabled(false);
}

void mainWindow::on_pushButtonFilterSearch_clicked()
{
    filterSearchWindow filterSearchWindow_;
    filterSearchWindow_.exec();
}

void mainWindow::on_pushButton_clicked()
{
    manualModeWindow manualModeWindow_;
    manualModeWindow_.exec();
}

void mainWindow::on_pushButtonOwner_clicked()
{
    ownerWindow ownerWindow_;
    ownerWindow_.exec();
}
