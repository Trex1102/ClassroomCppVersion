#include <iostream>
#include "User.h"
using namespace std;

int UserInfo::User::userID;
vector<UserInfo::User*> UserInfo::User::userList;

void UserInfo::User::addAsStudent(CourseInfo::Course& course)
{
	this->asStudent.push_back(&course);
}

void UserInfo::User::addAsTeacher(CourseInfo::Course& course)
{
	this->asTeacher.push_back(&course);
}

void UserInfo::User::createUser(User &user)
{
	cout << "First Name: ";  cin >> user.firstName;
	cout << "Middle Name: ";  cin >> user.middleName;
	cout << "Last Name: ";  cin >> user.lastName;
	cout << "Department: "; cin >> user.department;
	cout << "Age: "; cin >> user.age;
	cout << "Email: "; cin >> user.email;
	cout << "Phone: "; cin >> user.phone;
	
	user.createUserName();

	cout << "Your Username is " << user.username << endl;
	cout << "Enter a password: "; cin >> user.password;

	cout << "Your account has been created successfully" << endl;
}

void UserInfo::User::createUserName()
{
	username = firstName + to_string(userID);
}

void UserInfo::User::addCourseMaterials()
{
}

CourseInfo::Course* UserInfo::User::joinCourse(string courseCode, User & user)
{
	//string choice;
	for(const auto it: CourseInfo::Course::courseList)
	{
		if(it->getCourseCode() == courseCode)
		{
			cout << "Course Found" << endl;
			return it;
		}
	}
	return nullptr;
}

void UserInfo::User::displayInfo() const
{
	cout << "Name: " << firstName << ' ' << middleName << ' ' << lastName << endl;
	// other details

}

void UserInfo::User::addStudent(CourseInfo::Course &course,User& student)
{
	// check whether user is teacher of that course
	// add student to that course
}

void UserInfo::User::takeAttendance(CourseInfo::Course &course)
{
	CourseInfo::attendance attendance(&course);
	attendance.takeAttendance();
	course.attendanceList.insert({ static_cast<string>(__DATE__) , &attendance });
}



string UserInfo::User::getUsername() const
{
    return username;
}

void UserInfo::User::setUsername(string username)
{
    this->username = username;
}

string UserInfo::User::getFirstName() const
{
    return firstName;
}

void UserInfo::User::setFirstName(string firstName)
{
    this->firstName = firstName;
}

string UserInfo::User::getMiddleName() const
{
    return middleName;
}

void UserInfo::User::setMiddleName(string middleName)
{
    this->middleName = middleName;
}

int UserInfo::User::getAge() const
{
    return age;
}

void UserInfo::User::setAge(int age)
{
    this->age = age;
}

string UserInfo::User::getLastName() const
{
    return lastName;
}

void UserInfo::User::setLastName(string lastName)
{
    this->lastName = lastName;
}

string UserInfo::User::getDepartment() const
{
    return department;
}

void UserInfo::User::setDepartment(string department)
{
    this->department = department;
}

string UserInfo::User::getEmail() const
{
    return email;
}

void UserInfo::User::setEmail(string email)
{
    this->email = email;
}

string UserInfo::User::getPhone() const
{
    return phone;
}

void UserInfo::User::setPhone(string phone)
{
    this->phone = phone;
}

string UserInfo::User::getPassword() const
{
    return password;
}

void UserInfo::User::setPassword(string password)
{
    this->password = password;
}

vector<UserInfo::User*> UserInfo::User::getUserList() const
{
    return userList;
}

void UserInfo::User::setUserList(vector<User*> userList)
{
    this->userList = userList;
}

string UserInfo::User::getTeacherID() const
{
    return teacherID;
}

void UserInfo::User::setTeacherID(string teacherID)
{
    this->teacherID = teacherID;
}

string UserInfo::User::getStudentID() const
{
    return studentID;
}

void UserInfo::User::setStudentID(string studentID)
{
    this->studentID = studentID;
}

int UserInfo::User::getUserID() const
{
    return userID;
}

void UserInfo::User::setUserID(int userID)
{
    this->userID = userID;
}

void UserInfo::User::write()
{

	//int n = userList.size();
	
	ofstream ouf;
	//User user;
	int size = sizeof(User);
	ouf.open("User2.DAT", ios::trunc | ios::binary);
	if (!ouf)
	{
		//cout << "\nCan't open file\n";
		return;
	}
	for (unsigned j = 0; j < userList.size(); j++)
	{
		//ouf.write((char*)&User, sizeof(User));
		if (!ouf)
		{
			//cout << "\nCan't write to file\n";
			return;
		}
		ouf.write((char*)(userList[j]), size);
	}

	cout << "Writing " << userList.size() << " Users.\n";
	writeCount(userList.size());
}
void UserInfo::User::read()
{
	int cur = readCount();
	userID = cur;
	//User user;
	int size = sizeof(User);
	ifstream inf;
	inf.open("User2.DAT", ios::binary);
	if (!inf)
	{
		//cout << "\nCan't open file\n"; return;
		return;
	}
	int TotalUser = 0; // solution 1 : debug 2: store & retrieve
	for(int j=0;j<cur;j++)
	{
		//cout << TotalUser << endl;
		userList.push_back(nullptr);
		userList[TotalUser] = new User;
		size = sizeof(User);
		inf.read((char*)userList[TotalUser], size);
		TotalUser++;
	}
	//cout << "Reading " << TotalUser << " users\n";
}
void UserInfo::User::writeCount(int count)
{
	//int prev = readCount();
	ofstream outfile("Count.txt",ios::trunc);
	outfile << count;
	//cout << "\nFile Written\n";


}
int UserInfo::User::readCount()
{
	int count;
	ifstream infile("Count.txt");

	if (!infile.is_open())
	{
		//cerr << "Could not open the file\n";
		return 0;
	}

	infile >> count;
	//cout << count << endl;
	return count;
}

