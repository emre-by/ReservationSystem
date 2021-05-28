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
			cout << "Customer found" << endl;
			return x;
		}
	}
	cout << "Customer not found" << endl;
	return nullptr;
}

Room* searchFreeRoom(Date date, unsigned int beds) {
	Room* roomToReturn = nullptr;
	unsigned int counter = 0;
	// unsigned int i = 0;
	// unsigned int j = 0;

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
		cout << "Number of room orders: " << counter << " on given date: " << date << endl;

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
	string customerName;
	string customerPhone;

	cout << "Creating new Customer\n";

	cout << "Name of customer:\n";
	cin >> customerName;

	cout << "Phone number:\n";
	cin >> customerPhone;

	customer = new Customer{ customerName, customerPhone, customer };
	cout << "Currently created customer: " << endl;
	cout << customer->get_name() << endl;
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

	string customerName;
	Date d;
	char r, b, g;
	Room* available = nullptr;
	bool gr;

	cout << "for which customer name: ";
	cin >> customerName;

	Customer* cx = searchCustomer(customerName);

	if (cx != nullptr) {
		// cout << "customer found" << endl;
		cin >> d;
		cout << d << endl;

		cout << "d for double room, s for single room: " << endl;
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
			cout << "Room is available" << endl;
			
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
	Date d;
	string customerName;

	cout << "for which customer name: ";
	cin >> customerName;

	Customer* cx = searchCustomer(customerName);

	if (cx != nullptr) {
		cin >> d;
		cout << d << endl;
	}

	order = new Breakfast { d, cx, order };
}

void showAllOrders() {
	cout << "#######################" << endl;
	cout << "LIST OF ALL ORDERS" << endl;
	for (Order* x = order; x != nullptr; x = x->get_next()) {
		x->print();
		//x->printInfo();
		cout << *(x->get_customer());
		//cout << "Room pointer: " << x->get_room() << endl;
		cout << endl;
	}
	cout << "#######################" << endl;
}
void menuButtons() {}

int main() {

	// Class tests
	/*
	cout << "numberOfRooms = " << numberOfRooms << endl;
	cout << "Hotel = " << hotel << endl;
	cout << "Rooms = " << rooms << endl;
	cout << "Order = " << orders << endl;

	Customer d{ "Mehmet", "123" };
	Customer y{ "Max", "123", &x };
	Customer z{ "Mustermann", "123", &y };
	Customer k{ "XYZ", "123", &z };
	cout << k.get_next() << endl; 
	cout << &k << endl;

	cout << k.get_next()->get_name() << endl; 

	//Customer* c = searchCustomer("Emre", CustomerListGlobal);
	//cout << x.counter << endl;
	*/

	/*
	Room r1{ 1, 1, 0 };
	r1.print();
	*/

	/*
	Customer x{ "Emre", "123" };
	Date d1{ 10, 2, 2020 };
	Breakfast b{d1, &x};
	b.print();

	Room r(101, 2, 0);

	Single a{1, 1, 2010, &x, &r};
	a.print();
	*/
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

	// Printing number of beds
	/*
	for (auto c : rooms)
		cout << c->get_beds() << endl;
	*/

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

	/*
	newCustomer();
	newCustomer();
	newCustomer();
	newCustomer();
	newCustomer();
	*/

	/*
	cout << "Let's check customers: " << endl;
	cout << "Pointer of customer: " << customer << endl;
	cout << "Cout of customer" << *customer;

	cout << "Pointer of next customer: " << customer->get_next() << endl;
	cout << "Cout of next custumer: " << *(customer->get_next());
	*/

	/*
	printAllCustomers();

	Customer* searchPtr;
	searchPtr = searchCustomer("emre");

	cout << *searchPtr;
	*/

	return 0;
}