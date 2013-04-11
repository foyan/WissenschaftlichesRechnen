#include <string>
#include <sstream>
#include <iostream>

using namespace std;

template <typename T>

string convert_to_string(T obj) {
    ostringstream ss;
    ss << obj;
    return ss.str();
}

struct elefant {

    elefant(string name) : Name(name) {
    }

    string Name;

};

template <>
string convert_to_string<elefant*>(elefant* obj) {
    ostringstream ss;
    ss << obj->Name;
    return ss.str();
}

int factorial(int n) {
    int f = 1;
    while (n > 1) {
        f *= n--;
    }
    return f;
}

template <int N>
class factoriall {

    public:
        enum { value = N * factoriall<N-1>::value };

};

template <>
class factoriall<1> {

    public:
        enum { value = 1};

};

int mainzz() {

    cout << factorial(4) << endl << endl;

    cout << factoriall<12>::value << endl;

    int i = 42;
    cout << convert_to_string(i) << endl;
    cout << convert_to_string<int>(i) << endl;

    elefant* ele = new elefant("Florian");
   //elefant ele = elefant("Florian");

    cout << convert_to_string(ele) << endl;

    delete ele;

   return 0;

}

// beispiel 1

#include <cstdio>

int main1()

{

std::string s = "Hello";

s += ", world!";

std::printf("%s\n", s.c_str());

std::string::size_type idx = s.find("world");

if (idx != std::string::npos)

{

s.replace(idx, 5, "moon");

std::printf("%s\n", s.c_str());

}
} //end of file



int main2()

{

std::wstring s = L"Hello";

s += L", world!";

std::printf("%ls\n", s.c_str());

std::string::size_type idx = s.find(L"world");

if (idx != std::string::npos)

{

s.replace(idx, 5, L"moon");

std::printf("%ls\n", s.c_str());

}
}// end of file


int main3()

{

std::string s;

int i;

std::cin >> s >> i;

std::cout << i << s;

}// end of file

#include <cstring>

int main4()

{

char buffer[32];

std::cin.getline(buffer, sizeof(buffer));

std::cout.write(buffer, std::strlen(buffer));
}// end of file

int main5()

{

std::string input = "abc 10";

std::istringstream is(input);

std::ostringstream os;

std::string s;

int i;

is >> s >> i;

os << i << s;

std::cout << os.str() << std::endl;
}// end of file

#include <vector>

#include <iostream>

int main6()

{

std::vector<char> v;

v.push_back('a');

v.push_back('b');

v.push_back('c');

std::cout << v[0] << std::endl;

std::cout << v.at(2) << std::endl;

std::cout.write(&v[0], v.size()) << std::endl;

}// end of file

#include <list>

#include <iostream>

int main7()

{

std::list<char> l;

l.push_back('a');

l.push_back('b');

l.push_back('c');

std::cout << l.front() << std::endl;

std::cout << l.back() << std::endl;

std::cout << l.size() << std::endl;

}// end of file

#include <string>

#include <map>

#include <utility>

#include <iostream>

int main()

{

std::map<std::string, int> m;

m.insert(std::make_pair("Anton", 35));

m.insert(std::make_pair("Boris", 31));

m.insert(std::make_pair("Caesar", 40));

std::cout << m["Boris"] << std::endl;

}// end of file
