#include "customerlist.h"
#include <QDebug>

CustomerList::~CustomerList()
{
    qDeleteAll(*this);
}

bool CustomerList::add(Customer *c)
{
    if(findByID(c->getID()) != 0)
        return false;

    this->append(c);

    QString postalCode = c->getAddress();
    postalCode.remove(0, postalCode.size() - 5);

    idMap.insert(c->getID(), c);
    nameMap.insert(c->getName(),c);
    dpcMap.insert(postalCode,c);

    return true;
}

Customer *CustomerList::findByID(QString id)
{
    return idMap.value(id, 0);
}

QList<Customer *> CustomerList::findByName(QString name)
{
    return nameMap.values(name);
}

QList<Customer *> CustomerList::findByDPC(QString dpc)
{

    return dpcMap.values(dpc + " ");
}


bool CustomerList::remove(Customer *c)
{
    QString id = c->getID();

    if(findByID(id) == 0)
        return false;

    this->removeOne(c);
    idMap.remove(id);
    nameMap.remove(c->getName(),c);
    dpcMap.remove(c->getAddress(),c);

    return true;

}


