#include <iostream>
#include <string>
#include <iomanip>
#include "double.hpp"

using namespace std;

// ############ Double Class ####################
Double::Double(int d, int m, int y, Customer* c, Room* r, bool gr, Order* n, int bb)
: Accomodation {  d, m, y, c,  r, gr, n  }, bookedBeds {bb} {
	// cout << "New Double Room" << endl;
	if (r->get_beds() < 2)
		cout << "additional bed required" << endl;
}

Double::~Double() {
	cout << "Deleting Single" << endl;
}

double Double::get_price() {
	if (this->bookedBeds == 1)
		return 49.0 + this->priceForParking();
	else
		return 69.0 + this->priceForParking();
}

void Double::print() {
	cout << fixed << setprecision(2);
	cout << this->get_bookedFor() << setw(10)  << this->get_price() << " EUR: ";
	this->get_room()->print();
	if (this->priceForParking() != 0)
		cout << ", garage";
	if (this->bookedBeds == 2)
		cout << " (as double)";
	else
		cout << " (as single)";
	cout << endl;
}