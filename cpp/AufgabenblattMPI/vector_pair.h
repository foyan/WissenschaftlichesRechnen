#ifndef VECTOR_PAIR_H_
#define VECTOR_PAIR_H_

#include <cstdlib>
#include <vector>
#include <boost/serialization/vector.hpp>

using namespace std;

template<class T>
class vector_pair {
private:
	friend class boost::serialization::access;

	template<class Archive>
	void serialize(Archive &ar, const unsigned int version) {
		ar &_a;
		ar &_b;
	}

public:
	vector<T> _a;
	vector<T> _b;

};


#endif /* VECTOR_PAIR_H_ */
