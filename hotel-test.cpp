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
    
    Room Z(101);

    assert(Broadview.rehashCount == 0);
    
    Room Q;
    Broadview.insert(Q);

    assert(Broadview.rehashCount == 1);

    return true;
}

bool getStatusCheck() {
    Hotel Broadview("broadview");

    Room Q(101);
    Broadview.insert(Q);

    forward_list<Room>

    cout << Broadview.getData()[Broadview.hash(Q)].begin() << endl;

    assert(Broadview.getStatus(101) == CLEAN);

    return true;
}

bool findOpenCheck() {
    Hotel Broadview("broadview");
  //  cout << Broadview.capacity_ << endl;

    Room Q(101);
    Broadview.insert(Q);

//    cout << Broadview.findOpen() << endl;

    cout << Broadview.findOpen().number_ << endl;
    //cout << Broadview.checkFull() << endl;
    assert(Broadview.findOpen().number_ == 101);

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

    getStatusCheck();
    findOpenCheck();

    return 1;
}