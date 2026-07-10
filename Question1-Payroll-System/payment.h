#ifndef PAYMENT_H
#define PAYMENT_H

#include <QString>
class Payment
{
public:
    Payment(QString typ);
    QString getType() const;
    virtual double pay() = 0;
protected:
    QString type;
};

#endif // PAYMENT_H
