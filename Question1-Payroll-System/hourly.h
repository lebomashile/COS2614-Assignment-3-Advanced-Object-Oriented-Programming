#ifndef HOURLY_H
#define HOURLY_H

#include "payment.h"

class Hourly : public Payment
{
public:
    Hourly(double hr);
    void addHours(double hrs);
    double pay();
private:
    double hourlyRate;
    double hours;
};

#endif // HOURLY_H
