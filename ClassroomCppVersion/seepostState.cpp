#include "seepostState.h"
using namespace std;

StateInfo::seepostState::seepostState(ProgramDataRef data) : data(data)
{
}

void StateInfo::seepostState::Init()
{
	HandleInput();
}

void StateInfo::seepostState::HandleInput()
{
	Display();
	string choice;
	cout << "To go back #back\n";
	cin >> choice;
	if(choice == "#back")
	{
		data->machine.removeState();
	}
}

void StateInfo::seepostState::Pause()
{

}

void StateInfo::seepostState::Resume()
{
}

void StateInfo::seepostState::Display()
{
	system("cls");

	for(auto it: Feature::Post::postList)
	{
		if(it->enrolledCourseCode == data->currentCourse.getCourseCode())
		{
			it->Display();
		}
	}

}
