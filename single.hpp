#ifndef SINGLE_HPP
#define SINGLE_HPP
#include <iostream>
#include <string>
#include "date.hpp"
#include "customer.hpp"
#include "room.hpp"
#include "accomodation.hpp"

using namespace std;

class Single : public Accomodation {
public:
	Single(int d, int m, int y, Customer* c, Room* r, bool gr = 0, Order* n = nullptr);
	~Single();
	virtual double get_price();
	virtual void print();
};

#endif