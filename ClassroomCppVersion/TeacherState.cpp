#include "TeacherState.h"


using namespace std;

StateInfo::TeacherState::TeacherState(ProgramDataRef data) : data(data)
{
	
}


void StateInfo::TeacherState::Init()
{
	HandleInput();
}

void StateInfo::TeacherState::HandleInput()
{
	Display();
	string choice;
	cin >> choice;
	if (choice == "#addstu")
	{
		data->machine.addState(stateRef(new AddStudentState(this->data)), false);
	}
	if (choice == "#addmat")
	{

		data->machine.addState(stateRef(new AddMaterialState(this->data)), false);
	}
	if (choice == "#addout")
	{
		string _data;
		cout << "Enter Outline" << endl;
		cin.ignore();
		getline(cin, _data);
		data->currentCourse.setCourseOutline(_data);
		Init();
	}
	if (choice == "#addassign")
	{

		data->machine.addState(stateRef(new AddAssignmentState(this->data)), false);
	}
	if (choice == "#addpost")
	{
		data->machine.addState(stateRef(new AddPostState(this->data)), false);
	}
	if (choice == "#courseinfo")
	{
		data->currentCourse.displayCourseInfo();
	}
	if (choice == "#back")
	{
		data->machine.removeState();
	}

	if (choice == "#exit")
	{
		UserInfo::User::write();
		CourseInfo::Course::write();
		Feature::Assignment::write();
		Feature::Post::write();
		Feature::Material::write();
		CourseInfo::attendance::write();
		Database::Relations::write();

		exit(0);
	}
	

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
	cout << "Commands: " << endl
		<< "To add student #addstu" << endl
		<< "To add Course Materials #addmat" << endl
		<< "To add Course Outline #addout" << endl
		<< "To add assignment #addassign" << endl
		<< "To add post #addpost" << endl
		<< "To see course information type #courseinfo" << endl
		<< "To go back type #back" << endl
		<< "To exit type #exit" << endl;
}
