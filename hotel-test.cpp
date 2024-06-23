#include "hotel.hpp"
#include "room.hpp"

#include <cassert>

bool emptyHotel() {
    Hotel("bill");

    return true;
}

bool getterCheck() {
    Hotel Broadview("broadview");

    assert(Broadview.getName() == "broadview");

    return true;
}

int main() {
    emptyHotel();
    //getterCheck();

    return 1;
}