#include "salary.h"

Salary::Salary(double sal)
    : Payment("Salary"),
    salary(sal) {

}

double Salary::pay()
{
    return salary;
}
