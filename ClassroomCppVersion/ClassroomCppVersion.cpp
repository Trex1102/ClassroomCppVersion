// ClassroomCppVersion.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "User.h"
#include "Course.h"
#include "attendance.h"
#include "Teacher.h"
#include "Student.h"
#include "LoginSystem.h"
using namespace std;

int main()
{
    //UserInfo::User* currentUser = NULL;
    UserInfo::User user1("Saikat","CSE", 18, "saikatbahubali", "01774241186", "1234");
    UserInfo::User user2("Alvee", "CSE", 18, "1234", "01774234434", "12334");
	cout << user1.getEmail() << endl;
    std::cout << "Hello World!\n";
    CourseInfo::Course  c1("cse", "4241", "blank", 4.00);

	UserInfo::Teacher t1(&c1, &user1);
    UserInfo::Student s1(&c1, &user2 , "190041103");
    
    c1.enrollCourseTeacher(t1);
    c1.enrollCourseStudent(s1);

    LoginInfo::loginSystem();

}
