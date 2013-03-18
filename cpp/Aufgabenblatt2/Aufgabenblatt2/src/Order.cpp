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

void Order::add_good(Good* good) {
    this->goods->push_back(good);
};

Payment* Order::get_payment() {
    return this->payment;
}

Recipient* Order::get_recipient() {
    return this->recipient;
}

list<Good*>::const_iterator Order::goods_begin() {
    return this->goods->begin();
}

list<Good*>::const_iterator Order::goods_end() {
    return this->goods->end();
}
