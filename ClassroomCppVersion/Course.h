#pragma once
#include <string>
#include <iostream>
#include <map>
#include <vector>
#include "CourseMaterials.h"
#include "Attendance.h"
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
		string courseCode;
		string department;
		string courseID;
		string courseOutline;
		double courseCredit;

		vector<CourseMaterials*> courseMaterialList;
		vector<UserInfo::User*> studentList;
		vector<UserInfo::User*> teacherList;

	public:
		static vector<Course*> courseList;
		map<string, attendance*> attendanceList;
	public:

		Course()
		{
			createCourseCode();
		}
		Course(string department, string course_id, string courseOutline, double courseCredit)
			: department(std::move(department)),
			  courseID(std::move(course_id)),
			  courseOutline(std::move(courseOutline)),
			  courseCredit(courseCredit)
		{
			//courseCode++;
			
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


        vector<UserInfo::User*> getStudentList() const { return studentList; }
        void setStudentList(vector<UserInfo::User*> studentList) { this->studentList = studentList; }

        vector<UserInfo::User*> getTeacherList() const { return teacherList; }
        void setTeacherList(vector<UserInfo::User*> teacherList) { this->teacherList = teacherList; }

		map<string,attendance*> getattendanceList() const { return attendanceList; }
		void setattendanceList(map<string,attendance*> attendanceList) { this->attendanceList = attendanceList; }

		string getCourseCode() const { return courseCode; }

        // class functions

		void enrollCourseTeacher(UserInfo::User& teacher);
		void enrollCourseStudent(UserInfo::User& student);
		void displayCourseInfo();
		void addCourseMaterial(CourseMaterials& course_material);
		void showCourseMaterials();
		void static createCourse(CourseInfo::Course &course, UserInfo::User &teacher);
		void createCourseCode();
		
};
}
