#ifndef CUSTOMER_HPP
#define CUSTOMER_HPP
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Customer {
private:
	string name;
	string phone;
	Customer* next;
	// static int counter;
	// static vector<Customer*> CustomerList;
public:
	Customer(const string& name, const string& phone = "", Customer* next = nullptr);
	~Customer();
	string get_name() const;
	Customer* get_next() const;
	friend ostream& operator<<(ostream& out, const Customer& c);
};

// Customer* searchCustomer(const string& name);

#endif