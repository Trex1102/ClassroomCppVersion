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
	for (int j = 0;j < data->currentCourse.assignmentList.size();j++)
	{
		data->currentCourse.assignmentList[j]->Display();
	}

}
