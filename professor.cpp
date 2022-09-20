/*
 * Title:		Professor Class
 * Purpose:		Initializes, creates, and manipulates professor object - inherits from Date and Person
 * Author:		Christian Case Wright
 * Date:		May 08, 2022
 */

#include "date.h"
#include "person.h"
#include "professor.h"

#include <sstream>
using std::stringstream;

Professor::Professor(const string &name, const Date &birthday,
                     const string &department): Person(name, birthday),
                     _department(department), _hireDate(Date::Now()), _rank(Rank(0)), _salary(60000.0) {

}

Professor::Professor(const string &name, const Date &birthday, const string &department,
                     const Date &hireDate): Person(name, birthday), _department(department), _hireDate(hireDate) {

    // assigns rank and salary based on how long they have been with the school
    if ((Date::Now().GetYear() - _hireDate.GetYear()) < 5)
    {
        _rank = Rank(0);
        _salary = 60000.0;
    }
    else if ((Date::Now().GetYear() - _hireDate.GetYear()) < 10)
    {
        _rank = Rank(1);
        _salary = 70000.0;
    }
    else
    {
        _rank = Rank(2);
        _salary = 75000.0;
    }
}

Professor::Professor(const string &name, const Date &birthday, const string &department, const Date &hireDate,
                     Rank rank, float salary): Person(name, birthday),_department(department), _hireDate(hireDate),
                     _rank(rank), _salary(salary) {

}

Professor::~Professor() {

}

// writes datamembers to a string and returns it
string Professor::ToString() const
{
    stringstream ss;
    ss << "{Person: {name: " << _name << ", birthday: " << _birthday.ToString() << "}, department: "
          << _department << ", rank: " << _rank << ", hire-date: " << _hireDate.ToString()
          << ", salary: " << _salary << "}";
    return ss.str();
}

// reads each word in a line, validates the input, then stores it in appropriate data member for an object
void Professor::Read(istream &input)
{
    size_t year, month, day, hireYear, hireMonth, hireDay;
    int rank;
    string name, department;
    float salary = 0.0;

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
    input >> department;
    if (input.fail())
    {
        _department = "";
    }
    input >> hireYear;
    if (input.fail())
    {
        _hireDate = Date(0, 0, 0);
    }
    input >> hireMonth;
    if (input.fail())
    {
        _hireDate = Date(0, 0, 0);
    }
    input >> hireDay;
    if (input.fail())
    {
        _hireDate = Date(0, 0, 0);
    }
    input >> rank;
    if (input.fail())
    {
        _rank = Rank(0);
    }
    input >> salary;
    if (input.fail())
    {
        _salary = 0.0;
    }

    _name = name;
    _birthday = Date(year, month, day);
    _department = department;
    _hireDate = Date(hireYear, hireMonth, hireDay);
    _rank = Rank(rank);
    _salary = salary;
}

// writes datamembers to output
void Professor::Write(ostream &output) const {
    output << "R "<< _name << " " << _birthday.GetYear() << " " << _birthday.GetMonth() << " " << _birthday.GetDay()
    << " " << _department << " " << _hireDate.GetYear() << " " << _hireDate.GetMonth() << " " << _hireDate.GetDay()
    << " " << _rank << " " << _salary;
}

// applies raise to professor object
void Professor::Raise(float percentage) {
    _salary *= (1 + percentage);
}

// promotes professor object
void Professor::Promote() {
    if (_rank == Rank(0))
    {
        _rank = Rank(1);
    }
    else if(_rank == Rank(1))
    {
        _rank = Rank(2);
    }
}

// returns rank
Rank Professor::GetRank() const {
    return _rank;
}

// returns salary
float Professor::GetSalary() const {
    return _salary;
}
