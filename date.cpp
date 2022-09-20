/*
 * Title:		Date Class Method Definition
 * Purpose:		Implementation of all date class methods
 * Author:		Carlos Arias
 * Date:		April 16, 2020
 */
#include "date.h"

#include <string>
#include <iostream>
#include <ctime>
#include <cmath>
#include <sstream>

using std::string;
using std::stringstream;
using std::istream;
using std::ostream;

/**
 * Validates a date
 * This function (local to date.cpp) will check if the date represented
 * by year month day parameters is a valid date. Checks for leap years,
 * valid month numbers and valid day numbers. As the type of the parameters
 * is unsigned there is no need to check for negative numbers.
 * Year can be any value (but no negatives!), this date implementation does
 * not consider years BC.
 * Month can be an integer number between 1 and 12
 * Day, months with 31 days: 1, 3, 5, 7, 8, 10, 12; months with 30 days:
 * 4, 6, 9, 11. A year is leap if the year is divisible by 4 but not divisible
 * by 100 unless is divisible by 400.
 * @param year the year of the date
 * @param month the month of the date
 * @param day the day of the date
 * @return true if the date is valid, false otherwise
 */

bool IsValidDate(size_t year, size_t month, size_t day){
	if (month == 0 || month > 12 || day == 0 || day > 31){ // date is invalid
		return false;
	}else{
		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12){
			// Months that have 31 days, at this point the 1 <= day <= 31
			return true;
		}else if (month == 4 || month == 6 || month == 9 || month == 11){
			if (day == 31){ // date is invalid
				return false;
			}else{
				return true;
			}
		}else { // _month is 2
			bool yearIsLeap;
			if (year % 4 == 0){
				if (year % 100 == 0){
					if (year % 400 == 0){
						yearIsLeap = true;
					}else{
						yearIsLeap = false;
					}
				}else{
					yearIsLeap = true;
				}
			}else{
				yearIsLeap = false;
			}
			if (yearIsLeap){
				if (day > 29){ // date is invalid
					return false;
				}else{
					return true;
				}
			}else{
				if (day > 28){ // date is invalid
					return false;
				}else{
					return true;
				}
			}
		}
	}
}
/**
 * Date Default Constructor
 * By default a date is created with the current time.
 */
Date::Date() {
	*this = Now();
}
/**
 * Date Constructor
 * Creates a date given its parameter. If the date is invalid it sets
 * the year, the month and the day to zero.
 * @param year the year of the date
 * @param month the month of the date
 * @param day the day of the date
 */
Date::Date(size_t year, size_t month, size_t day) {
	if (IsValidDate(year, month, day)){
		_year = year;
		_month = month;
		_day = day;
	}else{
		_year = _month = _day = 0;
	}
}
/**
 * Difference between two dates
 * Calculates the difference in days between two dates.
 * @param other the other date to calculate with
 * @return the absolute value of the difference in days between this and other.
 */
int  Date::Difference(const Date &other) const {
	tm myTime, otherTime;
	myTime.tm_sec = myTime.tm_min = myTime.tm_hour = 0;
	otherTime.tm_sec = otherTime.tm_min = otherTime.tm_hour = 0;

	myTime.tm_year = _year - 1900;
	myTime.tm_mon = _month - 1;
	myTime.tm_mday = _day;

	otherTime.tm_year = other._year - 1900;
	otherTime.tm_mon = other._month - 1;
	otherTime.tm_mday = other._day;

	double days = difftime(mktime(&myTime), mktime(&otherTime)) / (24 * 60 * 60);
	return static_cast<int>(abs(days));
//	return static_cast<int>(days);
}
/**
 * String representation of date
 * Creates a string that represents the date. The string will have the format:
 * Www Mmm dd yyyy where Www is the day of the week, Mmm is the month, dd is the day,
 * yyyy is the year. If the day has a single digit, the day will be filled with a space.
 * Relies in asctime function of ctime
 * @return the string representation of the date
 */
string Date::ToLongString() const {
	tm myTime;
	myTime.tm_sec = myTime.tm_min = myTime.tm_hour = 0;

	myTime.tm_year = _year - 1900;
	myTime.tm_mon = _month - 1;
	myTime.tm_mday = _day;

	mktime(&myTime);
	string date(asctime(&myTime));
	return date.substr(0, 11) + date.substr(20, 4);
}
string Date::ToString() const {
	stringstream retVal;
	retVal << "{year: " << _year << ", month: " << _month << ", day: " << _day << "}";
	return retVal.str();
}
/**
 * Year Accessor
 * @return the year of the date
 */
size_t Date::GetYear() const {
	return _year;
}
/**
 * Month Accessor
 * @return the month of the date
 */
size_t Date::GetMonth() const {
	return _month;
}
/**
 * Day Accessor
 * @return the day of the date
 */
size_t Date::GetDay() const {
	return _day;
}
/**
 * Get current date
 * This static method can be called without instantiating the class. It will
 * return the current date as stored by the system.
 * @return the current date
 */
Date Date::Now() {
	time_t timeNow;
	time(&timeNow);
	tm* now;
	now = localtime(&timeNow);
	return Date(now->tm_year + 1900, now->tm_mon + 1, now->tm_mday);
}
/**
 * Stream extraction operator overload
 * Reads a date from an input stream. If at any time the extraction operation fails
 * (invalid input) the date is going to be set to year = month = day = 0: an invalid
 * date.
 * @param input input stream to read from
 * @param date the instance where the values are going to be stored
 * @return the input stream to allow chaining
 */
istream& operator>>(istream& input, Date& date){
	size_t year, month, day;
	input >> year;
	if (input.fail()){
		date._year = date._month = date._day = 0;
		return input;
	}
	input >> month;
	if (input.fail()){
		date._year = date._month = date._day = 0;
		return input;
	}
	input >> day;
	if (input.fail()){
		date._year = date._month = date._day = 0;
		return input;
	}
	date._year = year;
	date._month = month;
	date._day = day;
	return input;
}
/**
 * Stream insertion operator overload
 * Writes a date to an output stream
 * @param output output stream to write to
 * @param date the instance of date that is going to writen to output
 * @return the output stream to allow chaining
 */
ostream& operator<<(ostream& output, const Date& date){
	output << date._year << " " << date._month << " " << date._day;
	return output;
}

bool Date::IsInvalidDate() const {
	return (_year == 0 || _month == 0 || _day == 0);
}


