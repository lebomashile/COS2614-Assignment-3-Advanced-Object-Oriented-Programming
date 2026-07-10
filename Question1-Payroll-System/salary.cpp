#include "salary.h"

Salary::Salary(double sal)
    :salary(sal),
    Payment("Salary") {

}

double Salary::pay()
{
    return salary;
}
