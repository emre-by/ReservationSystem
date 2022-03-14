#include <iostream>
#include <string>
#include <iomanip>
#include "breakfast.hpp"

using namespace std;

Breakfast::Breakfast(Date d, Customer* c, Order* n)
: Order {d, c, n} {
	// cout << "Breakfast created" << endl;
}

Breakfast::~Breakfast() {
	cout << "Deleting Breakfast" << endl;
}

/*
Breakfast::Breakfast(Date d, Customer* c, Order* n)
: bookedfor{d}, customer{c}, next{n} {
	cout << "Breakfast created" << endl;
}
*/
double Breakfast::get_price() {
	return 9.9;
}

void Breakfast::print() {
	cout << fixed << setprecision(2);
	cout << this->get_bookedFor() << setw(10)  << this->get_price() << " EUR: Breakfast" << endl;

	// cout << this->date << endl;
	// cout << this->get_price() << endl;
	// cout << "Breakfast" << endl;
}