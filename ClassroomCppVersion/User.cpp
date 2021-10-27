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
