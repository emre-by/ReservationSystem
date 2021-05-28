#include <iostream>
#include <string>
#include "order.hpp"

using namespace std;

// ############ Order Class ####################
Order::Order(Date d, Customer* c, Order* n)
: bookedfor{d}, customer{c}, next{n} {
	bill = nullptr;
	cout << "New Order" << endl;
};

Order::~Order() {
	cout << "Deleting Order" << endl;
}

Date Order::get_bookedFor() const {
	return bookedfor;
}

Customer* Order::get_customer() const {
	return customer;
}

Order* Order::get_next() {
	return next;
}

bool Order::invoiced() {
	if (bill != nullptr)
		return true;
	else
		return false;
}

void Order::set_bill(Bill* newBill) {
	bill = newBill;
}

Room* Order::get_room() {
	return nullptr;
}

double Order::get_price() {
	return 0.0;
}

void Order::print() {

}

void Order::printInfo() {
	cout << "Order pointer: " << this << endl;
	cout << "Order class next pointer: " << next << endl;
}