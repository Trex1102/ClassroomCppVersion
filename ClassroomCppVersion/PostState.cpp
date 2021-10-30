#include "PostState.h"
using namespace std;

StateInfo::PostState::PostState(ProgramDataRef data) : data(data)
{
	HandleInput();
}


void StateInfo::PostState::Init()
{

}

void StateInfo::PostState::HandleInput()
{
	Display();
}

void StateInfo::PostState::Pause()
{

}

void StateInfo::PostState::Resume()
{

}

void StateInfo::PostState::Display()
{
	system("cls");
}
