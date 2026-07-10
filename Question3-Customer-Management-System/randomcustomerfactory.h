#ifndef RANDOMCUSTOMERFACTORY_H
#define RANDOMCUSTOMERFACTORY_H
#include "customer.h"

class RandomCustomerFactory{
public:
    RandomCustomerFactory();
    //returns a random contact
    Customer* getAContact();
private:
    //data members
    QStringList firstNames;
    QStringList lastNames;   
    QStringList streetAddresses;
    QStringList cities;
    QStringList zipCodes;

    void initializeFirstNames();
    void initializeLastNames();
    void initializeStreetAddresses();
    void initializeCities();
    void initializeZipCodes();
    QString generateID();
};

#endif // RANDOMCUSTOMERFACTORY_H
