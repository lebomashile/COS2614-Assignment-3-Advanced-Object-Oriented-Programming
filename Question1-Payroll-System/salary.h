#ifndef SALARY_H
#define SALARY_H

#include "payment.h"

class Salary : public Payment
{
public:
    Salary(double sal);
    double pay() override;

    Payment* clone() const override
    {
        return new Salary(*this);
    }

private:
    double salary;
};

#endif // SALARY_H
