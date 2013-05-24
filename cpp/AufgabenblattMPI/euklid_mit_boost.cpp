#include "euklid_mit_boost.h"

template<> double euklid_mit_boost<complex<double> >::quadrat_summand(complex<double> x) {
	return x.real() * x.real() + x.imag() * x.imag();
}

template<> complex<double> euklid_mit_boost<complex<double> >::get_component_input(string name, int index) {
	double re, im;

	cout << "Re(" << name << "[" << index << "]):";
	cin >> re;

	cout << "Im(" << name << "[" << index << "]):";
	cin >> im;

	return complex<double>(re, im);
}
