#ifndef PAYMENT_H
#define PAYMENT_H

#include <string>

using namespace std;

class Payment
{
    public:
        Payment();
        virtual ~Payment();

        string getCreditCardNumber();
        void setCreditCardNumber(string);
        int getExpiryMonth();
        int getExpiryYear();
        void setExpiry(int year, int month);
    protected:
    private:
        string creditCardNumber;
        int expiryMonth;
        int expiryYear;
};

#endif // PAYMENT_H
