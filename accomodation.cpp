#include <iostream>
#include <string>
#include <iomanip>
#include "accomodation.hpp"

using namespace std;

// ############ Accomodation Class ####################
Accomodation::Accomodation(int d, int m, int y, Customer* c, Room* r, bool gr, Order* n) 
	: Order{ Date{d, m, y }, c, n } {
		room = r;
		garage = gr;
		// cout << "New Accomodation" << endl;
}

Accomodation::~Accomodation() {
	cout << "Deleting Accomodation" << endl;
}

Room* Accomodation::get_room() {
	return room;
}

void Accomodation::print() {
	cout << "Printing accomodation" << endl;
	cout << fixed << setprecision(2);
	cout << this->get_bookedFor() << setw(10)  << this->get_price() << " EUR: Breakfast" << endl;
}

double Accomodation::priceForParking() {
	if (garage == 0)
		return 0.0;
	else
		return 15.0;

}