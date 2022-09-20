/*
 * Title:		Professor Header File
 * Purpose:		P P P P P P P P P
 * Author:		Christian Case Wright
 * Date:		May 05, 2022
 */

#ifndef SCHOOL_INHERITANCE_PROFESSOR_H
#define SCHOOL_INHERITANCE_PROFESSOR_H

#include "date.h"
#include "person.h"

enum Rank {ASSISTANT_PROFESSOR, ASSOCIATE_PROFESSOR, PROFESSOR};

class Professor : public Person{
    string _department;
    Date _hireDate;
    Rank _rank;
    float _salary;
public:
    Professor(const string& name, const Date& birthday, const string& department);
    Professor(const string& name, const Date& birthday, const string& department, const Date & hireDate);
    Professor(const string& name, const Date& birthday, const string& department, const Date& hireDate, Rank rank, float salary);
    virtual ~Professor();
    virtual string ToString()const;
    virtual void Read(istream& input);
    virtual void Write(ostream& output)const;
    void Raise(float percentage);
    void Promote();
    Rank GetRank()const;
    float GetSalary()const;

};



#endif
