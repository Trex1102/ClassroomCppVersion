#include "seeassignmentState.h"
using namespace std;

StateInfo::seeassignmentState::seeassignmentState(ProgramDataRef data) : data(data)
{
}

void StateInfo::seeassignmentState::Init()
{
	HandleInput();
}

void StateInfo::seeassignmentState::HandleInput()
{
	Display();
	string choice;
	cout << "To go back #back\n";
	cin >> choice;
	if (choice == "#back") data->machine.removeState();
	else
	{
		Init();
	}
}

void StateInfo::seeassignmentState::Pause()
{

}

void StateInfo::seeassignmentState::Resume()
{
}

void StateInfo::seeassignmentState::Display()
{
	system("cls");
	for(auto it: Feature::Assignment::assignmentList)
	{
		if(it->getAssignedCourse() == data->currentCourse.getCourseCode())
		{
			it->Display();
		}
	}

}
