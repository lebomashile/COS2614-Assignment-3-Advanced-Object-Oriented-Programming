#include "payment.h"

Payment::Payment(QString typ):type(typ) {

}

QString Payment::getType() const
{
    return type;
}


