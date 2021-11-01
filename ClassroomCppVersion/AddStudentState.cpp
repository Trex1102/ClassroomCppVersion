#include "AddStudentState.h"
using namespace std;

StateInfo::AddStudentState::AddStudentState(ProgramDataRef data): data(data)
{
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

	int count = 1;
	for(const auto it: UserInfo::User::userList)
	{
		if (count == 1) continue;
		else
		{
			if (it->getUsername() == username)
			{
				user = it;
			}
		}
		count++;
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
		data->currentCourse.getStudentList().push_back(user);
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
	cout << "Total users: " << UserInfo::User::TotalUser << endl;
	cout << "Input the user name of the student you like to add: ";

}
