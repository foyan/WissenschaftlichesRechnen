#ifndef ORDER_H
#define ORDER_H

#include "Payment.h"
#include "Recipient.h"
#include "Good.h"

class Order
{
    public:
        Order(Payment*, Recipient*);
        virtual ~Order();

        void addGood(Good*);
    protected:
    private:
        Payment* payment;
        Recipient* recipient;
};

#endif // ORDER_H
