#include "AddPostState.h"
using namespace std;
StateInfo::AddPostState::AddPostState(ProgramDataRef data): data(data)
{
	if (data == nullptr)
	{
		throw nullProgramRef();
	}
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
	post->createPostID();
	Feature::Post::postList.push_back(post);
	Database::Relations::CoursePost[data->currentCourse.getCourseCode()].push_back(post->getID());
	post->enrolledCourseCode = data->currentCourse.getCourseCode();
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
