#pragma once
#include <string>
#include <iostream>
#include <map>
#include <vector>
#include "CourseMaterials.h"
#include "attendance.h"
#include "Student.h"
#include "Teacher.h"
using namespace std;
namespace UserInfo
{
	class Student;
	class Teacher;
	class User;
}

namespace CourseInfo
{
	class attendance;
	class CourseMaterials;
	class Course
	{
	private:
		string department;
		string courseID;
		string courseOutline;
		double courseCredit;

		vector<CourseMaterials*> courseMaterialList;
		vector<UserInfo::Student*> studentList;
		vector<UserInfo::Teacher*> teacherList;
        

		friend class UserInfo::Teacher;
	public:
		map<string, attendance*> attendanceList;
	public:
		Course(string department, string course_id, string courseOutline, double courseCredit)
			: department(std::move(department)),
			  courseID(std::move(course_id)),
			  courseOutline(std::move(courseOutline)),
			  courseCredit(courseCredit)
		{
		}

		//getters setters
        string getdepartment() const { return department; }
        void setdepartment(string department) { this->department = department; }

        string getCourseID() const { return courseID; }
        void setCourseID(string courseID) { this->courseID = courseID; }

        string getcourseOutline() const { return courseOutline; }
        void setcourseOutline(string courseOutline) { this->courseOutline = courseOutline; }

        double getcourseCredit() const { return courseCredit; }
        void setcourseCredit(double courseCredit) { this->courseCredit = courseCredit; }


        vector<UserInfo::Student*> getStudentList() const { return studentList; }
        void setStudentList(vector<UserInfo::Student*> studentList) { this->studentList = studentList; }

        vector<UserInfo::Teacher*> getTeacherList() const { return teacherList; }
        void setTeacherList(vector<UserInfo::Teacher*> teacherList) { this->teacherList = teacherList; }

		map<string,attendance*> getattendanceList() const { return attendanceList; }
		void setattendanceList(map<string,attendance*> attendanceList) { this->attendanceList = attendanceList; }

        // class functions

		void enrollCourseTeacher(UserInfo::Teacher& teacher);
		void enrollCourseStudent(UserInfo::Student& student);
		void displayCourseInfo();
		void addCourseMaterial(CourseMaterials& course_material);
		void showCourseMaterials();
};
}
