#ifndef DOUBLE_HPP
#define DOUBLE_HPP
#include <iostream>
#include <string>
#include "date.hpp"
#include "customer.hpp"
#include "room.hpp"
#include "accomodation.hpp"

using namespace std;

class Double : public Accomodation {
public:
	Double(int d, int m, int y, Customer* c, Room* r, bool gr = 0, Order* n = nullptr);
	~Double();
	virtual double get_price();
	virtual void print();
};

#endif