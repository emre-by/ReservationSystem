#ifndef BREAKFAST_HPP
#define BREAKFAST_HPP
#include <iostream>
#include <string>
#include "order.hpp"

using namespace std;

class Breakfast : public Order {
public:
	Breakfast(Date d, Customer* c, Order* n = nullptr);
	~Breakfast();
	virtual double get_price();
	virtual void print();
};
#endif