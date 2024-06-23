#include "hotel.hpp"
#include "room.hpp"

#include <cassert>
#include <algorithm>
#include <iostream>

using namespace std;

Hotel::Hotel(string name):
    name_{name}, capacity_{0}, openRooms_{0}, data_{new std::forward_list<Room>[buckets_]} {
    }

Hotel::~Hotel() {
    delete[] data_;
}

//getters
string Hotel::getName() const {
    return name_;
}

size_t Hotel::numOpen() const {
    return openRooms_;
}

size_t Hotel::hash(const Room& room) const {
    const string& str = to_string(room.number_);

    size_t key = 5381;
    for (auto c : str) {
        key = (key << 5) + key + c; 
    }
    return key;
}


bool Hotel::exists(const Room& room) const {
    if (capacity_ == 0) {
        return false;
    }

    //get key
    size_t key = hash(room);
    key = key % capacity_;

    //pull list
    forward_list<Room> values = data_[key];

    for (auto i = values.begin(); i != values.end(); i++) {
        if (*i == room) {
            return true;
        }
    }

    return false;
}

void Hotel::insert(const Room& room) {
    //get key
    size_t key = hash(room);
    key = key % buckets_;

    data_[key].push_front(room);

    ++capacity_;
}




//

