#include "MainMenu.h"
#include "TeacherState.h"
#include"StudentState.h"
using namespace std;

StateInfo::MainMenu::MainMenu(ProgramDataRef data) : data(data)
{
	
}


void StateInfo::MainMenu::Init()
{
	HandleInput();
}

void StateInfo::MainMenu::HandleInput()
{
	string choice;
	Display();
	

	cin >> choice;
	if (choice == "#createcourse")
	{
		auto currentCourse = new CourseInfo::Course;
		CourseInfo::Course::createCourse(*currentCourse, data->currentUser);
		CourseInfo::Course::totalCourse++;
		CourseInfo::Course::courseList.push_back(currentCourse); // pushing course
		data->currentCourse = *currentCourse;
		currentCourse->enrollCourseTeacher(data->currentUser);
		data->machine.addState(stateRef(new TeacherState(this->data)), false);
	}
	else if (choice == "#exit")
	{
		UserInfo::User::write(); // User
		CourseInfo::Course::write(); // Course
		Feature::Assignment::write(); // Assignment
		Feature::Post::write(); // Post
		Database::Relations::write(); // Relations
		exit(1);
	}
	else
	{
		string code;
		CourseInfo::Course* course;
		cout << "Enter Course Code: "; cin >> code;
		course = UserInfo::User::joinCourse(code,data->currentUser);
		data->currentCourse = *course;

		if(course == nullptr)
		{
			cout << "Course not found" << endl;
			Init();
		}
		else
		{
			cout << "#jointolearn to join as student" << endl;
			cout << "#jointoteach to join as teacher" << endl;
			cout << "#exit" << endl;
			cin >> choice;
			if(choice=="#jointolearn")
			{
				if (course->enrollCourseStudent(data->currentUser))
				{
					data->machine.addState(stateRef(new StudentState(this->data)), false);
				}
				else
				{
					Init();
				}
			}
			
			else if(choice=="#jointoteach")
			{
				// check whether he is in the teacher list or not then add teacher state
				for(const auto it: Database::Relations::CourseTeacher[data->currentCourse.getCourseCode()])
				{
					if(it == data->currentUser.getUsername())
					{
						cout << "Go to teacher state\n";
						data->machine.addState(stateRef(new TeacherState(this->data)), false);
					}
					else
					{
						cout << "Sorry you are not in the teacher list. Tell your teacher friend to add you :)" << endl;
						Init();
					}
				}
			}
			else
			{
				CourseInfo::Course::write();
				UserInfo::User::write();
				Feature::Assignment::write();
				Feature::Post::write();
				Database::Relations::write();
				exit(1);
			}
		}
	}
}

void StateInfo::MainMenu::Pause()
{
	
}

void StateInfo::MainMenu::Resume()
{
}

void StateInfo::MainMenu::Display()
{
	system("cls");
	cout << "Welcome ";
	cout << "User: " << data->currentUser.getUsername() << endl;
	cout << "Total Courses: " << CourseInfo::Course::totalCourse<<endl;
	cout << "To join Course Press #joincourse \nTo create course type #createcourse \nTo exit #exit" << endl;
}


