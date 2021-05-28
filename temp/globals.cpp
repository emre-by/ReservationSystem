#include <iostream>
#include <string>
#include "date.hpp"
#include "customer.hpp"
#include "order.hpp"

using namespace std;

class Bill;
class Customer;
class Date;
class Order;
class Room;

const string hotel = "Duisburg Happy Sleeping";
const int numberOfRooms = 4;

Room* rooms = new Room[numberOfRooms];
Customer* customers = NULL;
Order* orders = NULL;

/*
Customer* searchCustomer(string name) {
	return *;
}
*/

int main() {
	Date d1{2, 4, 2020};
	Date d2{};
	cout << d1;

	cin >> d2;
	cout << d2;

	bool k = (d1 == d2);

	cout << k << endl;

	return 0;
}