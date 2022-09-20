/*
 * Title:		Student Class
 * Purpose:		Initializes, creates, and manipulates student object - inherits from Date and Person
 * Author:		Christian Case Wright
 * Date:		May 08, 2022
 */

#include "date.h"
#include "person.h"
#include "student.h"

#include <sstream>

using std::stringstream;

Student::Student(const string &name,
                 const Date &birthday) : Person(name, birthday), _major("Undecided"), _credits(0), _gpa(0.0){

}

Student::Student(const string &name, const Date &birthday,
                 const string &major) : Person(name, birthday), _major(major), _credits(0), _gpa(0.0) {

}

Student::~Student() {

}

// puts data members in string format and returns string
string Student::ToString() const
{
    stringstream ss;
    ss << "{Person: {name: " << _name << ", birthday: " << _birthday.ToString() << "}, major: "
            << _major << ", gpa: " << _gpa << ", credits: " << _credits << "}";


    return ss.str();
}

// reads each word in a line, validates the input, then stores it in appropriate data member for an object
void Student::Read(istream &input)
{
    size_t year, month, day, credits;
    string name, major;
    float gpa;

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
    input >> major;
    if (input.fail())
    {
        major = "";
    }
    input >> credits;
    if (input.fail())
    {
        credits = 0;
    }
    input >> gpa;
    if (input.fail())
    {
        gpa = 0.0;
    }

    _name = name;
    _birthday = Date(year, month, day);
    _major = major;
    _credits = credits;
    _gpa = gpa;
}

// writes data members to output
void Student::Write(ostream &output) {
    output << "S " << _name << " " << _birthday.GetYear() << " " << _birthday.GetMonth()
    << " " << _birthday.GetDay() << " " << _major << " " << _credits << " " << _gpa;
}

// adds grade and updates gpa and credit total
void Student::AddGrade(float grade, size_t credits) {
    size_t totalC = _credits + credits;
    _gpa = ((grade * static_cast<float>(credits)) + (_gpa * static_cast<float>(_credits))) /
            static_cast<float>(totalC);
    _credits = totalC;
}

// returns gpa
float Student::GetGPA() const {
    return _gpa;
}

// returns credits
size_t Student::GetCredits() const {
    return _credits;
}
