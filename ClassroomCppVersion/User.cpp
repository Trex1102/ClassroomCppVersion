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
