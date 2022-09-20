/*
 * Title:		Person Header File
 * Purpose:		P P P P P P P P P
 * Author:		Christian Case Wright
 * Date:		May 05, 2022
 */

#ifndef SCHOOL_INHERITANCE_PERSON_H
#define SCHOOL_INHERITANCE_PERSON_H

#include "date.h"

class Person : public Date{
protected:
    string _name;
    Date _birthday;
public:
    Person(const string& name, Date birthday);
    Person(const string& name, size_t day, size_t month, size_t year);
    virtual ~Person();
    virtual string ToString() const;
    virtual void Read(istream& input);
    virtual void Write(ostream& output);
    string GetName() const;
    size_t GetAge() const;
};


#endif
