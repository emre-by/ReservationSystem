#ifndef DATE_HPP
#define DATE_HPP
#include <iostream>

using namespace std;

class Date {
private:
	int day;
	int month;
	int year;
public:
	Date(int d = 9, int m = 1, int y = 2015);
	int get_day();
	int get_month();
	int get_year();
	friend istream& operator>>(istream& is, Date& d);
	friend ostream& operator<<(ostream& out, const Date& d);
	friend bool operator==(const Date &d1, const Date &d2);
};

#endif