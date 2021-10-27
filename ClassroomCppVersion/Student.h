#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "Course.h"
#include "Course.h"
#include "User.h"
#include "User.h"
using namespace std;


namespace CourseInfo
{
	class Course;
}



namespace UserInfo
{
	class User;

	class Student
	{
	private:
		string studentID;
		CourseInfo::Course* enrolledCourse;
		User* parentUser;
		
	public:
		Student(CourseInfo::Course* enrolled_course, User* parent_user, string student_id)
			:studentID(move(student_id)),
			enrolledCourse(enrolled_course),parentUser(parent_user)
		{
			
			linkStudentToUser();
		}

		// getters setters
		string getStudentID() const { return studentID; }
		void setStudentID(string studentID) { this->studentID = studentID; }

        CourseInfo::Course* getEnrolledCourse() const { return enrolledCourse; }
        void setEnrolledCourse(CourseInfo::Course* enrolledCourse) { this->enrolledCourse = enrolledCourse; }

        User* getParentUser() const { return parentUser; }
        void setParentUser(User* parentUser) { this->parentUser = parentUser; }

		// class functions

		void displayStudentInfo() const;
		void linkStudentToUser() const;
};
}