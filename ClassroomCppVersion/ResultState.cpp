#include "ResultState.h"
using namespace std;

StateInfo::ResultState::ResultState(ProgramDataRef data) : data(data)
{
	HandleInput();
}


void StateInfo::ResultState::Init()
{

}

void StateInfo::ResultState::HandleInput()
{
	Display();
}

void StateInfo::ResultState::Pause()
{

}

void StateInfo::ResultState::Resume()
{

}

void StateInfo::ResultState::Display()
{
	system("cls");
}
