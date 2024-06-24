#include "room.hpp"

using namespace std;

Room::Room(string user, size_t number, status stat, size_t rate) :
    user_{user}, number_{number}, status_{stat}, rate_{rate}
    {};

Room::Room(size_t number) :
    user_{""}, number_{number}, status_{CLEAN}, rate_{55}
    {};


string Room::getUser() const {
    return user_;
}

void Room::changeUser(string user) {
    user_ = user;
}

/**
* @brief operators
*/
bool Room::operator==(const Room& other) {
    return number_ == other.number_;
};

std::ostream& Room::printToStream(std::ostream& s) const {
    cout << "user: " << getUser() << endl;
    cout << "number: " << number_ << endl;
    cout << "status: " << to_string(status_) << endl;
    cout << "rate: " << rate_ << endl;

    return s;
}

std::ostream& operator<<(std::ostream& out, const Room& room) {
    return room.printToStream(out);
}