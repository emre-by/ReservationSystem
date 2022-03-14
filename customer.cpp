#include <iostream>
#include <string>
#include <vector>
#include "customer.hpp"

using namespace std;

// vector<Customer*> Customer::CustomerList;
// int Customer::counter;

Customer::Customer(const string& name, const string& phone, Customer* next)
: name{name}, phone{phone}, next{next} {
	// CustomerList.push_back(this);
	// counter++;
	// cout << "A new customer is created to the list, customer number: " << counter << endl;
	// cout << "Pointer of this customer: " << CustomerList.at(0) << endl;
	// cout << "New Customer" << endl;
}

Customer::~Customer() {
	cout << "Deleting customer: " << name << endl;
}

string Customer::get_name() const {
	return name;
}

Customer* Customer::get_next() const {
	return next;
}

ostream& operator<<(ostream& out, const Customer& c) {
	out << c.name << ", phone: " << c.phone << endl;
	return out;
}