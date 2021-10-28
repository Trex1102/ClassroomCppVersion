#pragma once
#include <iostream>
#include "User.h"
using namespace std;

int UserInfo::User::userID;
vector<UserInfo::User*> UserInfo::User::userList;

void UserInfo::User::addAsStudent(CourseInfo::Course& course)
{
	this->asStudent.push_back(&course);
}

void UserInfo::User::addAsTeacher(CourseInfo::Course& course)
{
	this->asTeacher.push_back(&course);
}

void UserInfo::User::createUser(User &user)
{
	cout << "First Name: ";  cin >> user.firstName;
	cout << "Middle Name: ";  cin >> user.middleName;
	cout << "Last Name: ";  cin >> user.lastName;
	cout << "Department: "; cin >> user.department;
	cout << "Age: "; cin >> user.age;
	cout << "Email: "; cin >> user.email;
	cout << "Phone: "; cin >> user.phone;
	
	user.createUserName();

	cout << "Your Username is " << user.username << endl;
	cout << "Enter a password: "; cin >> user.password;

	cout << "Your account has been created successfully" << endl;
}

void UserInfo::User::createUserName()
{
	username = firstName + to_string(userID);
}

void UserInfo::User::addCourseMaterials()
{
}

void UserInfo::User::joinCourse(string courseCode, User& user)
{
	for(const auto it: CourseInfo::Course::courseList)
	{
		string choice;
		if(it->getCourseCode() == courseCode)
		{
			cout << "Course Found" << endl;
			cout << "To join as teacher type #jointoteach" << endl << "To join as student type #jointolearn" << endl;
			cin >> choice;
			if(choice == "#jointoteach")
			{
				// search whether user is in the teacher list if not ask for password
			}
			else if(choice == "#jointolearn")
			{
				// include the user as student to the course -- no need to check as the coursecode is unique

				cout << "Congo" << endl;
				// show student dashboard 
			}
		}
	}
}

void UserInfo::User::displayInfo() const
{
	cout << "Name: " << firstName << ' ' << middleName << ' ' << lastName << endl;
	// other details

}

void UserInfo::User::addStudent(CourseInfo::Course &course,User& student)
{
	// check whether user is teacher of that course
	// add student to that course
}

void UserInfo::User::takeAttendance(CourseInfo::Course &course)
{
	CourseInfo::attendance attendance(&course);
	attendance.takeAttendance();
	course.attendanceList.insert({ static_cast<string>(__DATE__) , &attendance });
}


