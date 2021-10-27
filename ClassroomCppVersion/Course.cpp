#include "Course.h"
using namespace std;

void CourseInfo::Course::enrollCourseTeacher(UserInfo::Teacher& teacher)
{
	teacherList.push_back(&teacher);
}

void CourseInfo::Course::enrollCourseStudent(UserInfo::Student& student)
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
		
		it->displayTeacherInfo(); // only shows teacher part
		// display user info as well
		
	}
	// show students
	for(const auto it:studentList)
	{
		it->displayStudentInfo();
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


