#include <iostream>

using namespace std;

float FloatMachineEps() {
    float fmachine_e = 1.0, ftest = 1.0 + fmachine_e;

    while(1.0 != ftest) {
        fmachine_e /= 2.0;
        ftest = 1.0 + fmachine_e;
    }

    return fmachine_e;
}

double DoubleMachineEps() {
    double dmachine_e, dtest;
    dmachine_e = 1.0;
    dtest = 1.0 + dmachine_e;

    while(1.0 != dtest) {
        dmachine_e = dmachine_e/2.0;
        dtest = 1.0 + dmachine_e;
    }

    return dmachine_e;
}

long double LongDoubleMachineEps() {
    long double dmachine_e, dtest;
    dmachine_e = 1.0;
    dtest = 1.0 + dmachine_e;

    while(1.0 != dtest) {
        dmachine_e = dmachine_e/2.0;
        dtest = 1.0 + dmachine_e;
    }

    return dmachine_e;
}

int main(int argc, char* argv[]) {
    float fep = FloatMachineEps();
    double dep = DoubleMachineEps();
    long double ldep = LongDoubleMachineEps();
    cout << "Machine epsilon for single precision is: " << fep << endl;
    cout << "Machine epsilon for double precision is: " << dep << endl;
    cout << "Machine epsilon for extra long double chili cheese precision is: " << ldep << endl;
}
