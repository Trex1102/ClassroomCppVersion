#include "MainMenu.h"
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
	string choice;
	Display();
	cin >> choice;
	if (choice == "#createcourse")
	{
		
		CourseInfo::Course::createCourse(data->currentCourse, data->currentUser);
		// course is created 
	}
	else
	{
		// check for course
		// pass to teacher / student state
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


