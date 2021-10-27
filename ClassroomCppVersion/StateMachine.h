#pragma once
#include <iostream>
#include "User.h"
#include "LoginSystem.h"
using namespace std;
namespace StateInfo
{
	void dashboardState(UserInfo::User &currentUser);
	//void messageState(UserInfo::User& currentUser);
	//void adminState(UserInfo::User& currentUser);

	

	class courseState
	{
	private:
		CourseInfo::Course* currentCourse;
		UserInfo::User* currentUser;
	public:

		courseState(CourseInfo::Course* current_course, UserInfo::User* current_user)
			: currentCourse(current_course),
			  currentUser(current_user)
		{
		}

		void displayParticipants();
		virtual void displayCourseState();
		virtual ~courseState() = default;
	};

}