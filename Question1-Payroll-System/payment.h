#ifndef PAYMENT_H
#define PAYMENT_H

#include <QString>
class Payment
{
public:
    Payment(QString typ);
    virtual ~Payment() = default;

    QString getType() const;
    virtual double pay() = 0;

    virtual Payment* clone() const = 0;

protected:
    QString type;
};

#endif // PAYMENT_H
