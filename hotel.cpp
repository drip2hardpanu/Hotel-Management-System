#include "hotel.hpp"
#include "room.hpp"

#include <cassert>
#include <algorithm>
#include <iostream>

using namespace std;

Hotel::Hotel(string name):
    name_{name}, capacity_{0}, openRooms_{0}, data_{new std::forward_list<Room>[DEFAULT_ROOMS]} {
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
    key = key % buckets_;

    //pull list
    forward_list<Room> values = data_[key];

    for (auto i = values.begin(); i != values.end(); i++) {
        if (*i == room) {
            return true;
        }
    }

    return false;
}

bool Hotel::numberExists(size_t number) const {
    Room Q(number);
}

void Hotel::insert(const Room& room) {
    //rehash check 
    ++capacity_;

    if (loadFactor() > MAX_LOAD_FACTOR) {
        rehash();
    }

    size_t key = hash(room);
    key = key % buckets_;

    data_[key].push_front(room);
}

double Hotel::loadFactor() const {
    double forReturn = (double)capacity_/buckets_;
    return forReturn;
}

void Hotel::rehash() {
    size_t prevBuckets = buckets_;
    buckets_ = buckets_ * 2;

    //creating new hash table
    std::forward_list<Room>* newData_ = new std::forward_list<Room>[buckets_];

    //moving values to new table
    for (size_t q = 0; q < prevBuckets; ++q) {
        std::forward_list<Room> copy = data_[q];
        for (auto i = copy.begin(); i != copy.end(); ++i) {
            size_t key = hash(*i);
            key = key % buckets_;
            newData_[key].push_front(*i);
        }
    }

    //deleting old data
    delete[] data_;
    data_ = newData_;

    //for testing
    ++rehashCount;
}


void numberAddRoom(size_t roomNum) {

}


std::forward_list<Room>* Hotel::getData() {
    return data_;
}

