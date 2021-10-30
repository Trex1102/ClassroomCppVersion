#include "MainMenu.h"
using namespace std;

StateInfo::MainMenu::MainMenu(ProgramDataRef data) : data(data)
{
	data->currentUser = LoginInfo::loginSystem();
	cout << "User name: " << data->currentUser.getUsername() << endl;
}


void StateInfo::MainMenu::Init()
{
	
}

void StateInfo::MainMenu::HandleInput()
{
}

void StateInfo::MainMenu::Pause()
{
}

void StateInfo::MainMenu::Resume()
{
}

void StateInfo::MainMenu::Display()
{
}


