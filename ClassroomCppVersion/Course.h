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

        // class functions

		void enrollCourseTeacher(UserInfo::User& teacher);
		void enrollCourseStudent(UserInfo::User& student);
		void displayCourseInfo();
		void addCourseMaterial(CourseMaterials& course_material);
		void showCourseMaterials();
		void static createCourse(CourseInfo::Course &course, UserInfo::User &teacher);
		void createCourseCode();
		~Course() = default;



	
	public:
	    string getCourseCode() const;
	    void setCourseCode(string courseCode);

	    string getDepartment() const;
	    void setDepartment(string department);

	    string getCourseID() const;
	    void setCourseID(string courseID);

	    string getCourseOutline() const;
	    void setCourseOutline(string courseOutline);

	    double getCourseCredit() const;
	    void setCourseCredit(double courseCredit);

};
}
