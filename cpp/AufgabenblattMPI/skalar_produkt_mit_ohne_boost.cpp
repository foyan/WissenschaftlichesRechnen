#include <iostream>

#include "mpi.h"

#include "skalar_produkt_mit_ohne_boost.h"

using namespace std;

int skalar_produkt_mit_ohne_boost::skalar(int a[], int b[], int count, int rank, int size) {
	int c = 0;
	for (int i = rank-1; i < count; i += (size -1)) {
		c += (a[i] * b[i]);
	}
	return c;
}

int skalar_produkt_mit_ohne_boost::let_cluster_calculate_scalar_prod(int argc, char* argv[]) {

	MPI_Init(&argc, &argv);

	int rank, size;

	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	//cout << "Hi. I'm node #" << rank << "/" << size << endl;

	if (rank == 0) {

		int count;

		cout << "Count:";
		cin >> count;

		int a[count];
		int b[count];

		for (int i = 0; i < count; i++) {
			cout << "a[" << (i+1) << "]:";
			int tmp;
			cin >> tmp;
			a[i] = tmp;
		}
		for (int i = 0; i < count; i++) {
			cout << "b[" << (i+1) << "]:";
			int tmp;
			cin >> tmp;
			b[i] = tmp;
		}

		cout << "Thanks. Let's calculate." << endl;

		for (int i = 1; i < size; i++) {
			int buffer[1];
			buffer[0] = count;
			MPI_Send(buffer, 1, MPI_INT, i, 123, MPI_COMM_WORLD);
			MPI_Send(a, count, MPI_INT, i, 123, MPI_COMM_WORLD);
			MPI_Send(b, count, MPI_INT, i, 123, MPI_COMM_WORLD);
		}

		int result = 0;

		for (int i = 1; i < size; i++) {
			int buffer[1];
			MPI_Status status;
			MPI_Recv(buffer, 1, MPI_INT, i, 123, MPI_COMM_WORLD, &status);
			result += buffer[0];
		}

		cout << "Yeehah! a b = " << result << endl;

	} else {

		int buffer[1];
		MPI_Status status;
		MPI_Recv(buffer, 1, MPI_INT, 0, 123, MPI_COMM_WORLD, &status);

		int count = buffer[0];

		cout << "Node #" << rank << " received count = " << count << endl;

		int a[count];
		int b[count];

		MPI_Recv(a, count, MPI_INT, 0, 123, MPI_COMM_WORLD, &status);
		MPI_Recv(b, count, MPI_INT, 0, 123, MPI_COMM_WORLD, &status);

		cout << "Node #" << rank << " is calculating..." << endl;

		int res = skalar(a, b, count, rank, size);

		cout << "Node #" << rank << ": partial sum = " << res << endl;

		buffer[0] = res;

		MPI_Send(buffer, 1, MPI_INT, 0, 123, MPI_COMM_WORLD);

	}

	MPI_Finalize();

	return 0;
}

