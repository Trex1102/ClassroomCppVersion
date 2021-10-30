#include "TeacherState.h"
using namespace std;

StateInfo::TeacherState::TeacherState(ProgramDataRef data) : data(data)
{
	HandleInput();
}


void StateInfo::TeacherState::Init()
{

}

void StateInfo::TeacherState::HandleInput()
{
	Display();
}

void StateInfo::TeacherState::Pause()
{

}

void StateInfo::TeacherState::Resume()
{

}

void StateInfo::TeacherState::Display()
{
	system("cls");
	cout << "Welcome to Course: " << data->currentCourse.getCourseCode()<<endl;
	cout <<"Teacher: "<< data->currentUser.getUsername() << endl;
}
