/*
 * Title:		Student Header File
 * Purpose:		P P P P P P P P P
 * Author:		Christian Case Wright
 * Date:		May 08, 2022
 */

#ifndef SCHOOL_INHERITANCE_STUDENT_H
#define SCHOOL_INHERITANCE_STUDENT_H

#include "date.h"
#include "person.h"

class Student : public Person {
    string _major;
    size_t _credits;
    float _gpa;

public:
    Student( const string& name, const Date& birthday);
    Student(const string &name, const Date &birthday,const string &major);
    ~Student();
    string ToString() const;
    void Read(istream& input);
    void Write(ostream& output);
    void AddGrade(float grade, size_t credits);
    float GetGPA()const;
    size_t GetCredits()const;
};
#endif
