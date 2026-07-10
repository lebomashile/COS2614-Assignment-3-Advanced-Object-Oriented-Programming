#ifndef COMMISSION_H
#define COMMISSION_H

#include "payment.h"

class Commission : public Payment
{
public:
    Commission(double cr);
    void addSales(double sv);
    double pay();
private:
    double commissionRate;
    double totalSales;
};

#endif // COMMISSION_H
