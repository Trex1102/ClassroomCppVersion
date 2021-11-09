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

	for(auto it: Feature::Material::materialList)
	{
		if(it->getLinkedCourse() == data->currentCourse.getCourseCode())
		{
			it->Display();
		}
	}

}
