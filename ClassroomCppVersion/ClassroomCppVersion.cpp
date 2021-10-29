// ClassroomCppVersion.cpp : This file contains the 'main' function. Program execution begins and ends there.


#include <iostream>
#include "User.h"
#include "Course.h"
#include "Attendance.h"
#include "LoginSystem.h"
using namespace std;


int main()
{
    UserInfo::User currentUser = LoginInfo::loginSystem();

}
