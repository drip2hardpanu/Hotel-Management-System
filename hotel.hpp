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
        size_t occupied_ = 0;
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
       * \brief lookup for data_ using room number 
      */
        Room& lookup(size_t number) const;


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
        * \brief adds room with number
        * \param room to insert
        */
        void addRoom(size_t roomNum);

        /**
        * \brief finds room with just number
        * 
        */
       bool numberExists(size_t number) const;


        /**
        * \brief finds room with just number
        * 
        */
       status getStatus(size_t number) const;

       /**
        * \brief returns the number of an open room 
       */
      Room& findOpen() const;


      /**
       * \brief customer functions
      */

     /**
      * \brief checks in customer
      * \param cust - name of customer to check in
     */
      void checkIn(string cust);

      /**
       * \brief checks out room 
       * \param num - room number to check out
      */
      void checkOut(size_t num);

    
      /**
       * \brief checks if the hotel is full
      */
      bool checkFull() const;


      //Getters
      string getName() const;
      size_t numOpen() const;
      std::forward_list<Room>* getData();


};

#endif