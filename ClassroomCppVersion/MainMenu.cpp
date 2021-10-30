#include "MainMenu.h"
using namespace std;

StateInfo::MainMenu::MainMenu(shared_ptr<UserInfo::User> currentUser): currentUser(currentUser)
{
	cout << "User Name: " << currentUser->getUsername()<<endl;
	Dummy dummy(currentUser);
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


