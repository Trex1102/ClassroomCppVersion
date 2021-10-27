#pragma once
#include <iostream>
#include "User.h"
#include "LoginSystem.h"
#include "StateMachine.h"
using namespace std;
namespace StateInfo
{
	class TeacherState: public courseState
	{
	private:
	public:
		TeacherState(CourseInfo::Course* current_course, UserInfo::User* current_user)
			: courseState(current_course, current_user)
		{
		}

		void displayCourseState() override;
	};
}