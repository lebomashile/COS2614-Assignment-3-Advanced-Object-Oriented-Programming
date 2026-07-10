#include "customer.h"

Customer::Customer()
    :m_Name(""),
    m_ID("")
{
    m_Address.clear();
}

Customer::Customer(QString name, QString ID)
    :m_Name(name),
    m_ID(ID){

}

Customer::Customer(QString name, QString ID, QStringList addr)
    :m_Name(name),
    m_ID(ID),
    m_Address(addr)
{

}


QString Customer::toString(bool labelled) const
{

    return QString("Name:%1,ID:%2,Address:%3").arg(m_Name, m_ID,getAddress());
}

void Customer::setAddress(bool isDpc, QString addr, QString sepCharacter)
{
    QStringList str;
    str = addr.split(sepCharacter);

    m_Address = str;
}

QString Customer::getName() const
{
    return m_Name;
}

QString Customer::getID() const
{
    return m_ID;
}

QString Customer::getAddress() const
{
    QString a;

    for(int i = 0 ; i < m_Address.size(); i++)
        a += m_Address.at(i) + " ";

    return a;
}

