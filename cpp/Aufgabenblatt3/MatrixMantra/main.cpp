#include <iostream>

#include "Matrix.h"

using namespace std;

int main()
{
    Matrix<long> a = Matrix<long>(3,3);

    a.set(0, 0, 1);
    a.set(1, 0, 2);
    a.set(2, 0, 3);
    a.set(0, 1, 4);
    a.set(1, 1, 5);
    a.set(2, 1, 6);
    a.set(0, 2, 7);
    a.set(1, 2, 8);
    a.set(2, 2, 9);

    Matrix<long> b = Matrix<long>(3,3);

    b.set(0, 0, 6);
    b.set(1, 0, -1);
    b.set(2, 0, 12);
    b.set(0, 1, 3);
    b.set(1, 1, 2);
    b.set(2, 1, -124);
    b.set(0, 2, 0);
    b.set(1, 2, -3);
    b.set(2, 2, -1);

    cout << "a = " << a.to_string() << endl;
    cout << "b = " << b.to_string() << endl << endl;

    cout << "a+b = b+a = " << a.plus(b).to_string() << " = " << b.plus(a).to_string() << endl;
    cout << "a-b = " << a.minus(b).to_string() << endl;
    cout << "b-a = " << b.minus(a).to_string() << endl;
    cout << "ab = " << a.times(b).to_string() << endl;
    cout << "ba = " << b.times(a).to_string() << endl << endl;

    Matrix<long> x = Matrix<long>(5,5);

    x.set(0, 0, 1);
    x.set(1, 0, 2);
    x.set(2, 0, 3);
    x.set(3, 0, 5);
    x.set(4, 0, -23);
    x.set(0, 1, 4);
    x.set(1, 1, 5);
    x.set(2, 1, 6);
    x.set(3, 1, 5);
    x.set(4, 1, -23);
    x.set(0, 2, 7);
    x.set(1, 2, 8);
    x.set(2, 2, 9);
    x.set(3, 2, 5);
    x.set(4, 2, -23);
    x.set(0, 3, 7);
    x.set(1, 3, 8);
    x.set(2, 3, 9);
    x.set(3, 3, 5);
    x.set(4, 3, -23);
    x.set(0, 4, 7);
    x.set(1, 4, 8);
    x.set(2, 4, 9);
    x.set(3, 4, 5);
    x.set(4, 4, -23);

    Matrix<long> y = Matrix<long>(5,5);

    y.set(0, 0, 6);
    y.set(1, 0, -1);
    y.set(2, 0, 12);
    y.set(3, 0, 5);
    y.set(4, 0, -23);
    y.set(0, 1, 3);
    y.set(1, 1, 2);
    y.set(2, 1, -124);
    y.set(3, 1, 5);
    y.set(4, 1, -23);
    y.set(0, 2, 0);
    y.set(1, 2, -3);
    y.set(2, 2, -1);
    y.set(3, 2, 5);
    y.set(4, 2, -23);
    y.set(0, 3, 7);
    y.set(1, 3, 8);
    y.set(2, 3, 9);
    y.set(3, 3, 5);
    y.set(4, 3, -23);
    y.set(0, 4, 7);
    y.set(1, 4, 8);
    y.set(2, 4, 9);
    y.set(3, 4, 5);
    y.set(4, 4, -23);

    cout << "x = " << x.to_string() << endl;
    cout << "y = " << y.to_string() << endl << endl;

    cout << "x+y = x+y = " << x.plus(y).to_string() << " = " << y.plus(x).to_string() << endl;
    cout << "x-y = " << x.minus(y).to_string() << endl;
    cout << "y-x = " << y.minus(x).to_string() << endl;
    cout << "xy = " << x.times(y).to_string() << endl;
    cout << "yx = " << y.times(x).to_string() << endl << endl;

    cout << "norm(a) = " << a.norm() << endl;
    cout << "norm(b) = " << b.norm() << endl;
    cout << "norm(x) = " << x.norm() << endl;
    cout << "norm(y) = " << y.norm() << endl;

    Matrix<long> z(2,2);
    z.set(0,0,1);
    z.set(0,1,1);
    z.set(1,0,1);
    z.set(1,1,1);

    cout << z.norm();

}
