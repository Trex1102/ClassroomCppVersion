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
        string firstName;
        string middleName;
        string lastName;
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


        User()
        {
            userID++;
            userList.push_back(this);
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
        }


        // getters setters
        string getUsername() const { return username; }
        void setUsername(string username) { this->username = username; }

        string getFirstName() const { return firstName; }
        void setFirstName(string firstName) { this->firstName = firstName; }

        string getMiddleName() const { return middleName; }
        void setMiddleName(string middleName) { this->middleName = middleName; }

        string getLastName() const { return lastName; }
        void setLastName(string lastName) { this->lastName = lastName; }

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
        void static createUser(User &user);
        void createUserName();
                    

};
}