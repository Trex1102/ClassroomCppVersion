#include <iostream>
#include "StateMachine.h"
#include "LoginSystem.h"
#include "Course.h"
#include "TeacherState.h"
using namespace std;

void StateInfo::dashboardState(UserInfo::User& currentUser)
{
	string choice;
	vector<CourseInfo::Course* > asStudent = currentUser.getAsStudent();
	vector<CourseInfo::Course* > asTeacher = currentUser.getAsTeacher();
	system("cls");
	cout << "User name: " << currentUser.getUsername()<<endl;
	cout << "Joined Courses: " << endl;
	cout << "As teacher: " << asTeacher.size() << endl;
	cout << "As student: " << asStudent.size() << endl;
	cout << "To join courses type #joincourse" << endl;
	cout << "To create course type #createcourse" << endl;
	cin >> choice;
	if(choice == "#joincourse")
	{
		
	}
	if(choice == "#createcourse")
	{
		CourseInfo::Course course;
		CourseInfo::Course::createCourse(course , currentUser);
		StateInfo::TeacherState course_state(&course, &currentUser);
		course_state.displayCourseState();
	}

}

void StateInfo::courseState::displayParticipants()
{
	string choice;
	cout << "Teachers: " << endl;
	for (const auto it : currentCourse->getTeacherList())
	{
		cout << it->getFirstName() << ' ' << it->getMiddleName() << ' ' << it->getLastName() << endl;
	}
	cout << "Students: " << endl;
	for (const auto it : currentCourse->getStudentList())
	{
		cout << it->getFirstName() << ' ' << it->getMiddleName() << ' ' << it->getLastName() << endl;
	}

	cout << "To go back type #back" << endl;
	cin >> choice;
	if(choice == "#back")
	{
		this->displayCourseState();
	}
	else
	{
		//
	}
}

void StateInfo::courseState::displayCourseState()
{
	
	system("cls");
	cout << "Course Code: " << currentCourse->getCourseCode()<<endl;
	cout << "Course ID: " << currentCourse->getdepartment() << currentCourse->getCourseID()<<endl;
	
}
