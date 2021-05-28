#ifndef ACCOMODATION_HPP
#define ACCOMODATION_HPP
#include <iostream>
#include <string>
#include "date.hpp"
#include "customer.hpp"
#include "room.hpp"
#include "order.hpp"

using namespace std;

class Accomodation : public Order {
private:
	bool garage;
	Room* room;
public:
	Accomodation(int d, int m, int y, Customer* c, Room* r, bool gr = 0, Order* n = nullptr);
	virtual ~Accomodation();
	virtual Room* get_room();
	virtual void print();
protected:
	double priceForParking();
};

#endif