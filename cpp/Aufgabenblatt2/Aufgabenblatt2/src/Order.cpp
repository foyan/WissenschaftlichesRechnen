#include "../include/Order.h"
#include "../include/Good.h"

Order::Order(Payment* payment, Recipient* recipient) {
    this->payment = payment;
    this->recipient = recipient;
    this->goods = new list<Good*>();
}

Order::~Order()
{
    delete this->goods;
}

void Order::addGood(Good* good) {
    this->goods->push_back(good);
};
