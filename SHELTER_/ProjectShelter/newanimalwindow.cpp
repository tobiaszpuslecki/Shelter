#include "newanimalwindow.h"



SQLController SQLController_newAnimal("owners","root","SHELTER", "newAnimalWindowBase");

newAnimalWindow::newAnimalWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::newAnimalWindow)
{
    ui->setupUi(this);


}

newAnimalWindow::~newAnimalWindow()
{
    delete ui;
}



void newAnimalWindow::on_pushButtonCancel_clicked()
{
    this->hide();
}



void newAnimalWindow::on_pushButtonConfirm_clicked()
{


    if(SQLController_newAnimal.getIsOpen())
    {

        if(!ui->radioButtonIsDog->isChecked() && !ui->radioButtonIsCat->isChecked()) QMessageBox::information(this,"BŁĄD!","Nie podano typu zwierzęcia!");
        else if(!ui->radioButtonSexMan->isChecked() && !ui->radioButtonSexWoman->isChecked()) QMessageBox::information(this,"BŁĄD!","Nie podano płci!");
        else if(ui->lineEditName->text().isEmpty()) QMessageBox::information(this,"BŁĄD!","Nie podano imienia tymczasowego!");
        else if(ui->lineEditBoxNumber->text().isEmpty()) QMessageBox::information(this,"BŁĄD!","Nie podano numeru boxu!");
        else if(ui->checkBoxDisease->isChecked() && ui->lineEditDiseaseName->text()=="") QMessageBox::information(this,"BŁĄD!","Nie podano nazwy choroby!");
        else if(ui->lineEditBreed->text().isEmpty()) QMessageBox::information(this,"BŁĄD!","Nie podano rasy!");
        else if(ui->lineEditFoundDate->text().isEmpty()) QMessageBox::information(this,"BŁĄD!","Nie podano daty znalezienia!");
        else if(ui->lineEditFoundStreet->text().isEmpty()) QMessageBox::information(this,"BŁĄD!","Nie podano miejsca znalezienia!");
        else if(ui->lineEditHairColour->text().isEmpty()) QMessageBox::information(this,"BŁĄD!","Nie podano koloru sierści!");
        else if(ui->lineEditEyeColour->text().isEmpty()) QMessageBox::information(this,"BŁĄD!","Nie podano koloru oczu!");




        else
        {


            QString isDog = ui->radioButtonIsDog->isChecked() ? "D" : "C";
            QString isMan = ui->radioButtonSexMan->isChecked() ? "M" : "W";
            QString maxCID = QString::number(SQLController_newAnimal.getMaxCID());
            QString boxNo = QString::number( ui->lineEditBoxNumber->text().toInt() );

            QString hasDisease;
            if(ui->lineEditDiseaseName->text()!="" && ui->checkBoxDisease->isChecked()==false) hasDisease='Y';
            hasDisease = ui->checkBoxDisease->isChecked() ? "Y" : "N";


            Animal newAnimal;
            newAnimal.animalType=isDog;
            newAnimal.boxNumber=boxNo;
            newAnimal.breed=ui->lineEditBreed->text();
            newAnimal.cid=maxCID;
            newAnimal.diseaseName=ui->lineEditDiseaseName->text();
            newAnimal.eyeColour=ui->lineEditEyeColour->text();
            newAnimal.foundDate=ui->lineEditFoundDate->text();
            newAnimal.foundStreet=ui->lineEditFoundStreet->text();
            newAnimal.hairColour=ui->lineEditHairColour->text();
            newAnimal.hasDisease=hasDisease;
            newAnimal.hasHome="N";
            newAnimal.name=ui->lineEditName->text();
            newAnimal.sex=isMan;



            newAnimal.sendToBase();



            this->hide();
        }
    }
    else
    {
        QMessageBox::information(this,"BŁĄD!","Błąd bazy danych!");
    }
}
