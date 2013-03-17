#ifndef RECIPIENT_H
#define RECIPIENT_H

#include <string>

using namespace std;

enum Country {
    CH,
    DE,
    US
};

class Recipient
{
    public:
        Recipient();
        virtual ~Recipient();

        string getAddress();
        void setAddress(string);
        Country getCountry();
        void setCountry(Country);
        void setCountryFromString(string);
    protected:
    private:
        string address;
        Country country;
};

#endif // RECIPIENT_H
