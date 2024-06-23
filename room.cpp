#include "room.hpp"

using namespace std;

Room::Room(string user, size_t number, status stat, size_t rate) :
    user_{user}, number_{number}, status_{stat}, rate_{rate}
    {};

string Room::getUser() const {
    return user_;
}

/**
* @brief operators
*/
bool Room::operator==(const Room& other) {
    return number_ == other.number_;
};