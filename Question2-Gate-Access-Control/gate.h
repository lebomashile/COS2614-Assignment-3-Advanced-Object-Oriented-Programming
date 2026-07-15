#ifndef GATE_H
#define GATE_H

#include <QString>

class Gate
{
public:
    Gate(QString d, int p);
    QString getDescription()const;
    bool checkPassword(int p) const;
private:
    QString description;
    int password;
};

#endif // GATE_H
