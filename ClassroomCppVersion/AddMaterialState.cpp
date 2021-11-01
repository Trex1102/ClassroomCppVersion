/*#include "AddMaterialState.h"

StateInfo::AddMaterialState::AddMaterialState(ProgramDataRef data)
	:data(move(data)),coursematerials(move(nullptr))
{
}

void StateInfo::AddMaterialState::Init()
{

	HandleInput();
}

void StateInfo::AddMaterialState::HandleInput()
{
	Display();
	string choice;
	cout << "Course Material Added Successful" << endl;
	cout << "To add more press #more to go back #back" << endl;
	cin >> choice;
	if(choice =="#more")
	{
		Init();
	}
	else
	{
		data->machine.removeState();
	}
}

void StateInfo::AddMaterialState::Pause()
{
}

void StateInfo::AddMaterialState::Resume()
{
}

void StateInfo::AddMaterialState::Display()
{
	string choice1, choice2;
	system("cls");
	cout << "Material Concept: "; cin >> choice1; 
	cout << "Material text or link"; cin >> choice2;
	coursematerials->materials.insert(pair<string, string>(choice1, choice2));
}*/
