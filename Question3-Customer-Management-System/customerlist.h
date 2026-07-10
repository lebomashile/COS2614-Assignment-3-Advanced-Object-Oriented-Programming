#ifndef CUSTOMERLIST_H
#define CUSTOMERLIST_H

#include <QList>
#include <QString>
#include <QMap>
#include "customer.h"

class CustomerList : public QList<Customer*>
{
public:
    ~CustomerList();
    bool add(Customer *c);
    Customer *findByID(QString id);
    QList<Customer*> findByName(QString name);
    QList<Customer*> findByDPC(QString dpc);
    bool remove(Customer *c);

private:
    QMap<QString,Customer*> idMap;
    QMultiMap<QString,Customer*> nameMap;
    QMultiMap<QString,Customer*> dpcMap;
};

#endif // CUSTOMERLIST_H
