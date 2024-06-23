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
        size_t capacity_; //capacity of the hotel 
        size_t openRooms_; //number of open rooms in the hotel


        /**
        * @brief hash table containing rooms
        * uses separate chaining collison strategy
        */ 
        std::forward_list<Room>* data_;

    public:
        
        size_t buckets_ = DEFAULT_ROOMS; //buckets for the hash table
        /**
        * \brief Default number of rooms, used by constructor, normally, buckets is set to the number of rooms
        */
        static constexpr size_t DEFAULT_ROOMS = 100;
        

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
        * \param room - room to check for 
        */
        bool exists(const Room& room) const;


        /** 
        * \brief adds a room to the data 
        * \param room to insert
        */
        void insert(const Room& room); 


        /**
        * \brief checks in a customer
        * \param room to insert
        */
        void checkIn();

        //Getters
        string getName() const;
        size_t numOpen() const;

};

#endif