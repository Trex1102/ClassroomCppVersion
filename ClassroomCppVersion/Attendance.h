#pragma once
#include <string>
#include <iostream>
#include <map>
#include <vector>
#include "Course.h"
#include "User.h"
using namespace std;

namespace CourseInfo
{
	class Course;

	class attendance
	{
	private:
		string date;
		map<string, string> dailyAttendance;
		Course* course;
		friend UserInfo::User;
	public:
		attendance(Course* _course): course(_course)
		{
			date = __DATE__;
		}
		// accessing other classes functions

		void takeAttendance();
		
	};
}