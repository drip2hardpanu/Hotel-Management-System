#include "room.hpp"
#include <cassert>

/**
* Test case file for room
* To make: "make room-test"
*/

bool emptyRoom() {
    Room B;
    Room("bill", 204, CLEAN);

    return true;
}

bool nameCheck() {
    Room A("bill", 204, CLEAN);
    Room B;

    assert(A.getUser() == "bill");

    return true;
}

bool equalityCheck() {
    Room A("bill", 204, CLEAN);
    Room B("bill", 204, CLEAN);
    Room C;

    assert(A == B);

    return true;    
}

bool numberCheck() {
    Room("bill", 204, CLEAN);
}

int main() {
    emptyRoom();

    nameCheck();
    equalityCheck();

    return 1;
}