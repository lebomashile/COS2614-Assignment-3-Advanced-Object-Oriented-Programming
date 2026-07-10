#include "hourly.h"

Hourly::Hourly(double hr)
    :Payment("Hourly"),
    hours(0.0),
    hourlyRate(hr)
{

}

void Hourly::addHours(double hrs)
{
    hours += hrs;
}

double Hourly::pay()
{
    return hourlyRate * hours;
}
