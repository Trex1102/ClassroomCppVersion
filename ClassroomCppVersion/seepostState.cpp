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
	for (int j = 0;j <data->currentCourse.postList.size();j++)
	{
		data->currentCourse.postList[j]->Display();
    }

}
