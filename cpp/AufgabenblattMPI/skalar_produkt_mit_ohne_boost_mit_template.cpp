#include <iostream>

#include "mpi.h"
#include "skalar_produkt_mit_ohne_boost_mit_template.h"


template <>
MPI_Datatype skalar_produkt_mit_ohne_boost_mit_template<short>::get_type() {
	return MPI_SHORT;
}
template <>
MPI_Datatype skalar_produkt_mit_ohne_boost_mit_template<int>::get_type() {
	return MPI_INT;
}
template <>
MPI_Datatype skalar_produkt_mit_ohne_boost_mit_template<long>::get_type() {
	return MPI_LONG;
}
template <>
MPI_Datatype skalar_produkt_mit_ohne_boost_mit_template<float>::get_type() {
	return MPI_FLOAT;
}
template <>
MPI_Datatype skalar_produkt_mit_ohne_boost_mit_template<double>::get_type() {
	return MPI_DOUBLE;
}


