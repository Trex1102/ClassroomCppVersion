#pragma once
#include <iostream>
#include "User.h"
#include "LoginSystem.h"
using namespace std;
namespace StateInfo
{
	
	//void messageState(UserInfo::User& currentUser);
	//void adminState(UserInfo::User& currentUser);

	void dashboardState(UserInfo::User& currentUser);

	class courseState
	{
	protected:
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


	public:
        CourseInfo::Course* getCurrentCourse() const;
        void setCurrentCourse(CourseInfo::Course* currentCourse);

        UserInfo::User* getCurrentUser() const;
        void setCurrentUser(UserInfo::User* currentUser);
		
};

}