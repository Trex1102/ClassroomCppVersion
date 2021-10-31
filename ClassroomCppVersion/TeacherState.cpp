#include "TeacherState.h"
using namespace std;

StateInfo::TeacherState::TeacherState(ProgramDataRef data) : data(data)
{
	HandleInput();
}


void StateInfo::TeacherState::Init()
{

}

void StateInfo::TeacherState::HandleInput()
{
	Display();
	string choice;
	cin >> choice;
	if (choice == "#addstu")
	{

	}
	if (choice == "#addmat")
	{

	}
	if (choice == "#addout")
	{

	}
	if (choice == "#addassign")
	{

	}
	if (choice == "#addnotes")
	{

	}
	if (choice == "#coursepar")
	{
		//displayParticipants();
	}
	if (choice == "#back")
	{
		data->machine.removeState();
		//dashboardState(currentUser*);
	}

}

void StateInfo::TeacherState::Pause()
{

}

void StateInfo::TeacherState::Resume()
{

}

void StateInfo::TeacherState::Display()
{
	system("cls");
	cout << "Welcome to Course: " << data->currentCourse.getCourseCode()<<endl;
	cout <<"Teacher: "<< data->currentUser.getUsername() << endl;
	cout << "Commands: " << endl
		<< "To add student #addstu" << endl
		<< "To add Course Materials #addmat" << endl
		<< "To add Course Outline #addout" << endl
		<< "To add assignment #addassign" << endl
		<< "To add Short Notes #addsnotes" << endl
		<< "To see course participants type #coursepar" << endl
		<< "To go back type #back" << endl;

}
