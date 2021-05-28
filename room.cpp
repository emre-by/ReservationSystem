#include <iostream>
#include <string>
#include "room.hpp"

using namespace std;

Room::Room(int no, unsigned int beds, bool balcony) : no{no}, beds{beds}, balcony{balcony} {}

int Room::get_beds() const {
	return beds;
}

void Room::print() const {
	switch (balcony) {
		case 0:
			cout << "room no. " << no << ", " << beds << " bed(s)";
			break;
		case 1:
			cout << "room no. " << no << ", " << beds << " bed(s), balcony";
			break;
	}
}