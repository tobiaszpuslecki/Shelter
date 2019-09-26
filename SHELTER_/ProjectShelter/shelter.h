#ifndef SHELTER_H
#define SHELTER_H

#include <QString>



class Shelter
{
public:
    Shelter();
    virtual void sendToBase() = 0;
    //virtual void edit() = 0;
    QString cid;
    QString name;

};

class Animal : public Shelter
{
public:

    QString sex;
    QString breed;
    QString boxNumber;
    QString foundStreet;
    QString foundDate;
    QString hasHome;
    QString hasDisease;
    QString diseaseName;
    QString eyeColour;
    QString hairColour;
    QString animalType;

    virtual void sendToBase();


};

class Owner : public Shelter
{

    public:
    Owner(QString cid, QString name, QString surname, QString phone);
    Owner();

     virtual void sendToBase();



    QString surname,phone;
};


#endif // SHELTER_H
