#include "Course.h"
using namespace std;

//int CourseInfo::Course::courseCode = 100;
vector<CourseInfo::Course*>courseList;

void CourseInfo::Course::enrollCourseTeacher(UserInfo::User& teacher)
{
	teacherList.push_back(&teacher);
}

void CourseInfo::Course::enrollCourseStudent(UserInfo::User& student)
{
	studentList.push_back(&student);
}

void CourseInfo::Course::displayCourseInfo()
{
	cout << "Course Information: " << endl;
	cout << "Course ID: " << courseID << endl;
	cout << "department Name: " << department << endl;
	cout << "Course Teacher: " << endl;
	// show teachers
	for(const auto it: teacherList)
	{
		
		//it->displayTeacherInfo(); // only shows teacher part
		// display user info as well
		
	}
	// show students
	for(const auto it:studentList)
	{
		//it->displayStudentInfo();
		// display user info as well
	}
}

void CourseInfo::Course::addCourseMaterial(CourseMaterials& course_material)
{
	courseMaterialList.push_back(&course_material);
}

void CourseInfo::Course::showCourseMaterials()
{
	for(auto it:courseMaterialList)
	{
		//
	}
}

void CourseInfo::Course::createCourse(CourseInfo::Course &course , UserInfo::User &teacher)
{
	cout << "Department: "; cin >> course.department;
	cout << "Course ID: "; cin >> course.courseID;
	cout << "Course Credit: "; cin >> course.courseCredit;

	// for course outline use text link or input

	cout << "Your Course Code is " << course.courseCode << endl;
	course.teacherList.push_back(&teacher);
	cout << "Course Created Successful" << endl;
}

void CourseInfo::Course::createCourseCode()
{
	srand(time(0));
	for (int i = 0; i < 6; i++)
	{
		int x = (rand() % 89) + 33;
		courseCode = char(x) + courseCode;
	}
}



