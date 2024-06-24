#ifndef _HOTEL_
#define _HOTEL_

#include "room.hpp"

#include <forward_list>
#include <iostream>

using namespace std;
/**
 * Hotel
 *
 * Implements Hotel object, containing 
 * implemented as a hashset of room objects
 */
class Hotel {
    private:
        string name_;
        size_t openRooms_; //number of open rooms in the hotel


        /**
        * @brief hash table containing rooms
        * uses separate chaining collison strategy
        */ 
        std::forward_list<Room>* data_;

    public:
        size_t capacity_; //capacity of the hotel 
        size_t buckets_ = DEFAULT_ROOMS; //buckets for the hash table

        //testing variables
        size_t rehashCount = 0;

        /**
        * \brief Default number of rooms, used by constructor, normally, buckets is set to the number of rooms
        */
        static constexpr size_t DEFAULT_ROOMS = 100;
        static constexpr double MAX_LOAD_FACTOR = 0.8; //default load factor before resizing

        //omitting load factor since size of set is fixed

        /**
        * \brief constructor
        */
        explicit Hotel(string name);

        /** 
        * \brief Destructor 
        */
        ~Hotel();

        /**
        * @brief hash table functions
        */

        /** 
        * \brief simple hash function 
        * \param room to insert
        */
        size_t hash(const Room& room) const;

        /**
        * \brief check if in the hash table
        * \param room - const Room& object to check for 
        */
        bool exists(const Room& room) const;


        /** 
        * \brief adds a room to the data 
        * \param room to insert
        */
        void insert(const Room& room);

        /**
         * \brief returns the current load factor of data_
        */
        double loadFactor() const;

        /**
         * \brief rehashes data_
        */
        void rehash();










        /**
        * \brief checks in a customer
        * \param room to insert
        */
        void checkIn();

        
        /**
        * \brief adds room with just number
        * \param room to insert
        */
        void numberAddRoom(size_t roomNum);

        /**
        * \brief finds room with just number
        * 
        */
       bool numberExists(size_t number) const;

       /**
        * hotel functions
       */


        //Getters
        string getName() const;
        size_t numOpen() const;
        std::forward_list<Room>* getData();


};

#endif