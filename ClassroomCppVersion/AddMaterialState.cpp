#include "AddMaterialState.h"
using namespace std;

StateInfo::AddMaterialState::AddMaterialState(ProgramDataRef data):data(data)
{
}

void StateInfo::AddMaterialState::Init()
{
	HandleInput();
}

void StateInfo::AddMaterialState::HandleInput()
{
	Display();
	string _data, choice;
	auto material = new Feature::Material();
	Feature::Material::totalMaterials++;
	material->setLinkedCourse(data->currentCourse.getCourseCode());
	material->setUploaderTeacher(data->currentUser.getUsername());
	cin.ignore();
	cout << "Enter Material Topic: " << endl;
	getline(cin, _data);
	cout << "Enter Link: ";
	cin >> choice;
	//material->materials.insert({ _data, choice });
	//material->Display();
	cout << "Course Material Added Successfully" << endl;
	cout << "Add Another Course Material?? #retry or #back" << endl;
	cin >> choice;
	if (choice == "#back")
	{
		data->machine.removeState();
	}
	else Init();
}

void StateInfo::AddMaterialState::Pause()
{
}

void StateInfo::AddMaterialState::Resume()
{
}

void StateInfo::AddMaterialState::Display()
{
	system("cls");
}
