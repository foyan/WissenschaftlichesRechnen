#include "../include/Payment.h"

Payment::Payment()
{
    //ctor
}

Payment::~Payment()
{
    //dtor
}

string Payment::getCreditCardNumber() {
    return this->creditCardNumber;
}

void Payment::setCreditCardNumber(string ccnum) {
    this->creditCardNumber = ccnum;
}

int Payment::getExpiryMonth() {
    return this->expiryMonth;
}

int Payment::getExpiryYear() {
    return this->expiryYear;
}

void Payment::setExpiry(int year, int month) {
    this->expiryYear = year;
    this->expiryMonth = month;
}
