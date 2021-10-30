#include "MainMenu.h"
#include "TeacherState.h"
#include"StudentState.h"
using namespace std;

StateInfo::MainMenu::MainMenu(ProgramDataRef data) : data(data)
{
	//data->currentUser = LoginInfo::loginSystem();

	HandleInput();
	
}


void StateInfo::MainMenu::Init()
{
	
}

void StateInfo::MainMenu::HandleInput()
{
	int choice;
	Display();
	cin >> choice;
	if (choice == 2)
	{
		
		CourseInfo::Course::createCourse(data->currentCourse, data->currentUser);
		// course is created 

		data->machine.addState(stateRef(new TeacherState(this->data)));
	}
	else
	{
		// check for course
		// pass to teacher / student state
		data->machine.addState(stateRef(new StudentState(this->data)));
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


