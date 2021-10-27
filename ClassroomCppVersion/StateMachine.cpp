#include <iostream>
#include "StateMachine.h"
#include "LoginSystem.h"
using namespace std;

void StateInfo::dashboardState(UserInfo::User& currentUser)
{
	int choice;
	vector<CourseInfo::Course* > asStudent = currentUser.getAsStudent();
	vector<CourseInfo::Course* > asTeacher = currentUser.getAsTeacher();
	system("cls");
	cout << "User name: " << currentUser.getUsername()<<endl;
	cout << "Joined Classes: " << endl;
	cout << "As teacher: " << asTeacher.size() << endl;
	cout << "As student: " << asStudent.size() << endl;

}
