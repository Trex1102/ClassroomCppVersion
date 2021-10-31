#include "AssignmentState.h"
using namespace std;

StateInfo::AssignmentState::AssignmentState(ProgramDataRef data) : data(data)
{
	HandleInput();
}


void StateInfo::AssignmentState::Init()
{

}

void StateInfo::AssignmentState::HandleInput()
{
	Display();
}

void StateInfo::AssignmentState::Pause()
{

}

void StateInfo::AssignmentState::Resume()
{

}

void StateInfo::AssignmentState::Display()
{
	system("cls");
}
