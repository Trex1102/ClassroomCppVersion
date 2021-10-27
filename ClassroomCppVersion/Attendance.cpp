
#include "Attendance.h"
using namespace  std;

void CourseInfo::attendance::takeAttendance()
{
	{
		int choice;
		for (const auto it : course->getStudentList())
		{
			cout << "If Present input 1 otherwise input 0 " << endl;
			cout << "Student username: " << it->getUsername() << endl;
			cin >> choice;
			if (choice == 0)
			{
				dailyAttendance.insert(pair<string, string>(it->getUsername(), "Absent"));
			}
			else
			{
				dailyAttendance.insert(pair<string, string>(it->getUsername(), "Present"));
			}
		}
	}
}
