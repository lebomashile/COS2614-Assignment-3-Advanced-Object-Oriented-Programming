#include "commission.h"

Commission::Commission(double cr)
    :Payment("Commission"),
    commissionRate(cr),
    totalSales(0.0){

}

void Commission::addSales(double sv)
{
    totalSales += sv;
}

double Commission::pay()
{
    return commissionRate * totalSales;
}
