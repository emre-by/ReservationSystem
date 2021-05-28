#include <iostream>
#include <string>
#include "date.hpp"
using namespace std;

Date::Date(int d, int m, int y) : day{d}, month{m}, year{y} {}

int Date::get_day() {
	return day;
}

int Date::get_month() {
	return month;
}

int Date::get_year() {
	return year;
}

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
	out << dx << "." << mx << "." << d.year;
	return out;
}

bool operator==(const Date &d1, const Date &d2) {
	return (d1.year == d2.year) && (d1.month == d2.month) && (d1.year == d2.year);
}
