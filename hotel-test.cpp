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

bool insertCheck() {
    Hotel Broadview("broadview");
    Room W;

    Broadview.insert(W);

    assert(Broadview.capacity_ == 1);

    return true;
}

bool existsCheck() {
    Hotel Broadview("broadview");
    Room W;

    Broadview.insert(W);

    assert(Broadview.exists(W));

    return true;
}

bool loadfactorCheck01() {
    Hotel Broadview("broadview");
    Room W;
    Room Q;

    Broadview.insert(W);

    assert(Broadview.loadFactor() == 0.01);

    Broadview.insert(Q);
    assert(Broadview.loadFactor() == 0.02);

    return true;
}

bool loadfactorCheck02() {
    Hotel Broadview("broadview");

    for (size_t i = 0; i < 20; i++) {
        Room W(i);
        Broadview.insert(W);
    }

    assert(Broadview.loadFactor() == 0.2);

    return true;
}

bool insertRehashCheck() {
    Hotel Broadview("broadview");

    for (size_t i = 0; i < 80; ++i) {
        Room W(i);
        Broadview.insert(W);
    }

    assert(Broadview.rehashCount == 0);
    
    Room Q;
    Broadview.insert(Q);

    assert(Broadview.rehashCount == 1);

    return true;
}


int main() {
    emptyHotel();
    getterCheck();
    insertCheck();
    existsCheck();

    loadfactorCheck01();
    loadfactorCheck02();

    insertRehashCheck();

    return 1;
}