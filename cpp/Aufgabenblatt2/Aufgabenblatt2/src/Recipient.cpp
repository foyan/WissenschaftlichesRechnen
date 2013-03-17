#include "../include/Recipient.h"

Recipient::Recipient()
{
    //ctor
}

Recipient::~Recipient()
{
    //dtor
}

Country Recipient::getCountry() {
    return this->country;
}

void Recipient::setCountry(Country country) {
    this->country = country;
}

void Recipient::setCountryFromString(string country) {
    if (country == "CH") {
        this->country = CH;
        return;
    }
    if (country == "DE") {
        this->country = DE;
        return;
    }
    if (country == "US") {
        this->country = US;
        return;
    }
    throw "This aint no country.";
}

string Recipient::getAddress() {
    return this->address;
}

void Recipient::setAddress(string address) {
    this->address = address;
}
