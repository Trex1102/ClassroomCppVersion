#include "AddStudentState.h"
using namespace std;

StateInfo::AddStudentState::AddStudentState(ProgramDataRef data): data(data)
{
	if (data == nullptr)
	{
		throw nullProgramRef();
	}
}

void StateInfo::AddStudentState::Init()
{
	HandleInput();
}

void StateInfo::AddStudentState::HandleInput()
{
	Display();
	string username, choice;
	cin >> username;
	UserInfo::User* user = nullptr;
	
	for(const auto it: UserInfo::User::userList)
	{
		if (it->getUsername() == username)
		{
			user = it;
		}
	}
	
	if(user== nullptr)
	
	{
		cout << "No user exists with this username" << endl;
		cout << "To back to previous state #back" << endl;
		cin >> choice;
		if(choice == "#back")data->machine.removeState();
	}
	else
	{
		//data->currentCourse.getStudentList().push_back(user);
		/*Database Part*/
		Database::Relations::CourseStudent[data->currentCourse.getCourseCode()].push_back(user->getUsername());
		Database::Relations::StudentCourse[user->getUsername()].push_back(data->currentCourse.getCourseCode());
		//
		cout << "User added successfully" << endl;
		cout << "To back to previous state #back" << endl;
		cin >> choice;
		if (choice == "#back")data->machine.removeState();
	}
}

void StateInfo::AddStudentState::Pause()
{
}

void StateInfo::AddStudentState::Resume()
{
}

void StateInfo::AddStudentState::Display()
{
	system("cls");
	cout << "Total users: " << UserInfo::User::userID << endl;
	cout << "Input the user name of the student you like to add: ";

}
