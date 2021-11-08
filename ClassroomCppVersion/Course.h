#pragma once
#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <array>
#include "Attendance.h"
#include "Post.h"
#include "Assignment.h"
#include "Material.h"
#include "Database.h"
using namespace std;
namespace UserInfo
{
	class Student;
	class Teacher;
	class User;
}

namespace Feature
{
	class Post;
	class Assignment;
	class Material;
}

namespace CourseInfo
{
	class attendance;
	
	class Course
	{
	private:
		string courseCode;
		string department;
		string courseID;
		string courseOutline;
		// 1. char 2. file i/o
		double courseCredit;

	public:
		static int totalCourse;
		static vector<Course*> courseList;

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
			createCourseCode();
		}
		
		//void operator = (const Course& course);
		void enrollCourseTeacher(UserInfo::User& teacher);
		bool enrollCourseStudent(UserInfo::User& student);
		void displayCourseInfo() const;
		void showCourseMaterials() const;
		void static createCourse(CourseInfo::Course &course, UserInfo::User &teacher);
		void createCourseCode();
		static void display();
		static void read();
		static void write();
		static void writeCount(int count);
		static int readCount();


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
