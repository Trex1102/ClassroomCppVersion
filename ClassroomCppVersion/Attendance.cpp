
#include "Attendance.h"

using namespace  std;

void CourseInfo::attendance::takeAttendance()
{
	{
		int i;
		for (auto it : course->getStudentList())
		{
			cout << "If Present input 1 otherwise input 0 " << endl;
			cout << "Student ID: " << it->getStudentID() << endl;
			cin >> i;
			if (i == 0)
			{
				dailyAttendance.insert(pair<string, string>(it->getStudentID(), "Absent"));
			}
			else
			{
				dailyAttendance.insert(pair<string, string>(it->getStudentID(), "Present"));
			}
		}
	}
}
