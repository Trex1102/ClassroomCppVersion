#include "MainMenu.h"
#include "TeacherState.h"
#include"StudentState.h"
using namespace std;

StateInfo::MainMenu::MainMenu(ProgramDataRef data) : data(data)
{
	//data->currentUser = LoginInfo::loginSystem();
	//Init();
}


void StateInfo::MainMenu::Init()
{
	HandleInput();
}

void StateInfo::MainMenu::HandleInput()
{
	string choice;
	Display();
	cin >> choice;
	if (choice == "#createcourse")
	{
		
		CourseInfo::Course::createCourse(data->currentCourse, data->currentUser);
		data->machine.addState(stateRef(new TeacherState(this->data)), false);
	}
	else
	{
		string code, choice;
		cout << "Enter Course Code: "; cin >> code;
		choice = UserInfo::User::joinCourse(code,data->currentUser);
		if(choice == "#jointoteach")
		{
			// check whether user is in the course as teacher
			// create & passs teacher state
		}
		else
		{
			// join as teacher as codes are unique
			// create & pass student state
		}
	}
}

void StateInfo::MainMenu::Pause()
{
	
}

void StateInfo::MainMenu::Resume()
{
}

void StateInfo::MainMenu::Display()
{
	system("cls");
	cout << "Welcome ";
	cout << "User: " << data->currentUser.getUsername() << endl;
	cout << "To join Course Press #joincourse or to create course type #createcourse" << endl;
}


