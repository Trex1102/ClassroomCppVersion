#include "AddAssignmentState.h"

StateInfo::AddAssignmentState::AddAssignmentState(ProgramDataRef data):data(data)
{
	if (data == nullptr)
	{
		throw nullProgramRef();
	}
}

void StateInfo::AddAssignmentState::Init()
{
	HandleInput();
}

void StateInfo::AddAssignmentState::HandleInput()
{
	Display();
	string _data, choice;
	auto assignment = new Feature::Assignment;
	assignment->setAssignedCourse(data->currentCourse.getCourseCode());
	Feature::Assignment::totalAssignment++;
	Feature::Assignment::assignmentList.push_back(assignment);
	// add to database
	assignment->setAssignedUsers();

	cin.ignore();
	getline(cin, _data);
	assignment->setData(_data);
	cout << "Enter Deadline Date: ";
	cin >> choice;
	assignment->setDeadlineDate(choice);
	cout << "Enter Deadline Time: ";
	cin >> choice;
	assignment->setDeadlineTime(choice);

	cout << "Assignment Added Successfully" << endl;
	cout << "Add Another Assignment?? #retry or #back" << endl;
	cin >> choice;
	if (choice == "#back")
	{
		data->machine.removeState();
	}
	else Init();
}

void StateInfo::AddAssignmentState::Pause()
{
}

void StateInfo::AddAssignmentState::Resume()
{
}

void StateInfo::AddAssignmentState::Display()
{
	system("cls");
	cout << "Enter assignment text" << endl;
}
