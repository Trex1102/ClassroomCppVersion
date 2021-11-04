#pragma once
#include <string>
#include <iostream>
#include <map>
#include <vector>

#include "Attendance.h"
#include "Post.h"
#include "Assignment.h"
#include "Material.h"
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
		double courseCredit;
		

		
		vector<UserInfo::User*> studentList;
		vector<UserInfo::User*> teacherList;

	public:

		vector<Feature::Material*> courseMaterialList;
		vector<Feature::Assignment*> assignmentList;
		vector<Feature::Post*> postList;
		static int totalCourse;
		static vector<Course*> courseList;
		map<string, attendance*> attendanceList;

	public:

		Course()
		{
			//totalCourse++;
			createCourseCode();
			//courseList.push_back(this);
			
		}
		Course(string department, string course_id, string courseOutline, double courseCredit)
			: department(std::move(department)),
			  courseID(std::move(course_id)),
			  courseOutline(std::move(courseOutline)),
			  courseCredit(courseCredit)
		{
			//totalCourse++;
			createCourseCode();
			//courseList.push_back(this);
		}

        // class functions

		void enrollCourseTeacher(UserInfo::User& teacher);
		void enrollCourseStudent(UserInfo::User& student);
		void displayCourseInfo();
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
		

		vector<UserInfo::User*> getStudentList() const;
		void setStudentList(vector<UserInfo::User*> studentList);

		vector<UserInfo::User*> getTeacherList() const;
		void setTeacherList(vector<UserInfo::User*> teacherList);
    
		static void display();
		static void read();
		static void write();
		static void writeCount(int count);
		static int readCount();
	};
}
