#pragma once
#include <string>
#include <iostream>
#include <vector>

#include "Attendance.h"
#include "Course.h"
#include "Course.h"
#include "Course.h"
#include "User.h"

namespace CourseInfo
{
	class Course;
	class attendance;
}

using namespace std;

namespace UserInfo
{
	class User;
	class Student;
	class Teacher
	{
	private:
		CourseInfo::Course* enrolledCourse;
		User* parentUser;
		static int teacherID;
	public:
		Teacher(CourseInfo::Course* enrolled_course, User* parent_user)
			:enrolledCourse(enrolled_course),
			parentUser(parent_user)
		{
			teacherID++;
			linkTeacherToUser();

		}
		// getters setters
		CourseInfo::Course* getEnrolledCourse() const { return enrolledCourse; }
        void setEnrolledCourse(CourseInfo::Course* enrolledCourse) { this->enrolledCourse = enrolledCourse; }

        User* getParentUser() const { return parentUser; }
        void setParentUser(User* parentUser) { this->parentUser = parentUser; }

		// class functions

		void takeAttendance() const; // teacher taking attendance
		void displayTeacherInfo() const;
		void addStudent(Student& student) const;
		void addCourseMaterials();
		void linkTeacherToUser() const;
};
}
