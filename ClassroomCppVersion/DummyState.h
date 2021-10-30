#pragma once
#include <string>
#include <iostream>
#include <map>
#include <vector>
#include "CourseMaterials.h"
#include "Attendance.h"
#include "State.h"
#include "Program.h"
using namespace std;

class Dummy
{
private:
	shared_ptr<UserInfo::User>currentUser = make_shared<UserInfo::User>();
public:
	Dummy(shared_ptr<UserInfo::User> currentUser):currentUser(currentUser)
	{
		cout << "User name: " << currentUser->getUsername() << endl;
	}
};