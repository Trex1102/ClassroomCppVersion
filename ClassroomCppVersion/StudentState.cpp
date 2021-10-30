#include "StudentState.h"
using namespace std;

StateInfo::StudentState::StudentState(ProgramDataRef data) : data(data)
{
	HandleInput();
}


void StateInfo::StudentState::Init()
{

}

void StateInfo::StudentState::HandleInput()
{
	Display();
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
}
