#include "seematState.h"
using namespace std;

StateInfo::seematState::seematState(ProgramDataRef data) : data(data)
{
}

void StateInfo::seematState::Init()
{
	HandleInput();
}

void StateInfo::seematState::HandleInput()
{
	Display();

}

void StateInfo::seematState::Pause()
{

}

void StateInfo::seematState::Resume()
{
}

void StateInfo::seematState::Display()
{
	system("cls");
	for (int j = 0;j < data->currentCourse.courseMaterialList.size();j++)
	{
		data->currentCourse.courseMaterialList[j]->Display();
	}

}
