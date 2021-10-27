
#include "Student.h"
using namespace std;

void UserInfo::Student::displayStudentInfo() const
{
	{
		cout << "Student Info: " << endl;
		cout << "Student Name: " << parentUser->getName() << endl;
		cout << "Student ID: " << studentID<<endl;
	}
}

void UserInfo::Student::linkStudentToUser() const
{
	parentUser->addAsStudent(*this->enrolledCourse);
}
