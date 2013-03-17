#ifndef GOOD_H
#define GOOD_H

#include <string>

using namespace std;

class Good
{
    public:
        Good();
        virtual ~Good();
        string getName();
        void setName(string);

    private:
        string name;
};

#endif // GOOD_H
