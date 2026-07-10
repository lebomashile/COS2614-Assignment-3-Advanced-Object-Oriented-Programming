//Lebohang Mashile
//10089039

#include <QCoreApplication>
#include "customerlist.h"
#include <QTextStream>
#include "randomcustomerfactory.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QTextStream cout(stdout);
    QTextStream cin(stdin);
    QString id, name, postalCode;

    RandomCustomerFactory randomGenerator;
    CustomerList customerList;
    Customer *customer[10];

    for(int i = 0 ; i < 10; i++)
        customer[i] = randomGenerator.getAContact();


    for(int i = 0 ; i < 10; i++)
        if(customerList.add(customer[i]))
            cout << "Add Successful ->" <<  customer[i]->toString(true) <<endl;
        else
            cout << "Add Failed ->" <<  customer[i]->toString(true) <<endl;



    cout << "Search by ID:";
    cout.flush();
    id = cin.readLine();


    if(customerList.findByID(id) != 0)
        cout << customerList.findByID(id)->toString(true);
    else
        cout << "Customer not found";

    cout << endl << "Search by name:";
    cout.flush();
    name = cin.readLine();

    QList<Customer*> nameList = customerList.findByName(name);

    if(nameList.size() > 0)
    foreach(Customer *c, nameList)
        if(c != 0)
            cout  << c->toString(true) << endl;

    else
            cout << "Customer not found" << endl;

    cout << endl << "Search by dpc:";
    cout.flush();
    postalCode = cin.readLine();

    QList<Customer*> dpcList = customerList.findByDPC(postalCode);

    if(dpcList.size() > 0){
        foreach(Customer *c, dpcList)
            if(c != 0)
                cout  << c->toString(true) << endl;
    }
    else
        cout << "Customer not found" << endl;

    cout << endl << "Done...";
    cout.flush();


    return a.exec();
}





