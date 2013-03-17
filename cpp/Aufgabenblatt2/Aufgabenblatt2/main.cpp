#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <algorithm>

#include "include/Good.h"
#include "include/Recipient.h"
#include "include/Payment.h"
#include "include/Order.h"

using namespace std;

void aufgabe1();
void aufgabe2();
void aufgabe3();
void aufgabe4();
void aufgabe5();
void aufgabe6();
void aufgabe7();
void aufgabe8();
void aufgabe9();

int main()
{
    aufgabe9();
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

void aufgabe9() {
    cout << "Ware:";
    string wname;
    cin >> wname;

    Good* good = new Good();
    good->setName(wname);

    cout << "Adresse:";
    string addr;
    cin >> addr;

    cout << "Land:";
    string ctry;
    cin >> ctry;

    Recipient* rec = new Recipient();
    rec->setAddress(addr);
    rec->setCountryFromString(ctry);

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

    Order* order = new Order(paym, rec);
    order->addGood(good);

    delete order;
    delete good;
    delete rec;
    delete paym;
}

