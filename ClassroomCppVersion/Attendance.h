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
	public:
		attendance()//cons
		{
			date = __DATE__;
		}
		attendance(Course* _course): course(_course)
		{
			date = __DATE__;
		}
		// accessing other classes functions
		static int totalAttendance;
		static vector<attendance*>AttendanceList;
		void takeAttendance();

		static void read();
		static void write();
		static void writeCount(int );
		static int readCount();
		
	};
}