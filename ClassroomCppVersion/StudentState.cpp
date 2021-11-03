#include "StudentState.h"
using namespace std;

StateInfo::StudentState::StudentState(ProgramDataRef data) : data(data)
{
	
}


void StateInfo::StudentState::Init()
{
	HandleInput();
}

void StateInfo::StudentState::HandleInput()
{
	Display();
	string choice;
	cin >> choice;

	if(choice == "#seepost")
	{
		
	}

	if(choice == "#seeassignment")
	{
		
	}
	if(choice =="seemat")
	{
		
	}

	if(choice =="seeoutline")
	{
		cout << data->currentCourse.getCourseOutline() << endl;
	}
	if (choice == "#exit")
	{
		UserInfo::User::write();
		CourseInfo::Course::write();
		Feature::Assignment::write();
		Feature::Post::write();
		exit(0);
	}

}

void StateInfo::StudentState::Pause()
{

}

void StateInfo::StudentState::Resume()
{

}

void StateInfo::StudentState::Display()
{
	system("cls");
	cout << "Username: " << data->currentUser.getUsername() << endl;
	cout << "Class code: " << data->currentCourse.getCourseCode() << endl;
	cout << "Commands: " << endl;
	cout << "#seepost - To see class posts" << endl;
	cout << "#seeassignment - To see class assignment" << endl;
	cout << "#seemat - To see course materials" << endl;
	cout << "#seeoutline - To see course outline" << endl;
	cout << "#exit" << endl;
}
