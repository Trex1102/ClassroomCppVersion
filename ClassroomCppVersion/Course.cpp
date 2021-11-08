#include "Course.h"
using namespace std;

int CourseInfo::Course::totalCourse;
vector<CourseInfo::Course*>CourseInfo::Course::courseList;

void CourseInfo::Course::enrollCourseTeacher(UserInfo::User& teacher)
{
	
	Database::Relations::CourseTeacher[this->getCourseCode()].push_back(teacher.getUsername());
	Database::Relations::TeacherCourse[teacher.getUsername()].push_back(this->getCourseCode());
}

bool CourseInfo::Course::enrollCourseStudent(UserInfo::User& student)
{
	// check whether he is a teacher or not
	if(!Database::Relations::TeacherCourse[student.getUsername()].empty())
	{
		cout << "Oh boy! You are already a teacher!\n";
		return false;
	}

	cout << "You are added successfully\n";

	/*Database Part*/
	Database::Relations::StudentCourse[student.getUsername()].push_back(this->getCourseCode());
	Database::Relations::CourseStudent[this->getCourseCode()].push_back(student.getUsername());
	return true;
}

void CourseInfo::Course::displayCourseInfo() const
{
	cout << "Course Information: " << endl;
	cout << "Course ID: " << courseID << endl;
	cout << "Department Name: " << department << endl;
	cout << "Course Code: " << courseCode << endl;
	// show teachers
	cout << "Course Teachers: " << endl;
	for (const auto it : Database::Relations::CourseTeacher[courseCode])
	{
		cout << it << endl;
	}
	// show students
	cout << "Course Students: " << endl;
	for(const auto it:Database::Relations::CourseStudent[courseCode])
	{
		cout << it << endl;
	}
}
void CourseInfo::Course::showCourseMaterials() const
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
	cout << "Your Course Code is " << course.courseCode << endl;
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
	ofstream ouf;
	int size = sizeof(Course);
	ouf.open("Database0/Course.DAT", ios::trunc | ios::binary);
	if (!ouf)
	{
		return;
	}
	for (unsigned j = 0; j < courseList.size(); j++)
	{
		if (!ouf)
		{
			//cout << "\nCan't write to file\n";
			return;
		}
		ouf.write((char*)(courseList[j]), size);
	}

	//cout << "Writing " << courseList.size() << " Courses.\n";
	writeCount(courseList.size());
}
void CourseInfo::Course::read()
{
	int cur = readCount();
	totalCourse = cur;
	int size = sizeof(Course);
	ifstream inf;
	inf.open("Database0/Course.DAT", ios::binary);
	if (!inf.is_open())
	{
		return;
	}
	int TotalCourse = 0; 
	for (int j = 0;j < cur;j++)
	{
		try 
		{
			courseList.push_back(nullptr);
			courseList[TotalCourse] = new Course;
			size = sizeof(Course);
			inf.read((char*)courseList[TotalCourse], size);
			TotalCourse++;
		}
		catch (bad_alloc)
		{
			cout << "Can't Allocate Course" << endl;
		}
	}
}
void CourseInfo::Course::writeCount(int count)
{
	ofstream outfile("Database0/Course_Count.txt", ios::trunc);
	outfile << count;
//	cout << "\nFile Written\n";


}
int CourseInfo::Course::readCount()
{
	int count;
	ifstream infile("Database0/Course_Count.txt");

	if (!infile.is_open())
	{
		//cerr << "Could not open the file\n";
		return 0;
	}

	infile >> count;
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


