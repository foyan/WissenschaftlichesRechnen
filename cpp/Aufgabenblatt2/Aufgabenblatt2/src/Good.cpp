#include "../include/Good.h"

Good::Good() {

}

Good::~Good() {

}

string Good::getName() {
    return this->name;
}

void Good::setName(string name) {
    this->name = name;
}
