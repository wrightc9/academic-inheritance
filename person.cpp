/*
 * Title:		Person Class
 * Purpose:		Initializes, creates, and manipulates person object
 * Author:		Christian Case Wright
 * Date:		May 05, 2022
 */
#include "person.h"
#include "date.h"

Person::Person(const string& name, Date birthday): _name(name), _birthday(birthday)
{

}

Person::Person(const string& name, size_t day, size_t month, size_t year):_name(name), _birthday(year, month, day)
{

}

Person::~Person()
{

}

string Person::ToString() const
{
    string retVal = "{name: " + _name + ", birthday: " + _birthday.ToString() + "}";
    return retVal;
}

// reads each word in a line, validates the input, then stores it in appropriate data member for an object
void Person::Read(istream &input)
{
    size_t year, month, day;
    string name;

    input >> name;
    if (input.fail())
    {
        _name = "";
    }
    input >> year;
    if (input.fail())
    {
        _birthday = Date(0, 0, 0);
    }
    input >> month;
    if (input.fail())
    {
        _birthday = Date(0, 0, 0);
    }
    input >> day;
    if (input.fail())
    {
        _birthday = Date(0, 0, 0);
    }
    _name = name;
    _birthday = Date(year, month, day);
}

// writes properties of person class to output
void Person::Write(ostream &output)
{
    output << "P " << _name << " " << _birthday.GetYear() << " " << _birthday.GetMonth() << " " << _birthday.GetDay();
}

// returns the contents of name datamember
string Person::GetName() const
{
    return _name;
}

// returns age
size_t Person::GetAge() const
{
    return Date::Now().GetYear() - _birthday.GetYear();
}
