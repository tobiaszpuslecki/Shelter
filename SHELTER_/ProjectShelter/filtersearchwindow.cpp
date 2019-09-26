#include "filtersearchwindow.h"


unsigned int CIDValue = 1;



SQLController SQLController_filterSearch("owners","root","SHELTER", "filterSearchWindow");
Animal animalBuffer;

filterSearchWindow::filterSearchWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::filterSearchWindow)
{
    ui->setupUi(this);

    SQLController_filterSearch.getAnimalData(CIDValue,animalBuffer);
    ui->lineEditCID->setText(QString::number(CIDValue));
    ui->labelAnimalType->setText(animalBuffer.animalType);
    ui->labelName->setText(animalBuffer.name);
    ui->labelSex->setText(animalBuffer.sex);
    ui->labelBreed->setText(animalBuffer.breed);
    ui->labelBoxNumber->setText(animalBuffer.boxNumber);
    ui->labelFoundDate->setText(animalBuffer.foundDate);

    ui->labelFoundDesantion->setText(animalBuffer.foundStreet);
    ui->labelHasHome->setText(animalBuffer.hasHome);
    ui->labelHasDisease->setText(animalBuffer.hasDisease);
    ui->labelDiseaseName->setText(animalBuffer.diseaseName);
    ui->labelEyeColour->setText(animalBuffer.eyeColour);
    ui->labelHairColour->setText(animalBuffer.hairColour);

}

filterSearchWindow::~filterSearchWindow()
{
    delete ui;
}



void filterSearchWindow::on_pushButtonCancel_clicked()
{
    this->hide();
}

void filterSearchWindow::on_pushButtonLeftArrow_clicked()
{
    if(CIDValue>1)
    {
        CIDValue--;
        SQLController_filterSearch.getAnimalData(CIDValue,animalBuffer);
        ui->lineEditCID->setText(QString::number(CIDValue));
        ui->labelAnimalType->setText(animalBuffer.animalType);
        ui->labelName->setText(animalBuffer.name);
        ui->labelSex->setText(animalBuffer.sex);
        ui->labelBreed->setText(animalBuffer.breed);
        ui->labelBoxNumber->setText(animalBuffer.boxNumber);
        ui->labelFoundDate->setText(animalBuffer.foundDate);

        ui->labelFoundDesantion->setText(animalBuffer.foundStreet);
        ui->labelHasHome->setText(animalBuffer.hasHome);
        ui->labelHasDisease->setText(animalBuffer.hasDisease);
        ui->labelDiseaseName->setText(animalBuffer.diseaseName);
        ui->labelEyeColour->setText(animalBuffer.eyeColour);
        ui->labelHairColour->setText(animalBuffer.hairColour);



    }
}

void filterSearchWindow::on_pushButtonRightArrow_clicked()
{
    if( !((CIDValue+1)>SQLController_filterSearch.getMaxCID()) )
    {
        CIDValue++;
        SQLController_filterSearch.getAnimalData(CIDValue,animalBuffer);
        ui->lineEditCID->setText(QString::number(CIDValue));
        ui->labelAnimalType->setText(animalBuffer.animalType);
        ui->labelName->setText(animalBuffer.name);
        ui->labelSex->setText(animalBuffer.sex);
        ui->labelBreed->setText(animalBuffer.breed);
        ui->labelBoxNumber->setText(animalBuffer.boxNumber);
        ui->labelFoundDate->setText(animalBuffer.foundDate);

        ui->labelFoundDesantion->setText(animalBuffer.foundStreet);
        ui->labelHasHome->setText(animalBuffer.hasHome);
        ui->labelHasDisease->setText(animalBuffer.hasDisease);
        ui->labelDiseaseName->setText(animalBuffer.diseaseName);
        ui->labelEyeColour->setText(animalBuffer.eyeColour);
        ui->labelHairColour->setText(animalBuffer.hairColour);
    }
}

void filterSearchWindow::on_pushButtonSearch_clicked()
{
    unsigned int tempCIDValue = ui->lineEditCID->text().toInt();

    if(tempCIDValue>0 && tempCIDValue<=SQLController_filterSearch.getMaxCID())
    {
        CIDValue = tempCIDValue;
        SQLController_filterSearch.getAnimalData(CIDValue,animalBuffer);
        ui->lineEditCID->setText(QString::number(CIDValue));
        ui->labelAnimalType->setText(animalBuffer.animalType);
        ui->labelName->setText(animalBuffer.name);
        ui->labelSex->setText(animalBuffer.sex);
        ui->labelBreed->setText(animalBuffer.breed);
        ui->labelBoxNumber->setText(animalBuffer.boxNumber);
        ui->labelFoundDate->setText(animalBuffer.foundDate);

        ui->labelFoundDesantion->setText(animalBuffer.foundStreet);
        ui->labelHasHome->setText(animalBuffer.hasHome);
        ui->labelHasDisease->setText(animalBuffer.hasDisease);
        ui->labelDiseaseName->setText(animalBuffer.diseaseName);
        ui->labelEyeColour->setText(animalBuffer.eyeColour);
        ui->labelHairColour->setText(animalBuffer.hairColour);

    }
    else
    {
        QMessageBox::information(this,"BŁĄD!","Nie ma takiego CID!");

    }
}
