/*
 * Title:		Date Class Declaration
 * Purpose:		A Class to represent a simple date
 * Author:		Carlos Arias
 * Date:		April 16, 2020
 */
#ifndef SCHOOL_INHERITANCE_DATE_H
#define SCHOOL_INHERITANCE_DATE_H

#include <string>
#include <iostream>
using std::string;
using std::ostream;
using std::istream;

class Date {
	size_t _year;
	size_t _month;
	size_t _day;
public:
	Date();
    Date(size_t year, size_t month, size_t day);
	int Difference(const Date& other)const;
	string ToString()const;
	string ToLongString()const;
	size_t GetYear()const;
	size_t GetMonth()const;
	size_t GetDay()const;
	bool IsInvalidDate()const;
	static Date Now();
	friend istream& operator>>(istream& input, Date& date);
	friend ostream& operator<<(ostream& output, const Date& date);
};


#endif
