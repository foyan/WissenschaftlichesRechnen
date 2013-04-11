#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <algorithm>
#include <list>

#include "include/Good.h"
#include "include/Recipient.h"
#include "include/Payment.h"
#include "include/Order.h"

/*using namespace std;

void aufgabe1();
void aufgabe2();
void aufgabe3();
void aufgabe4();
void aufgabe5();
void aufgabe6();
void aufgabe7();
void aufgabe8();
void aufgabe9();
void aufgabe10();
void aufgabe11();
void aufgabe12();
void aufgabe13();

int mainz()
{
    aufgabe13();
    return 0;
}

void aufgabe1() {
    cout << "x y z: ";
    double x, y, z;
    cin >> x >> y >> z;
    double r = (x + 10) * y / z;
    cout << " => r = " << r << endl;
}

void aufgabe2() {
    cout << "Vierstellige Zahl:";
    string n;
    cin >> n;

    int q = atoi(n.substr(0, 1).c_str())
        + atoi(n.substr(1, 1).c_str())
        + atoi(n.substr(2, 1).c_str())
        + atoi(n.substr(3, 1).c_str());
    cout << q;
}

void aufgabe3() {
    cout << "Vierstellige Zahl:";
    string n;
    cin >> n;

    int q = 0, i = 4;
    while (i-- > 0) {
        q += atoi(n.substr(i, 1).c_str());
    }
    cout << q;
}

void aufgabe4() {
    cout << "Quodlibet Zahl:";
    string n;
    cin >> n;

    int q = 0, i = n.length();
    while (i-- > 0) {
        q += atoi(n.substr(i, 1).c_str());
    }
    cout << q;
}

int is_prime(int n) {
    if (n % 2 == 0) {
        return n == 2 ? 1 : 0;
    }
    if (n % 3 == 0) {
        return n == 3 ? 1 : 0;
    }
    int m = sqrt(n);

    for (int i = 5; i <= m; i += 6) {
        return ((n % i == 0) && (n % (i+2) == 0)) ? 1 : 0;
    }

    return 1;
}

void aufgabe5() {
    cout << "Zahl:";
    int n;
    cin >> n;

    cout << is_prime(n) << endl;
}

void aufgabe6() {
    int a[5] = {0, 4, -2, 17, 3};

    int min = INT_MAX, max = INT_MIN;

    for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++) {
        min = a[i] < min ? a[i] : min;
        max = a[i] > max ? a[i] : max;
    }

    cout << "min: " << min << ", max: " << max << endl;
}

int power(int base, int exponent) {
    int n = 1;
    for (int i = 0; i < exponent; i++) {
        n *= base;
    }
    return n;
}

void aufgabe7() {
    cout << "b, e:";
    int b, e;
    cin >> b >> e;

    cout << "b^e = " << power(b, e) << endl;
}

void reverse(string* n) {
    reverse(n->begin(), n->end());
}

void aufgabe8() {
    cout << "Zahl:";
    string n;
    cin >> n;
    reverse(&n);
    cout << n;
}

Good* ask_for_good() {
    cout << "Ware:";
    string wname;
    cin >> wname;

    if(wname == "-") {
        return NULL;
    }

    Good* good = new Good();
    good->setName(wname);

    return good;
}

Recipient* ask_for_recipient() {
    cout << "Adresse:";
    string addr;
    cin >> addr;

    cout << "Land:";
    string ctry;
    cin >> ctry;

    Recipient* rec = new Recipient();
    rec->setAddress(addr);
    rec->setCountryFromString(ctry);

    return rec;
}

Payment* ask_for_payment() {
    cout << "Kreditkarten-Nummer:";
    string ccnum;
    cin >> ccnum;

    cout << "Expiry Jahr:";
    int expy;
    cin >> expy;

    cout << "Expiry Monat:";
    int expm;
    cin >> expm;

    Payment* paym = new Payment();
    paym->setCreditCardNumber(ccnum);
    paym->setExpiry(expy, expm);

    return paym;
}

void aufgabe9() {

    Good* good = ask_for_good();
    Recipient* rec = ask_for_recipient();
    Payment* paym = ask_for_payment();

    Order* order = new Order(paym, rec);
    order->add_good(good);

    delete order;
    delete good;
    delete rec;
    delete paym;
}

void aufgabe10() {

    Good* good = ask_for_good();
    Recipient* rec = ask_for_recipient();
    Payment* paym = ask_for_payment();

    Order* order = new Order(paym, rec);

    list<Good*>* goods = new list<Good*>();

    int i = 0;
    while (good != NULL && i++ < 10) {
        order->add_good(good);
        goods->push_back(good);
        cout << "More? Type - when done.";
        good = ask_for_good();
    }

    delete order;

    for (list<Good*>::iterator i = goods->begin(); i != goods->end(); i++) {
        delete (*i);
    }

    delete goods;
    delete rec;
    delete paym;

}

void print_order(Order* order) {
    cout << "Lieferadresse: " << order->get_recipient()->getAddress() << ", " << order->get_recipient()->getCountry() << endl;
    cout << "Kreditkarte: " << order->get_payment()->getCreditCardNumber()
         << ", exp " << order->get_payment()->getExpiryYear() << "/" << order->get_payment()->getExpiryMonth() << endl;

    for (list<Good*>::const_iterator i = order->goods_begin(); i != order->goods_end(); i++) {
        cout << "  - Ware: " << (*i)->getName() << endl;
    }

}

void aufgabe11() {

    Good* good = ask_for_good();
    Recipient* rec = ask_for_recipient();
    Payment* paym = ask_for_payment();

    Order* order = new Order(paym, rec);

    list<Good*>* goods = new list<Good*>();

    int i = 0;
    while (good != NULL && i++ < 10) {
        order->add_good(good);
        goods->push_back(good);
        cout << "More? Type - when done.";
        good = ask_for_good();
    }

    print_order(order);

    delete order;

    for (list<Good*>::iterator i = goods->begin(); i != goods->end(); i++) {
        delete (*i);
    }

    delete goods;
    delete rec;
    delete paym;

}

void aufgabe12() {
    cout << "Anzahl:";
    int nbr;
    cin >> nbr;
    short* bobby = new short[nbr];

    for (int i = 0; i < nbr; i++) {
        bobby[i] = i % 2;
    }

    for (int i = 0; i < nbr; i++) {
        cout << bobby[i];
    }

}

#define KUHNIX

struct dep_number_t {
#ifdef KUHNIX
long
#endif
#ifdef LUXUS
char
#endif
#ifdef HASTA
short
#endif
#ifdef BANANA
#error "Banana Mac wird nicht unterstuetzt."
#endif
nbr;

};

dep_number_t add(dep_number_t a, dep_number_t b) {
    dep_number_t c;
    c.nbr = a.nbr + b.nbr;
    cout << c.nbr;
    return c;
}

void aufgabe13() {
    cout << "Zwei Zahlen:";
    dep_number_t a, b;
    cin >> a.nbr >> b.nbr;
    add(a, b);
}
*/
