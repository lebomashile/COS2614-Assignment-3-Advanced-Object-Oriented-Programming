#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <QString>
#include <QStringList>
class Customer
{
public:
    Customer();
    Customer(QString name, QString ID);
    Customer(QString name, QString ID, QStringList addr);
    QString toString(bool labelled)const;
    void setAddress(bool isDpc, QString addr, QString sepCharacter);
    QString getName()const;
    QString getID()const;
    QString getAddress()const;
private:
    QString m_Name;
    QString m_ID;
    QStringList m_Address;
};

#endif // CUSTOMER_H
