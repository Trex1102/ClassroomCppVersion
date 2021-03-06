#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include "Course.h"
#include "Attendance.h"

namespace CourseInfo
{
	class Course;
}

using namespace std;

namespace UserInfo {
    class User
    {
    private:
        
        string username=" ";
        string firstName=" ";
        string middleName=" ";
        string lastName=" ";
        string department=" ";
        int age;
        string email=" ";
        string phone=" ";
        string password=" ";

        string teacherID, studentID;
    public:
        static vector<User*> userList;

        static int userID;

        User()
        {
            age = 18;
        }

        User(string username, string first_name, string middle_name, string last_name, string department, int age,
	        string email, string phone, string password)
	        : username(std::move(username)),
	          firstName(std::move(first_name)),
	          middleName(std::move(middle_name)),
	          lastName(std::move(last_name)),
	          department(std::move(department)),
	          age(age),
	          email(std::move(email)),
	          phone(std::move(phone)),
	          password(std::move(password))
        {
            age = 18;
        }

        //friend ostream& operator<<(ostream& c, const User& user);
      //  void operator = (const User& user);
        // class function
        void static createUser(User &user);
        void createUserName();
        void displayInfo() const;
        static void takeAttendance(CourseInfo::Course &course);
        static void addCourseMaterials();
        static CourseInfo::Course* joinCourse(string courseCode,User& user);
        static void read();
        static void write();
        static void writeCount(int);
        static int readCount();

        ~User() = default;
    // getters setters
	public:
	    string getUsername() const;
	    void setUsername(string username);

	    string getFirstName() const;
	    void setFirstName(string firstName);

	    string getMiddleName() const;
	    void setMiddleName(string middleName);

	    int getAge() const;
	    void setAge(int age);

	    string getLastName() const;
	    void setLastName(string lastName);

	    string getDepartment() const;
	    void setDepartment(string department);

	    string getEmail() const;
	    void setEmail(string email);

	    string getPhone() const;
	    void setPhone(string phone);

	    string getPassword() const;
	    void setPassword(string password);

	    vector<User*> getUserList() const;
	    void setUserList(vector<User*> userList);

	    string getTeacherID() const;
	    void setTeacherID(string teacherID);

	    string getStudentID() const;
	    void setStudentID(string studentID);

	    int getUserID() const;
	    void setUserID(int userID);
	};
}