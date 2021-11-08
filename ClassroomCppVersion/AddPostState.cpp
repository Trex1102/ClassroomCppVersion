#include "AddPostState.h"
using namespace std;
StateInfo::AddPostState::AddPostState(ProgramDataRef data): data(data)
{
}

void StateInfo::AddPostState::Init()
{
	HandleInput();
}

void StateInfo::AddPostState::HandleInput()
{
	Display();
	string _data, choice;
	auto post = new Feature::Post();
	Feature::Post::totalPosts++;
	Feature::Post::postList.push_back(post);
	//data->currentCourse.postList.push_back(post);
	cin.ignore();
	getline(cin, _data);
	post->setData(_data);
	post->Display();
	cout << "Post Added Successfully" << endl;
	cout << "Add Another Post?? #retry or #back" << endl;
	cin >> choice;

	if (choice == "#back")
	{
		data->machine.removeState();
	}
	else Init();
}

void StateInfo::AddPostState::Pause()
{
}

void StateInfo::AddPostState::Resume()
{
}

void StateInfo::AddPostState::Display()
{
	system("cls");
	cout << "Enter text" << endl;
	
}
