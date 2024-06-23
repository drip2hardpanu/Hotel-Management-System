#ifndef _ROOM_
#define _ROOM_

#include <iostream>

using namespace std;

// possible room statuses
enum status {CLEAN, OCCUPIED, DIRTY};

/**
* Room
* 
* A Room Object that contains name of occupant, status of the room, and the room number 
*/
class Room {
    private:
        string user_;

    public:
        size_t number_;
        status status_;
        size_t rate_;
        
        /**
        * \brief constructs a room
        */
        Room(string user = "", size_t number = 000, status status_ = CLEAN, size_t rate = 20);

        /**
        * \brief getters
        */
        string getUser() const;

        bool operator==(const Room& other);
};




#endif