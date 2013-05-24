#ifndef SKALAR_PRODUKT_MIT_BOOST_H_
#define SKALAR_PRODUKT_MIT_BOOST_H_

#include <boost/mpi.hpp>
#include <iostream>
#include <cstdlib>
#include "vector_pair.h"

namespace mpi = boost::mpi;

using namespace std;


template <typename T>
class skalar_produkt_mit_boost {

private:

	mpi::communicator _world;
	int _size;
	int _rank;

	T skalar(vector<T> a, vector<T> b) {
		T c = 0;
		for (unsigned int i = _rank-1; i < a.size(); i += (_size -1)) {
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


	void send_out(vector<T> a, vector<T> b) {
		for (int i = 1; i < _size; i++) {
			vector_pair<T> d;
			d._a = a;
			d._b = b;
			_world.send(i, 123, d);
		}
	}

	T wait() {
		T result = 0;

		for (int i = 1; i < _size; i++) {
			T partial_result;
			_world.recv(i, 123, partial_result);
			result += partial_result;
		}

		return result;
	}

	vector<T> get_input(string name, int count) {

		vector<T> a;

		for (int i = 0; i < count; i++) {
			cout << name << "[" << (i+1) << "]:";
			T tmp;
			cin >> tmp;
			a.push_back(tmp);
			a[i] = tmp;
		}

		return a;
	}

	void perform_slave_action() {

		vector_pair<T> d;

		_world.recv(0, 123, d);

		cout << "Node #" << _rank << " is calculating..." << endl;

		T result = skalar(d._a, d._b);

		cout << "Node #" << _rank << ": partial sum = " << result;
		cout.flush();

		_world.send(0, 123, result);

	}

public:

	int let_cluster_calculate_skalar_prod(int argc, char* argv[]) {

		mpi::environment env(argc, argv);
		mpi::communicator world;

		_world = world;
		_size = world.size();
		_rank = world.rank();

		if (world.rank() == 0) {

			int count = get_count();
			vector<T> a = get_input("a", count);
			vector<T> b = get_input("b", count);

			send_out(a, b);

			T result = wait();

			cout << "Yeehaah! a b = " << result;

		} else {

			perform_slave_action();

		}

		return 0;
	}

};

#endif /* SKALAR_PRODUKT_MIT_BOOST_H_ */

