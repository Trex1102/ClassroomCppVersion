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

		data->machine.addState(stateRef(new seepostState(this->data)), false);
	}

	if (choice == "#seeassignment")
	{
		data->machine.addState(stateRef(new seeassignmentState(this->data)), false);
	}
	if (choice == "seemat")
	{
		data->machine.addState(stateRef(new seematState(this->data)), false);
	}

	if(choice =="seeoutline")
	{
		// retrieve from file
		cout << data->currentCourse.getCourseOutline() << endl;
	}
	if (choice == "#exit")
	{
		UserInfo::User::write();
		CourseInfo::Course::write();
		Feature::Assignment::write();
		Feature::Post::write();

		Feature::Material::write();
		CourseInfo::attendance::write();

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
