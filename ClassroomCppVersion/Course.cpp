﻿#include "Course.h"
using namespace std;

int CourseInfo::Course::totalCourse;
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
	cout << "Course Code: " << courseCode << endl;
	// show teachers
	/*for (const auto it : teacherList)
	{
		
		// only shows teacher part
		// display user info as well
		
	}
	// show students
	for(const auto it:studentList)
	{
		//it->displayStudentInfo();
		// display user info as well
	}*/
}
void CourseInfo::Course::showCourseMaterials()
{

}
void CourseInfo::Course::display()
{
	for (auto it : CourseInfo::Course::courseList)
	{
		cout << "CourseCode: " << it->getCourseCode() << endl;
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
	//totalCourse++;
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
void CourseInfo::Course::write()
{

	//int n = userList.size();

	ofstream ouf;
	//User user;
	int size = sizeof(Course);
	ouf.open("Course.DAT", ios::trunc | ios::binary);
	if (!ouf)
	{
		cout << "\nCan't open file\n";
		return;
	}
	for (unsigned j = 0; j < courseList.size(); j++)
	{
		//ouf.write((char*)&User, sizeof(User));
		if (!ouf)
		{
			cout << "\nCan't write to file\n";
			return;
		}
		ouf.write((char*)(courseList[j]), size);
	}

	cout << "Writing " << courseList.size() << " Courses.\n";
	writeCount(courseList.size());
}
void CourseInfo::Course::read()
{
	int cur = readCount();
	totalCourse = cur;
	//User user;
	int size = sizeof(Course);
	ifstream inf;
	inf.open("Course.DAT", ios::binary);
	if (!inf.is_open())
	{
		//cout << "\nCan't open file\n"; return;
		return;
	}
	int TotalCourse = 0; // solution 1 : debug 2: store & retrieve
	for (int j = 0;j < cur;j++)
	{
		//cout << TotalCourse << endl;
		courseList.push_back(nullptr);
		courseList[TotalCourse] = new Course;
		size = sizeof(Course);
		inf.read((char*)courseList[TotalCourse], size);
		TotalCourse++;
	}
	//cout << "Reading " << TotalCourse << " users\n";
}
void CourseInfo::Course::writeCount(int count)
{
	//int prev = readCount();
	ofstream outfile("Course_Count.txt", ios::trunc);
	outfile << count;
	cout << "\nFile Written\n";


}
int CourseInfo::Course::readCount()
{
	int count;
	ifstream infile("Course_Count.txt");

	if (!infile.is_open())
	{
		cerr << "Could not open the file\n";
		return 0;
	}

	infile >> count;
	//cout << count << endl;
	return count;
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

