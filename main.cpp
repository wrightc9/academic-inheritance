#include "date.h"
#include "person.h"
#include "student.h"
#include "professor.h"


#include <iostream>
#include <vector>
#include <fstream>

using std::cin;
using std::cerr;
using std::cout;
using std::endl;
using std::vector;

size_t Menu();


int main(int argc, char* argv[])
{
	vector<Person*> people; // This is the only vector you need, remember to release the memory
	int userOption;
	while ( (userOption = Menu()) != 15){
		if (userOption == 1){			// Add Person

            string name;
            cout << "Name: ";
            cin >> name;

            size_t year, month, day;

            // validates input and creates new person and puts in vector
            while(true)
            {
                cout << "Birth date yyyy mm dd: ";
                cin >> year >> month >> day;
                Date date = Date(year, month, day);
                if (date.IsInvalidDate())
                {
                    cin.clear();
                    cin.ignore();
                    cerr << "Invalid Date!" << endl;

                    continue;
                }
                else // successfully validates
                {
                    Person* person = new Person(name, date);
                    people.push_back(person);
                    break;
                }
            }

            cout << "Person inserted in position: " << people.size() - 1 << endl << endl;

		}else if (userOption == 2){		// Add Student

            string name, major;
            cout << "Name: ";
            cin >> name;

            size_t year, month, day;

            // validates input and creates new student and puts in vector
            while(true)
            {
                cout << "Birth date yyyy mm dd: ";
                cin >> year >> month >> day;
                Date date = Date(year, month, day);
                if (date.IsInvalidDate())
                {
                    cin.clear();
                    cin.ignore();
                    cerr << "Invalid Date!" << endl;

                    continue;
                }
                else // successfully validates
                {
                    cout << "Major: ";
                    cin >> major;

                    Student* student = new Student(name, date, major);
                    people.push_back(student);
                    break;
                }
            }

            cout << "Student inserted in position: " << people.size() - 1 << endl << endl;

		}else if (userOption == 3){		// Add Professor

            string name, department;
            cout << "Name: ";
            cin >> name;

            size_t year, month, day;

            // validates input and creates new person and puts in vector
            while(true)
            {
                cout << "Birth date yyyy mm dd: ";
                cin >> year >> month >> day;
                Date date = Date(year, month, day);
                if (date.IsInvalidDate())
                {
                    cin.clear();
                    cin.ignore();
                    cerr << "Invalid Date!" << endl;

                    continue;
                }
                else // first date validates
                {
                    cout << "Department: ";
                    cin >> department;

                    // validates input and creates new person and puts in vector
                    while(true)
                    {
                        cout << "Hire date yyyy mm dd: ";
                        cin >> year >> month >> day;
                        Date hire = Date(year, month, day);
                        if (hire.IsInvalidDate())
                        {
                            cin.clear();
                            cin.ignore();
                            cerr << "Invalid Date!" << endl;

                            continue;
                        }
                        else // successfully validates
                        {
                            Professor *professor = new Professor(name, date, department, hire);
                            people.push_back(professor);
                            break;
                        }
                    }
                    break;
                }
            }

            cout << "Professor inserted in position: " << people.size() - 1 << endl << endl;

		}else if (userOption == 4){		// List All People

            // lists all objects in the vector
            for(Person* & i : people)
            {
                cout << i->ToString() << endl;
            }

		}else if (userOption == 5){		// Show Students Report

            // lists all students
            for(Person* & i : people)
            {
                if(dynamic_cast<Student*>(i) != nullptr)
                {
                    cout << i->ToString() << endl;
                }
            }

		}else if (userOption == 6){		// Show Professor Report

            // lists all professors
            for(Person* & i : people)
            {
                if(dynamic_cast<Professor*>(i) != nullptr)
                {
                    cout << i->ToString() << endl;
                }
            }

		}else if (userOption == 7){		// Show !Professor !Student

            // lists all non-students and non-professors
            for(Person* & i : people)
            {
                if(dynamic_cast<Student*>(i) == nullptr && dynamic_cast<Professor*>(i) == nullptr)
                {
                    cout << i->ToString() << endl;
                }

            }

		}else if (userOption == 8){		// Calculate Average GPA

            Student* student;
            float totalGPA = 0.0;
            int numStud = 0;

            // gets gpa of all students and calculates average
            for(Person* & i : people)
            {
                if((student = dynamic_cast<Student*>(i)) != nullptr)
                {
                    totalGPA += student->GetGPA();
                    numStud++;
                }
            }

            cout << "The average GPA of the students is: " << totalGPA / numStud << endl;

		}else if (userOption == 9){		// Calculate Average Salary

            Professor* professor;
            float totalSalary = 0.0;
            int numProf = 0;

            // gets salary of all professors and find the average
            for(Person* & i : people)
            {
                if((professor = dynamic_cast<Professor*>(i)) != nullptr)
                {
                    totalSalary += professor->GetSalary();
                    numProf++;
                }

                cout << "The average Salary of the professors is: " << totalSalary / numProf << endl;
            }

		}else if (userOption == 10){	// Input Grades to Student

            size_t credits, sel;
            float grade = 0.0;
            Student* student;

            // lists students with position in front
            for(size_t i = 0; i < people.size(); i++)
            {
                if((student = dynamic_cast<Student*>(people.at(i))) != nullptr)
                {
                    cout << i << " " << student->ToString() << endl;
                }
            }

            // takes selection and validates input
            while(true)
            {
                cout << "Number of student to input grades to: ";
                cin >> sel;

                if(cin.fail()) // validates input is a number
                {
                    cin.clear();
                    cin.ignore(255, '\n');
                    cerr << "Incorrect input!" << endl;

                    continue;
                }
                if(sel >= people.size()) // validates selection is within range
                {
                    cerr << "Position out of range!" << endl;

                    continue;
                }
                if ((student = dynamic_cast<Student *>(people.at(sel))) == nullptr) // verifies selection is a Student
                {
                    cerr << "Person " << people.at(sel)->ToString() << " is not a student" << endl;

                    continue;
                }

                break;
            }

            // asks for grade and validates input
            while(true)
            {
                cout << "Grade of the student [0.0 to 4.0 scale]: ";
                cin >> grade;

                if(cin.fail()) // validates input is a number
                {
                    cin.clear();
                    cin.ignore(255, '\n');
                    cerr << "Incorrect input!" << endl;

                    continue;
                }
                if(grade > 4.0 || grade < 0) // verifies input is between 0 and 4
                {
                    cerr << "Invalid grade value, make sure [0.0, 4.0]" << endl;
                    continue;
                }
                break;
            }

            // validates and takes input for credits
            while(true)
            {
                cout << "Credits {1, 2, 3, 4, 5}: ";
                cin >> credits;

                if(cin.fail()) // validates if it is a number
                {
                    cin.clear();
                    cin.ignore(255, '\n');
                    cerr << "Incorrect input!" << endl;
                    continue;
                }
                if(credits > 5 || credits < 0) // validates input is between 0 and 5
                {
                    cerr << "Invalid credit value, make sure to choose a number 1-5" << endl;
                    continue;
                }
                break;
            }

            // adds grade to student
            student = dynamic_cast<Student*>(people.at(sel));
            student->AddGrade(grade, credits);

		}else if (userOption == 11){	// Promote Professor
            Professor* professor;
            size_t sel;

            // lists all professors with their positions
            for(size_t i = 0; i < people.size(); i++)
            {
                if((professor = dynamic_cast<Professor*>(people.at(i))) != nullptr)
                {
                    cout << i << " " << professor->ToString() << endl;
                }
            }

            // loops until valid selection (it is a number, it is within range, and the selection is a professor)
            while(true)
            {
                cout << "Number of professor to promote: ";
                cin >> sel;

                if(cin.fail()) // if not a number
                {
                    cin.clear();
                    cin.ignore(255, '\n');
                    cerr << "Incorrect input!" << endl;

                    continue;
                }
                if(sel >= people.size()) // out of range
                {
                    cerr << "Position out of range!" << endl;

                    continue;
                }
                if ((professor = dynamic_cast<Professor *>(people.at(sel))) == nullptr) // not a professor
                {
                    cerr << "Person " << people.at(sel)->ToString() << " is not a professor" << endl;

                    continue;
                }

                break;
            }

            professor = dynamic_cast<Professor*>(people.at(sel));
            professor->Promote();

		}else if (userOption == 12){	// Give Raise to Professor
            Professor* professor;
            size_t sel;
            float raise = 0.0;

            // lists all professors with their positions
            for(size_t i = 0; i < people.size(); i++)
            {
                if((professor = dynamic_cast<Professor*>(people.at(i))) != nullptr)
                {
                    cout << i << " " << professor->ToString() << endl;
                }
            }

            // loops until valid selection (it is a number, it is within range, and the selection is a professor)
            while(true)
            {
                cout << "Number of professor to give raise: ";
                cin >> sel;

                if(cin.fail())
                {
                    cin.clear();
                    cin.ignore(255, '\n');
                    cerr << "Incorrect input!" << endl;

                    continue;
                }
                if(sel >= people.size())
                {
                    cerr << "Position out of range!" << endl;

                    continue;
                }
                if ((professor = dynamic_cast<Professor *>(people.at(sel))) == nullptr)
                {
                    cerr << "Person " << people.at(sel)->ToString() << " is not a professor" << endl;

                    continue;
                }

                break;
            }

            // loops until valid input is supplied (between 0 - 50) and is a number
            while (true)
            {
                cout << "Raise to the professor ]0.0, 50.0] ";
                cin >> raise;
                if(cin.fail())
                {
                    cin.clear();
                    cin.ignore(255, '\n');
                    cerr << "Incorrect input!" << endl;
                    continue;
                }
                if(raise > 50 || raise < 0)
                {
                    cerr << "Invalid raise value, make sure to choose a number 0 and 50" << endl;
                    continue;
                }
                break;
            }

            // gives raise to professor
            professor = dynamic_cast<Professor *>(people.at(sel));
            professor->Raise(raise/100);

		}else if (userOption == 13){	// Load from File
            string fileName, type;

            cout << "Input Filename: ";
            cin >> fileName;

            std::ifstream myFile;
            myFile.open(fileName);

            // checks if file is open before reading from file
            if (!myFile.is_open())
            {
                cerr << "Unable to open file " << fileName << endl;
            }
            else
            {
                while(myFile >> type)
                {
                    if (type == "P") // reads person from file and creates person object & adds to people vector
                    {
                        Person* person = new Person("", Date(0,0,0));
                        people.push_back(person);
                        person->Read(myFile);
                    } else if (type == "S") // reads student from file and creates person object & adds to people vector
                    {
                        Student* student = new Student("", Date(0,0,0));
                        people.push_back(student);
                        student->Read(myFile);
                    } else if (type == "R") // reads professor from file and creates person object & adds to people vector
                    {
                        Professor* professor  = new Professor("", Date(0,0,0), "");
                        people.push_back(professor);
                        professor->Read(myFile);
                    } else // if there is not a P R or S at the beginning of the line, throws error
                    {
                        cerr << "Something went wrong reading a " << type << " from file" << endl;
                    }
                }
            }
            myFile.close();

		}else if (userOption == 14){	// Write to File
            string fileName;

            std::ofstream myFile;

            cout << "Output filename: ";
            cin >> fileName;


            myFile.open(fileName);

            // checks if file is open, the writes contents of people vector to .txt file
            if(!myFile.is_open())
            {
                cerr << "Unable to open file " << fileName << endl;
            }
            else
            {
                for (Person *list : people)
                {
                    if (dynamic_cast<Student *>(list) != nullptr) // writes student to file
                    {
                        list->Write(myFile);
                        myFile << endl;
                    }
                    else if (dynamic_cast<Professor *>(list) != nullptr) // writes professor to file
                    {
                        dynamic_cast<Professor *>(list)->Write(myFile);
                        myFile << endl;
                    }
                    else // writes person to file
                    {
                        list->Write(myFile);
                        myFile << endl;
                    }
                }
            }

            myFile.close();
		}
	}

    for (Person* list : people)
    {
        delete list;
    }

	return 0;
}

size_t Menu(){
	int option = 0;
	while(true){
		cout << "-------------------------------------------" << endl;
		cout << "1. Add a Person" << endl;
		cout << "2. Add a Student" << endl;
		cout << "3. Add a Professor" << endl;
		cout << "4. List all People" << endl;
		cout << "5. Show Students Report" << endl;
		cout << "6. Show Professors Report" << endl;
		cout << "7. Show People (not Professors or Students)" << endl;
		cout << "8. Calculate all Students Average GPA" << endl;
		cout << "9. Calculate all Professors Average Salary" << endl;
		cout << "10. Input Grades to Student" << endl;
		cout << "11. Promote Professor" << endl;
		cout << "12. Give Raise to Professor" << endl;
		cout << "13. Load Data from File" << endl;
		cout << "14. Write Data to File" << endl;
		cout << "15. Exit" << endl;

		cin >> option;
		if (cin.fail()){
			cin.clear();
			cin.ignore(255, '\n');
			cerr << "Incorrect input!" << endl;
			continue;
		}
		if (option < 1 || option > 15){
			cerr << "Incorrect menu option!" << endl;
			continue;
		}
		break;
	}
	cout << endl;
	return static_cast<size_t>(option);
}
