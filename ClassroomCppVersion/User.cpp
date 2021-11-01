#include <iostream>
#include <fstream>
#include "User.h"
using namespace std;

int UserInfo::User::TotalUser;
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
	//cout << "User ID: "<<user.getUserID();
	cout << "Department: "; cin >> user.department;
	cout << "Age: "; cin >> user.age;
	cout << "Email: "; cin >> user.email;
	cout << "Phone: "; cin >> user.phone;
	
	user.createUserName();

	cout << "Your Username is " << user.username << endl;
	cout << "Enter a password: "; cin >> user.password;

	cout << "Your account has been created successfully" << endl;
}

void UserInfo::User::User_diskout()
{
	ofstream outfile;
	outfile.open("User.DAT", ios::app | ios::binary);
	outfile.write((char*)this, sizeof(*this));
	

}
void UserInfo::User::User_diskin(int userid)
{
	ifstream infile;
	infile.open("User.DAT", ios::binary);
	infile.seekg(userid * sizeof(User));
	infile.read((char*)this, sizeof(*this));
}
/*void UserInfo::User::FindUser(string username, string password)
{
	long pos;
	ifstream infile;
	infile.open("User.DAT", ios::binary);
	infile.seekg(0);
	//User user;
	while (!infile.eof())
	{
		pos = infile.tellg();
		infile.read((char*)this, sizeof(*this));
		if (this->username == username)
		{
			if (this->password == password)
			{
				cout << "Login Successfull" << endl;
				infile.seekg(pos);
				break;
			}
			else
			{
				cout << "Password doesn't match" << endl;
			}
		}
		else
		{
			cout << "No user found" << endl;
		}
	}
}*/
int UserInfo::User::User_diskcount()
{
	ifstream infile;
	infile.open("User.DAT", ios::binary);
	infile.seekg(0, ios::end);
	return(int)infile.tellg()/sizeof(User);
	
}
void UserInfo::User::createUserName()
{
	username = firstName + to_string(TotalUser);
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
	//cout << "User id: " << getTotalUser() << endl;
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

int UserInfo::User::getTotalUser() const
{
    return TotalUser;
}

void UserInfo::User::setTotalUser()
{
	int uid = User_diskcount()+1;
	this->TotalUser= uid;
}

