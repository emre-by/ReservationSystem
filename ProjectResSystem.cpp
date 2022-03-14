#include <iostream>
#include <string>
#include "global_header.hpp"
#include "date.hpp"
#include "customer.hpp"
#include "room.hpp"
#include "order.hpp"
#include "breakfast.hpp"
#include "accomodation.hpp"
#include "single.hpp"
#include "double.hpp"

using namespace std;

Customer* searchCustomer(const string& name) {
	for (Customer* x = customer; x != nullptr; x = x->get_next() ) {
		if (x->get_name() == name) {
			// cout << "Customer found" << endl;
			return x;
		}
	}
	cout << "Customer not found" << endl;
	return nullptr;
}

Room* searchFreeRoom(Date date, unsigned int beds) {
	Room* roomToReturn = nullptr;
	unsigned int counter = 0;

	Room* copyRooms[numberOfRooms];

	for (int i = 0; i < numberOfRooms; i++)
		copyRooms[i] = rooms[i];

	// Take the first empty room with enough beds
	if (order == nullptr) {
		for (int i = 0; i < numberOfRooms; ++i) {
			if (static_cast<int>(beds) <= rooms[i]->get_beds()) {
				roomToReturn = rooms[i];
				break;
			}
		}
	}
	else {
		for (Order* x = order; x != nullptr; x = x->get_next()) {
			if ((x->get_bookedFor() == date) && (x->get_price() > 30.0))
				counter += 1;
		}
		// cout << "Number of room orders: " << counter << " on given date: " << date << endl;

		if (counter == numberOfRooms) {
			cout << "Search free room did not find any empty rooms" << endl;
			roomToReturn = nullptr;
		}
		else {
			for (Order* x = order; x != nullptr; x = x->get_next()) {
				if ((x->get_bookedFor() == date) && (x->get_price() > 30.0)) {
					for (int i = 0; i < numberOfRooms; i++) {
						if (copyRooms[i] == x->get_room())
							copyRooms[i] = nullptr;
					}
				}
			}

			for (int i = 0; i < numberOfRooms; ++i) {
				if ((copyRooms[i] != nullptr) && (static_cast<int>(beds) <= rooms[i]->get_beds())) {
					roomToReturn = copyRooms[i];
					break;
				}
			}

		}

	}

	return roomToReturn;
}

char printMenu() {
	char k;
	cout << "HOTEL RESERVATION SYSTEM" << endl;
	cout << hotel << endl;
	cout << "e end\n";
	cout << "n new customer\n";
	cout << "p print all customers\n";
	cout << "a accomodation booking\n";
	cout << "b breakfast booking\n";
	cout << "s show all orders\n";
	cout << "your choice: ";
	cin >> k;
	return k;
}

void newCustomer() {
	cin.ignore();
	string cName;
	string cPhone;
	cout << "Creating new Customer\n";

	cout << "name of customer: ";
	getline(cin, cName);

	cout << "Phone number: ";
	getline(cin, cPhone);

	customer = new Customer{ cName, cPhone, customer };
	// cout << "Currently created customer: " << endl;
	// cout << customer->get_name() << endl;
}

void printAllCustomers() {
	/*
	if (customer->get_next() == nullptr) {
		cout << *customer;
		cout << "End of list" << endl;
	}
	else {
		cout << *customer;
		printAllCustomers(customer->get_next());
	}
	*/
	cout << "#######################" << endl;
	cout << "LIST OF CUSTOMERS" << endl;
	for (Customer* x = customer; x != nullptr; x = x->get_next() )
		cout << *x;
	cout << "#######################" << endl;
}

