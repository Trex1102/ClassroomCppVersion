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
		CourseInfo::Course::totalCourse++;
		data->currentCourse = *currentCourse;
		currentCourse->enrollCourseTeacher(data->currentUser);
		
		data->machine.addState(stateRef(new TeacherState(this->data)), false);
	
		
	}
	else if (choice == "#exit")
	{
		UserInfo::User::write();
		CourseInfo::Course::write();
		Feature::Assignment::write();
		Feature::Post::write();
		exit(1);
	}
	else
	{
		string code;
		CourseInfo::Course* course;
		int cur_course = CourseInfo::Course::readCount();
		
		//cout << "Current Courses: " << cur_course << endl;
	//	CourseInfo::Course::display();
		cout << "Enter Course Code: "; cin >> code;

		course = UserInfo::User::joinCourse(code,data->currentUser);
		//cout << course->StudentList[0] << endl;
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
				course->enrollCourseStudent(data->currentUser);
				data->currentCourse = *course;
				data->machine.addState(stateRef(new StudentState(this->data)) ,false);
			}
			
			else if(choice=="#jointoteach")
			{
				for(const auto it:course->getTeacherList())
				{
					if(it->getUsername() == data->currentUser.getUsername())
					{
						data->currentCourse = *course;
						data->machine.addState(stateRef(new TeacherState(this->data)), false);
					}
				}

				cout << "Sorry you are not in the teacher list. Tell your teacher friend to add you :)" << endl;
				Init();
			}
			else
			{
				CourseInfo::Course::write();
				UserInfo::User::write();
				Feature::Assignment::write();
				Feature::Post::write();
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
	cout << "To join Course Press #joincourse or to create course type #createcourse to go back #back to exit #exit" << endl;
}


