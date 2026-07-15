#include "gate.h"

Gate::Gate(QString d, int p)
    :description(d),password(p){

}

QString Gate::getDescription() const
{
    return description;
}

bool Gate::checkPassword(int p) const
{
    if(p == password)
        return true;
    else
            return false;
}
