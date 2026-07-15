#include "employee.h"

int Employee::nextID = 1000;

Employee::Employee(QString fn, QString sn)
    : firstName(fn),
    surname(sn),
    payment(nullptr)
{
    nextID++;
    id = nextID;
}

Employee::Employee(const Employee &e)
    : id(e.id),
    firstName(e.firstName),
    surname(e.surname)
{
    payment = (e.payment != nullptr) ? e.payment->clone() : nullptr;


}

Employee& Employee::operator=(const Employee &e)
{
    if (this != &e)
    {
        delete payment;

        firstName = e.firstName;
        surname = e.surname;
        id = e.id;

        payment = (e.payment != nullptr)
                      ? e.payment->clone()
                      : nullptr;
    }

    return *this;

}
Employee::~Employee()
{
    delete payment;
}

int Employee::getID() const
{
    return id;
}

QString Employee::getName() const
{
    return firstName + " " + surname;
}

void Employee::setPayment(Payment *pay)
{
    payment = pay;
}

Payment *Employee::getPayment() const
{
    return payment;
}
