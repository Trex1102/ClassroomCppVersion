
#include "Teacher.h"
using namespace  std;

int UserInfo::Teacher::teacherID;

void UserInfo::Teacher::takeAttendance() const
{
	{
		CourseInfo::attendance attendance(enrolledCourse);
		attendance.takeAttendance();
		enrolledCourse->attendanceList.insert({static_cast<string>(__DATE__) , &attendance });
	}
}

void UserInfo::Teacher::displayTeacherInfo() const
{
	cout << "Teacher Info: " << endl;
	cout << "Teacher Name: " << parentUser->getFirstName() << endl;
	cout << "Teacher Email: " << parentUser->getEmail()<<endl;
	cout << "Other Courses" << endl;
}

void UserInfo::Teacher::addStudent(Student& student) const
{
	this->enrolledCourse->enrollCourseStudent(student);
}

void UserInfo::Teacher::addCourseMaterials()
{
}

void UserInfo::Teacher::linkTeacherToUser() const
{
	parentUser->addAsTeacher(*this->enrolledCourse);
}
