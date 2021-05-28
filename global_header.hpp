#ifndef GLOBAL_HEADER_HPP
#define GLOBAL_HEADER_HPP
#include <string>
#include <vector>

using namespace std;

class Bill;
class Customer;
class Date;
class Order;
class Room;

const string hotel = "Duisburg Happy Sleeping";
const int numberOfRooms = 4;
Room* rooms[numberOfRooms]; // Stack Object
//Room** rooms = new Room*[numberOfRooms]; // Heap Object

Customer* customer = nullptr;
Order* order = nullptr;

#endif