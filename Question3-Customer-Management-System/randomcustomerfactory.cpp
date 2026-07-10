#include <QDebug>
#include <QtGlobal>
#include <QTime>
#include "randomcustomerfactory.h"

RandomCustomerFactory::RandomCustomerFactory(){
    initializeFirstNames();
    initializeLastNames();
    initializeStreetAddresses();
    initializeCities();
    initializeZipCodes();
    qsrand(QTime::currentTime().msec());
}

void RandomCustomerFactory::initializeFirstNames(){
    firstNames<< "AB" << "CD" << "FF" << "G" << "Ann"
               << "Leo" << "Mathe" << "Marthe" << "Lata"
               << "Mersault" << "Gerald" << "Tonic" << "Tom" << "Anna" << "Hilda";
}

void RandomCustomerFactory::initializeLastNames(){
    lastNames << "Botha" << "Viljoen" << "Kotze" << "Mentz"
             << "van der Merwe" << "Naidoo" << "Liang"
             << "Kritzinger" << "Becker" << "Lubbe" << "Engelbrecht"
             << "Schoeman"<< "Horne" << "Eloff" << "Selati";
}

void RandomCustomerFactory::initializeStreetAddresses(){
    streetAddresses << "32 Menlyn" << "1 Kelvin" << "74 - 23rd street"
                    << "100 Lion" << "3 Protea Road" << "302 Muskejaat"
                    << "45 Lois Street" << "100 skillpad" << "29 Atterbury Road"
                    << "567 Selati Street" << "34 Preller Street" << "75 Puzzle Road"
                    <<"100 Endless Street" << "45 Leask Street" << "786 Good Hope";
}

void RandomCustomerFactory::initializeCities(){
    cities << "Pretoria" << "Victoria" << "East City"
           << "West Rand" << "Potchefstroom" << "Mogale City"
           << "Cape City" << "Milton" << "Port Elizebath"
           << "Klersdorp" << "Krugersdorp" << "Randburg"
           << "Florida" << "Randfontein" << "Ventersdorp";
}

void RandomCustomerFactory::initializeZipCodes(){
    zipCodes << "0001" << "0010" << "0100" << "1000"
             << "1001" << "1010" << "1100" << "1101"
             << "1110" << "1111" << "1002"<< "1003"
             << "3045" << "1005" << "0003";
}

Customer* RandomCustomerFactory::getAContact(){
    QString sepCharacter = ",";
    QString randomFName = firstNames.at((qrand() % (firstNames.size() + 0)));
    QString randomLName = lastNames.at((qrand() % (lastNames.size() + 0)));
    QString randomName = QString("%1 %2")
                         .arg(randomFName)
                         .arg(randomLName);
    QString randomUniqueID = generateID();
    QString randomAddress = QString("%1%2%3%4%5")
                            .arg(streetAddresses.at((qrand() % (streetAddresses.size() + 0))))
                            .arg(sepCharacter)
                            .arg(cities.at((qrand() % (cities.size() + 0))))
                            .arg(sepCharacter)
                            .arg(zipCodes.at((qrand() % (zipCodes.size() + 0))));

    Customer* randomCust = new Customer(randomName, randomUniqueID);
    randomCust->setAddress(true,randomAddress,sepCharacter);
    randomCust->setAddress(false,randomAddress,sepCharacter);
    return randomCust;
}

QString RandomCustomerFactory::generateID(){
    int randomID = qrand() % ((9999 + 1) - 1111) + 1111;
    return QString::number(randomID);
}