void accomodationBooking() {
	cin.ignore();
	string customerName;
	Date d;
	char r, b, g;
	Room* available = nullptr;
	bool gr;

	cout << "for which customer name: ";
	// cin >> customerName;
	getline(cin, customerName);

	Customer* cx = searchCustomer(customerName);

	if (cx != nullptr) {
		cout << "for which date: ";
		cin >> d;
		// cout << d << endl;

		cout << "d for double room, s for single room: ";
		cin >> r;

		switch (r) {
			case 'd':
				available = searchFreeRoom(d, 2);
				break;
			case 's':
				available = searchFreeRoom(d, 1);
				break;
		}

		if (available) {
			// cout << "Room is available" << endl;
			
			cout << "b for breakfast, w for without: ";
			cin >> b;
			
			cout << "g for garage, w for without: ";
			cin >> g;

			if (g == 'g')
				gr = true;
			else
				gr = false;

			switch (r) {
				case 'd':
					order = new Double{ d.get_day(), d.get_month(), d.get_year(), cx, available, gr, order };
					if (b == 'b') {
						order = new Breakfast {d, cx, order};
						order = new Breakfast {d, cx, order};
					}
					break;
				case 's':
					if ( available->get_beds() == 2 )
						order = new Double{ d.get_day(), d.get_month(), d.get_year(), cx, available, gr, order, 1 };
					else
						order = new Single{ d.get_day(), d.get_month(), d.get_year(), cx, available, gr, order };
					if (b == 'b')
						order = new Breakfast {d, cx, order};
					break;
			}
		}
		else 
			cout << "sorry no free room at this date" << endl;
	}
	else
		cout << "sorry customer not found" << endl; // error message?
}

void breakfastBooking() {
	cin.ignore();
	Date d;
	string customerName;

	cout << "for which customer name: ";
	// cin >> customerName;
	getline(cin, customerName);

	Customer* cx = searchCustomer(customerName);

	if (cx != nullptr) {
		cout << "for which date: ";
		cin >> d;
		// cout << d << endl;
		order = new Breakfast { d, cx, order };
	}
}

void showAllOrders() {
	cout << "#######################" << endl;
	cout << "LIST OF ALL ORDERS" << endl;
	for (Order* x = order; x != nullptr; x = x->get_next()) {
		x->print();
	}
	cout << "#######################" << endl;

	/*
	for (Order* x = order; x != nullptr; x = x->get_next()) {
		if (x->get_price() != 9.9) {
			x->print();
			for (Order* y = order; y != nullptr; y = y->get_next()) {
				if ((x->get_customer() == y->get_customer()) && (y->get_price() == 9.9))
					y->print();
			}
		}
	}*/
}

void deleteHeapObjects() {
	for (Customer* x = customer; x != nullptr; x = x->get_next() )
		delete x;
	customer = nullptr;

	for (Order* x = order; x != nullptr; x = x->get_next() )
		delete x;
	order = nullptr;
}

int main() {

	// ############## CREATE ROOMS  ############## 
	for (int i = 0; i < (numberOfRooms / 2); i++) {
		rooms[i] = new Room{ 1, 1, 0 };
	}

	for (int i = (numberOfRooms / 2); i < numberOfRooms; i++) {
		rooms[i] = new Room{ i, 2, 1 };
	}

	cout << hotel << endl;
	for (int k = 0; k < numberOfRooms; k++) {
		rooms[k]->print();
		cout << endl;
	}

	// ############## MENU PRINT  ############## 
	char option;
	do {
		option = printMenu();
	} while(!(option == 'e' || option == 'n' || option == 'p' || option == 'a' || option == 'b' || option == 's'));

	// cout << "your choice: " << option << endl;

	do {
		switch(option) {
			case 'n':
				newCustomer();
				option = printMenu();
				break;
			case 'p':
				printAllCustomers();
				option = printMenu();
				break;
			case 'a':
				accomodationBooking();
				option = printMenu();
				break;
			case 'b':
				breakfastBooking();
				option = printMenu();
				break;
			case 's':
				showAllOrders();
				option = printMenu();
				break;
			}
	} while(!(option == 'e'));

	deleteHeapObjects();

	return 0;
}