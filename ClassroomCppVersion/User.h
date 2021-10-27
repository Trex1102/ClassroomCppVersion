#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "Course.h"

namespace CourseInfo
{
	class Course;
}

using namespace std;

namespace UserInfo {
    class User
    {
    private:
        
        string username;
        string name;
        string department;
        int age;
        string email;
        string phone;
        string password;

    public:
        static vector<User*> userList;
        static int userID;
        vector<CourseInfo::Course*> asStudent;
        vector<CourseInfo::Course*> asTeacher;


        User(string name, string department, int age, string email, string phone, string password)
	        : name(std::move(name)),
	          department(std::move(department)),
	          age(age),
	          email(std::move(email)),
	          phone(std::move(phone)),
	          password(std::move(password))
        {
            userID++;
            username = name + to_string(userID);
            userList.push_back(this);
        }

        

    public:

        // getters setters
        string getName() const { return name; }
        void setName(const string name) { this->name = name; }

        string getdepartment() const { return department; }
        void setdepartment(string department) { this->department = department; }

        int getAge() const { return age; }
        void setAge(const int age) { this->age = age; }

        string getEmail() const { return email; }
        void setEmail(string email) { this->email = email; }

        string getPhone() const { return phone; }
        void setPhone(string phone) { this->phone = phone; }

        string getPassword() const { return password; }
        void setPassword(string password) { this->password = password; }

        vector<CourseInfo::Course*> getAsStudent() const { return asStudent; }
        void setAsStudent(vector<CourseInfo::Course*> asStudent) { this->asStudent = asStudent; }

        vector<CourseInfo::Course*> getAsTeacher() const { return asTeacher; }
        void setAsTeacher(vector<CourseInfo::Course*> asTeacher) { this->asTeacher = asTeacher; }

        // class function
        void addAsStudent(CourseInfo::Course &course);
        void addAsTeacher(CourseInfo::Course& course);
    };
}