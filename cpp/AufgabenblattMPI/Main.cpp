#include <complex>
#include "euklid_mit_boost.h"
#include "skalar_produkt_mit_ohne_boost.h"
#include "skalar_produkt_mit_ohne_boost_mit_template.h"
#include "skalar_produkt_mit_boost.h"

int main(int argc, char* argv[]) {

	// Aufgabe 1a
	//skalar_produkt_mit_ohne_boost sk;
	//sk.let_cluster_calculate_scalar_prod(argc, argv);

	// Aufgabe 1b
	//skalar_produkt_mit_ohne_boost_mit_template<int> skt_int;
	//skt_int.let_cluster_calculate_skalar_prod(argc, argv);

	// Aufgabe 1c
	//skalar_produkt_mit_boost<int> skb;
	//skb.let_cluster_calculate_skalar_prod(argc, argv);

	// Aufgabe 2a
	//euklid_mit_boost<int> norm_int;
	//return norm_int.let_cluster_calculate_norm(argc, argv);

	// Aufgabe 2b
	// Komplexe Zahlen.

	// Aufgabe 2c
	euklid_mit_boost<complex<double> > norm_complex;
	return norm_complex.let_cluster_calculate_norm(argc, argv);

}
