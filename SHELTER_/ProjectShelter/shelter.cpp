#include "shelter.h"
#include "sqlcontroller.h"

Shelter::Shelter()
{
}


Owner::Owner(QString cid, QString name, QString surname, QString phone)
{
    this->cid=cid;
    this->name=name;
    this->surname=surname;
    this->phone=phone;
}
Owner::Owner()
{

}


void Owner::sendToBase()
{
   SQLController SQLController_temp("owners","root","SHELTER", "temporary");
   SQLController_temp.makeAdoption(this->cid,this->name,this->surname,this->phone);

}

void Animal::sendToBase()
{

    QString cmd = "USE animals; INSERT INTO animal (cid, animalType, name, sex, breed, boxNumber, foundDate, foundStreet,hasDisease, diseaseName, colourHair, colourEye, hasHome) VALUES ";
    cmd=cmd+'('+this->cid+", '"+this->animalType+"', '"+this->name+"', '"+this->sex+"', '";
    cmd=cmd+this->breed+"', '"+this->boxNumber+"', '";
    cmd=cmd+this->foundDate+"', '"+this->foundStreet+"', '";
    cmd=cmd+this->hasDisease+"', '"+this->diseaseName+"', '"+this->hairColour+"', '";
    cmd=cmd+this->eyeColour+"', 'N')";

    SQLController SQLController_temp("owners","root","SHELTER", "temporary");
    SQLController_temp.Upload(cmd);


}

