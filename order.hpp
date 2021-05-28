#ifndef ORDER_HPP
#define ORDER_HPP
#include <iostream>
#include <string>
#include "date.hpp"
#include "customer.hpp"
#include "room.hpp"

using namespace std;

class Bill {
};

class Order {
private:
	Date bookedfor;
	Bill* bill;
	Customer* customer;
	Order* next;
public:
	Order(Date d, Customer* c, Order* n = nullptr);
	Date get_bookedFor() const;
	Customer* get_customer() const;
	Order* get_next();
	bool invoiced();
	void set_bill(Bill* newBill);
	virtual Room* get_room();
	virtual double get_price() = 0;
	virtual void print() = 0;
	virtual ~Order();
	void printInfo();
};

#endif