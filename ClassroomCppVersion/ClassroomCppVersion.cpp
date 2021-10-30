// ClassroomCppVersion.cpp : This file contains the 'main' function. Program execution begins and ends there.


#include <iostream>
#include "User.h"
#include "Course.h"
#include "Attendance.h"
#include "LoginSystem.h"
#include "Program.h"
#include "MainMenu.h"
using namespace std;

int main()
{
	UserInfo::User currentUser = LoginInfo::loginSystem();
	shared_ptr<UserInfo::User> sharedCurrentUser = make_shared<UserInfo::User>(currentUser);
	StateInfo::MainMenu menu(sharedCurrentUser);

}
