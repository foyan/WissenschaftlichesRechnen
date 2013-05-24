/*
 * skalar_produkt_mit_ohne_boost_mit_template.h
 *
 *  Created on: May 24, 2013
 *      Author: florian
 */

#ifndef SKALAR_PRODUKT_MIT_OHNE_BOOST_MIT_TEMPLATE_H_
#define SKALAR_PRODUKT_MIT_OHNE_BOOST_MIT_TEMPLATE_H_

using namespace std;

#include "mpi.h"

template <typename T>
class skalar_produkt_mit_ohne_boost_mit_template {

private:

	T skalar(T a[], T b[], int count, int rank, int size) {
		T c = 0;
		for (int i = rank-1; i < count; i += (size -1)) {
			c += (a[i] * b[i]);
		}
		return c;
	}

	int get_count() {
		int count;
		cout << "Count:";
		cin >> count;
		return count;
	}

	MPI_Datatype get_type() {
		return MPI_INT;
	}

	void send_out(int count, T a[], T b[], int size) {
		for (int i = 1; i < size; i++) {
			int buffer[1];
			buffer[0] = count;
			MPI_Send(buffer, 1, MPI_INT, i, 123, MPI_COMM_WORLD);
			MPI_Send(a, count, get_type(), i, 123, MPI_COMM_WORLD);
			MPI_Send(b, count, get_type(), i, 123, MPI_COMM_WORLD);
		}
	}

	T wait(int size) {
		T result = 0;

		for (int i = 1; i < size; i++) {
			T buffer[1];
			MPI_Status status;
			MPI_Recv(buffer, 1, get_type(), i, 123, MPI_COMM_WORLD, &status);
			result += buffer[0];
		}
		return result;
	}

	T* get_input(string name, int count) {

		T* a = new T[count];

		for (int i = 0; i < count; i++) {
			cout << name << "[" << (i+1) << "]:";
			T tmp;
			cin >> tmp;
			a[i] = tmp;
		}

		return a;
	}

	void perform_slave_action(int rank, int size) {
		int buffer[1];
		MPI_Status status;
		MPI_Recv(buffer, 1, MPI_INT, 0, 123, MPI_COMM_WORLD, &status);

		int count = buffer[0];

		cout << "Node #" << rank << " received count = " << count << endl;

		T a[count];
		T b[count];

		MPI_Recv(a, count, get_type(), 0, 123, MPI_COMM_WORLD, &status);
		MPI_Recv(b, count, get_type(), 0, 123, MPI_COMM_WORLD, &status);

		cout << "Node #" << rank << " is calculating..." << endl;

		T calc_result_buffer[1];
		calc_result_buffer[0] = skalar(a, b, count, rank, size);

		cout << "Node #" << rank << ": partial sum = " << calc_result_buffer[0];

		MPI_Send(calc_result_buffer, 1, get_type(), 0, 123, MPI_COMM_WORLD);

	}

public:

	int let_cluster_calculate_skalar_prod(int argc, char* argv[]) {
		MPI_Init(&argc, &argv);

		int rank, size;

		MPI_Comm_rank(MPI_COMM_WORLD, &rank);
		MPI_Comm_size(MPI_COMM_WORLD, &size);

		if (rank == 0) {

			int count = get_count();
			T* a = get_input("a", count);
			T* b = get_input("b", count);

			send_out(count, a, b, size);

			T result = wait(size);

			cout << "Yeehaah! a b = " << result;

		} else {

			perform_slave_action(rank, size);

		}

		MPI_Finalize();

		return 0;
	}

};



#endif /* SKALAR_PRODUKT_MIT_OHNE_BOOST_MIT_TEMPLATE_H_ */
