#include "../include/Order.h"
#include "../include/Good.h"

Order::Order(Payment* payment, Recipient* recipient) {
    this->payment = payment;
    this->recipient = recipient;
}

Order::~Order()
{
    //dtor
}

void Order::addGood(Good* good) {

};
