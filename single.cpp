#include <iostream>
#include <string>
#include <iomanip>
#include "single.hpp"

using namespace std;

// ############ Single Class ####################
Single::Single(int d, int m, int y, Customer* c, Room* r, bool gr, Order* n) 
: Accomodation { d, m, y, c,  r, gr, n } {
	// cout << "New Single Room" << endl;
}

Single::~Single() {
	cout << "Deleting Single" << endl;
}

double Single::get_price() {
	return 49.0 + this->priceForParking();
}

void Single::print() {
	cout << fixed << setprecision(2);
	cout << this->get_bookedFor() << setw(10)  << this->get_price() << " EUR: ";
	this->get_room()->print();
	if (this->priceForParking() != 0)
		cout << ", garage";
	cout << " (as single)" << endl;
}