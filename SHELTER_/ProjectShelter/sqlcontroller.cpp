#include "sqlcontroller.h"
#include "shelter.h"


SQLController::SQLController(QString name, QString usr, QString pwd, QString conName)
{
            db = QSqlDatabase::addDatabase("QMYSQL", conName);
            db.setHostName("localhost");
            db.setDatabaseName(name);
            db.setUserName(usr);
            db.setPassword(pwd);


            if (!db.open())
            {
                isOpen = false;
                qDebug() << conName <<": Error: Cannot connect to database!";
            }
            else
            {
                isOpen = true;
                qDebug() << conName <<": Connection established.";
            }
}



bool SQLController::getIsOpen()
{
     return isOpen ? true : false;
}


unsigned int SQLController::getMaxCID()
{
    QSqlQuery download(db);
    download.exec("USE animals");
    download.exec("SET @max_cid=0");
    download.exec("SET @max_cid = (SELECT COUNT(*) FROM animal)+1");
    download.exec("SELECT @max_cid");
    int maxCID;
    while (download.next())
    {
       maxCID = download.value(0).toInt();
       //qDebug()  << maxCID;
    }

    return maxCID;

}

int SQLController::getNumberOf(QString type, int cid)
{
    int counter;
    QSqlQuery download(db);

    download.exec("USE animals");
    if(type=="cats")
        download.exec("SELECT COUNT(hasHome) FROM animal WHERE hasHome='N' AND animalType='C';");
    else if(type=="dogs")
        download.exec("SELECT COUNT(hasHome) FROM animal WHERE hasHome='N' AND animalType='D';");
    else // if type == cid
    {
        QString cidString = QString::number(cid);
        download.exec("SELECT COUNT(cid) FROM animal WHERE cid="+cidString);
    }


    while (download.next())
    {
        counter = download.value(0).toInt();
        qDebug() << "Counter for " <<  type << " = " << counter;
    }

    return counter;
}

void SQLController::makeAdoption(QString cid, QString name, QString surname, QString phone)
{
    QSqlQuery upload(db);

    upload.exec("USE animals");
    upload.exec("UPDATE animal SET boxNumber=0 WHERE cid="+cid);
    upload.exec("UPDATE animal SET hasHome='Y' WHERE cid="+cid);
    upload.exec("USE owners");

    upload.exec("INSERT INTO owner (cid, name, surname, phone) VALUES("+cid+ ", '"+name+"', '"+surname+"', '"+phone+"')");

}


QString SQLController::manualMode(QString cmd)
{
    QSqlQuery query(db);
    QString str;

    query.exec(cmd);

        while(query.next())
        {
            for(int i=0; i<query.size()-1;i++)
            {
                qDebug() << i << ". " << query.value(i);
                str=str+" "+query.value(i).toString();
            }
            str+="/n";
            qDebug() << "Number of Rows: " << query.size();

        }


    return str;

}

void SQLController::getOwnerData(QString cid, Owner& o)
{
    QSqlQuery download(db);


    download.exec("USE owners");
    download.exec("SELECT * FROM owner WHERE cid="+cid);

   while(download.next())
   {
           o.name = download.value(1).toString();
           o.surname =  download.value(2).toString();
           o.phone = download.value(3).toString();
   }


}

void SQLController::getAnimalData(int cid, Animal& a)
{
    QSqlQuery download(db);
    QString cid_ = QString::number(cid);



    download.exec("USE animals");
    download.exec("SELECT * FROM animal WHERE cid="+cid_);

   while(download.next())
   {
           a.animalType = download.value(1).toString();
           a.name = download.value(2).toString();
           a.sex = download.value(3).toString();
           a.breed = download.value(4).toString();
           a.boxNumber = download.value(5).toString();
           a.foundDate = download.value(6).toString();
           a.foundStreet = download.value(7).toString();
           a.hasDisease = download.value(8).toString();
           a.diseaseName = download.value(9).toString();
           a.hairColour = download.value(10).toString();
           a.eyeColour = download.value(11).toString();
           a.hasHome    = download.value(12).toString();

   }
}


void SQLController::Upload(QString cmd)
{
    db.exec(cmd);
}
