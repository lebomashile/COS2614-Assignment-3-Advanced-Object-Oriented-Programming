#ifndef COMMISSION_H
#define COMMISSION_H

#include "payment.h"

class Commission : public Payment
{
public:
    Commission(double cr);
    void addSales(double sv);
    double pay() override;

    Payment* clone() const override
    {
        return new Commission(*this);
    }

private:
    double commissionRate;
    double totalSales;
};

#endif // COMMISSION_H
