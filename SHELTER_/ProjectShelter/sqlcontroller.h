#ifndef SQLCONTROLLER_H
#define SQLCONTROLLER_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QString>
#include <QTextBrowser>
#include "shelter.h"


class SQLController
{
public:
    QSqlDatabase db;
    bool isOpen = false;



        SQLController(QString name, QString usr, QString pwd, QString conName);
        void Upload(QString cmd);
        bool getIsOpen();
        unsigned int getMaxCID();
        int getNumberOf(QString type, int cid=0);
        void makeAdoption(QString cid, QString name, QString surname, QString phone);
        QString manualMode(QString cmd);
        void getOwnerData(QString cid, Owner &o);
        void getAnimalData(int cid, Animal& a);




};


#endif // SQLCONTROLLER_H
