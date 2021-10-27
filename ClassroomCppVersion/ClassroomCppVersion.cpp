// ClassroomCppVersion.cpp : This file contains the 'main' function. Program execution begins and ends there.


#include <iostream>
#include "User.h"
#include "Course.h"
#include "Attendance.h"
#include "LoginSystem.h"
#include "StateMachine.h"
using namespace std;


int main()
{
    UserInfo::User currentUser = LoginInfo::loginSystem();
    StateInfo::dashboardState(currentUser);
}