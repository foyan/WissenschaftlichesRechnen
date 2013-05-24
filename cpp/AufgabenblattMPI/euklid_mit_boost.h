#ifndef EUKLID_MIT_BOOST_H_
#define EUKLID_MIT_BOOST_H_

#include <boost/mpi.hpp>
#include <iostream>
#include <cstdlib>
#include <complex>
#include <boost/serialization/vector.hpp>
#include <boost/serialization/complex.hpp>

namespace mpi = boost::mpi;

using namespace std;

template <typename T>
class euklid_mit_boost {

private:

	mpi::communicator _world;
	int _size;
	int _rank;

	double quadrat_summand(T x) {
		return x * x;
	}

	double quadrat_summe(vector<T> a) {
		double c = 0;
		for (unsigned int i = _rank-1; i < a.size(); i += (_size -1)) {
			c += quadrat_summand(a[i]);
		}
		return c;
	}

	int get_count() {
		int count;
		cout << "Count:";
		cin >> count;
		return count;
	}


	void send_out(vector<T> a) {
		for (int i = 1; i < _size; i++) {
			_world.send(i, 123, a);
		}
	}

	double wait() {
		double result = 0;

		for (int i = 1; i < _size; i++) {
			double partial_result;
			_world.recv(i, 123, partial_result);
			result += partial_result;
		}

		return sqrt(result);
	}

	T get_component_input(string name, int index) {
		T c;
		cout << name << "[" << index << "]:";
		cin >> c;
		return c;
	}

	vector<T> get_input(string name, int count) {

		vector<T> a;

		for (int i = 0; i < count; i++) {
			a.push_back(get_component_input(name, i+1));
		}

		return a;
	}

	void perform_slave_action() {

		vector<T> d;

		_world.recv(0, 123, d);

		cout << "Node #" << _rank << " is calculating..." << endl;

		double result = quadrat_summe(d);

		cout << "Node #" << _rank << ": partial square sum = " << result;
		cout.flush();

		_world.send(0, 123, result);

	}

public:

	int let_cluster_calculate_norm(int argc, char* argv[]) {

		mpi::environment env(argc, argv);
		mpi::communicator world;

		_world = world;
		_size = world.size();
		_rank = world.rank();

		if (world.rank() == 0) {

			int count = get_count();
			vector<T> a = get_input("v", count);

			send_out(a);

			double result = wait();

			cout << "Yeehaah! ||v||_2 = " << result;

		} else {

			perform_slave_action();

		}

		return 0;
	}

};

template<> double euklid_mit_boost<complex<double> >::quadrat_summand(complex<double> x);

template<> complex<double> euklid_mit_boost<complex<double> >::get_component_input(string name, int index);

#endif /* EUKLID_MIT_BOOST_H_ */
