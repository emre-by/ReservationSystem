#ifndef ROOM_HPP
#define ROOM_HPP
#include <iostream>

using namespace std;

class Room {
private:
	int no; // room number
	unsigned int beds; // number of beds
	bool balcony; // if there is a balcony or not
public:
	Room(int no, unsigned int beds, bool balcony);
	int get_beds() const;
	void print() const;
};

#endif