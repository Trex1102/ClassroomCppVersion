#pragma once
#include <iostream>
#include <map>
#include <fstream>
#include <vector>
#include <string>
using namespace std;
namespace Database
{
	void writeCount(int count, std::string filename);
	int readCount(std::string filename);
	class Relations
	{
	public:
		static map<string, vector<string>> CourseStudent;
		static int CourseStudentcount;
		static map<string, vector<string>> CourseTeacher;
		static int CourseTeachercount; 

		static map<string, vector<string>> StudentCourse; 
		static int StudentCoursecount; 
		static map<string, vector<string>> TeacherCourse; // not implemented
		static int TeacherCoursecount; // not implemented

		static map<string, vector<string>> CoursePost;
		static int CoursePostcount;
		static map<string, vector<string>> CourseAssignment;
		static int CourseAssignmentcount;
		static void read();
		static void write();
		static void display();
		
	};

	inline void input()
	{
		Relations::CourseStudent["1"].push_back("saikat");
		Relations::CourseStudent["2"].push_back("saikat");
		Relations::CourseStudent["2"].push_back("saikat");
		Relations::CourseStudent["3"].push_back("saikat");
		Relations::CourseStudent["4"].push_back("saikat");

		Relations::CoursePost["a"].push_back("saikat");
		Relations::CoursePost["b"].push_back("saikat");
		Relations::CoursePost["b"].push_back("saikat");
		Relations::CoursePost["c"].push_back("saikat");
		Relations::CoursePost["d"].push_back("saikat");

		Relations::CourseAssignment["x"].push_back("saikat");
		Relations::CourseAssignment["y"].push_back("saikat");
		Relations::CourseAssignment["y"].push_back("saikat");
		Relations::CourseAssignment["w"].push_back("saikat");
		Relations::CourseAssignment["z"].push_back("saikat");
	}
}
