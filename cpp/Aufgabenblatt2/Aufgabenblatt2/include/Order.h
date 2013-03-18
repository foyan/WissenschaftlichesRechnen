#ifndef ORDER_H
#define ORDER_H

#include <list>

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
        list<Good*>* goods;
};

#endif // ORDER_H
