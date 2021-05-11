#include <iostream>
#include <string>
using namespace std;

class Bill;
class Customer;
class Date;
class Order;
class Room;

const string hotel = "Duisburg Happy Sleeping";
const int numberOfRooms = 4;

class Date {
private:
	int day;
	int month;
	int year;
public:
	Date(int d = 9, int m = 1, int y = 2015) : day{d}, month{m}, year{y} {}
	friend istream& operator>>(istream& is, Date& d);
	friend ostream& operator<<(ostream& out, const Date& d);
	friend bool operator==(const Date &d1, const Date &d2);
};

istream& operator>>(istream& is, Date& d) {
	cout << "Enter day: " << endl;
	is >> d.day;
	cout << "Enter month: " << endl;
	is >> d.month;
	cout << "Enter year: " << endl;
	is >> d.year;

	// is >> d.day >> d.month >> d.year;
	return is;
}

ostream& operator<<(ostream& out, const Date& d) {

	string dx = to_string(d.day);
	string mx = to_string(d.month);

	if (d.day < 10) 
		dx = "0" + dx;
	if (d.month < 10)
		mx = "0" + mx;
	out << dx << "." << mx << "." << d.year << endl;
	return out;
}

bool operator==(const Date &d1, const Date &d2) {
	return (d1.year == d2.year) && (d1.month == d2.month) && (d1.year == d2.year);
}

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