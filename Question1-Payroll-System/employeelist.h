#ifndef EMPLOYEELIST_H
#define EMPLOYEELIST_H

#include <QList>
#include "employee.h"

class EmployeeList : public QList<Employee>
{
public:
    EmployeeList();
};

#endif // EMPLOYEELIST_H
