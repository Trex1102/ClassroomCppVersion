#include "AttendanceState.h"
using namespace std;

StateInfo::AttendanceState::AttendanceState(ProgramDataRef data) : data(data)
{
	HandleInput();
}


void StateInfo::AttendanceState::Init()
{

}

void StateInfo::AttendanceState::HandleInput()
{
	Display();
}

void StateInfo::AttendanceState::Pause()
{

}

void StateInfo::AttendanceState::Resume()
{

}

void StateInfo::AttendanceState::Display()
{
	system("cls");
}
