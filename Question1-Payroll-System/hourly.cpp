#include "hourly.h"

Hourly::Hourly(double hr)
    : Payment("Hourly"),
    hourlyRate(hr),
    hours(0.0)
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
