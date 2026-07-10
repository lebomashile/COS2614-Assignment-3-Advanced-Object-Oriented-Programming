// Lebohang Mashile
// 10089039

#include <QCoreApplication>
#include "employeelist.h"
#include "hourly.h"
#include "commission.h"
#include "salary.h"
#include <QTextStream>

QTextStream cout(stdout);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Employee employee1("Lerato", "Jiyane");
    Employee employee2("Omega", "Ngwenya");
    Employee employee3("Katlego", "Moloko");
    Employee employee4("Angel", "Nkosi");
    Employee employee5("Nokulunga", "Mbatha");
    Employee employee6("Lucian", "Almighty");

    EmployeeList employeelist;

    Hourly *h1 = new Hourly(456);
    Hourly *h2 = new Hourly(234);
    Commission *c1 = new Commission(353);
    Commission *c2 = new Commission(536);

    h1->addHours(55);
    h2->addHours(23);
    c1->addSales(53);
    c2->addSales(76);

    Payment *payment1 = new Salary(8000);
    Payment *payment2 = new Salary(7000);
    Payment *payment3 = h1;
    Payment *payment4 = h2;
    Payment *payment5 = c1;
    Payment *payment6 = c2;

    employee1.setPayment(payment1);
    employee2.setPayment(payment2);
    employee3.setPayment(payment3);
    employee4.setPayment(payment4);
    employee5.setPayment(payment5);
    employee6.setPayment(payment6);

    Employee copy(employee6);

    employeelist.append(employee1);
    employeelist.append(employee2);
    employeelist.append(employee3);
    employeelist.append(employee4);
    employeelist.append(employee5);
    employeelist.append(copy);

    for(int i = 0 ; i < employeelist.size();i++)
    {
     cout << "Name:" << employeelist.at(i).getName()
          << ",ID:" << employeelist.at(i).getID()
          <<",Payment Type:"
          <<employeelist.at(i).getPayment()->getType()
          <<",Pay:" << employeelist.at(i).getPayment()->pay() << endl;
    }
cout.flush();

    return a.exec();
}
