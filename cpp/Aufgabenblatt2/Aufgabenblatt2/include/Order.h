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

        void add_good(Good*);

        Payment* get_payment();
        Recipient* get_recipient();

        list<Good*>::const_iterator goods_begin();
        list<Good*>::const_iterator goods_end();


    protected:
    private:
        Payment* payment;
        Recipient* recipient;
        list<Good*>* goods;
};

#endif // ORDER_H
