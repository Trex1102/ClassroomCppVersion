#include "Course.h"
using namespace std;


vector<CourseInfo::Course*>CourseInfo::Course::courseList;

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
		
		// only shows teacher part
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
	auto const t = static_cast<long int> (time(nullptr));
	srand(t);
	for (int i = 0; i < 6; i++)
	{
		int x = (rand() % 89) + 33;
		courseCode = char(x) + courseCode;
	}
}




string CourseInfo::Course::getCourseCode() const
{
    return courseCode;
}

void CourseInfo::Course::setCourseCode(string courseCode)
{
    this->courseCode = courseCode;
}

string CourseInfo::Course::getDepartment() const
{
    return department;
}

void CourseInfo::Course::setDepartment(string department)
{
    this->department = department;
}

string CourseInfo::Course::getCourseID() const
{
    return courseID;
}

void CourseInfo::Course::setCourseID(string courseID)
{
    this->courseID = courseID;
}

string CourseInfo::Course::getCourseOutline() const
{
    return courseOutline;
}

void CourseInfo::Course::setCourseOutline(string courseOutline)
{
    this->courseOutline = courseOutline;
}

double CourseInfo::Course::getCourseCredit() const
{
    return courseCredit;
}

void CourseInfo::Course::setCourseCredit(double courseCredit)
{
    this->courseCredit = courseCredit;
}


vector<CourseInfo::CourseMaterials*> CourseInfo::Course::getCourseMaterialList() const
{
    return courseMaterialList;
}

void CourseInfo::Course::setCourseMaterialList(vector<CourseMaterials*> courseMaterialList)
{
    this->courseMaterialList = courseMaterialList;
}

vector<UserInfo::User*> CourseInfo::Course::getStudentList() const
{
    return studentList;
}

void CourseInfo::Course::setStudentList(vector<UserInfo::User*> studentList)
{
    this->studentList = studentList;
}

vector<UserInfo::User*> CourseInfo::Course::getTeacherList() const
{
    return teacherList;
}

void CourseInfo::Course::setTeacherList(vector<UserInfo::User*> teacherList)
{
    this->teacherList = teacherList;
}

