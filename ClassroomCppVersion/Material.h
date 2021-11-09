#pragma once
#include <iostream>
#include <vector>
#include "Course.h"
#include <string>
using namespace std;

namespace UserInfo
{
	class User;
}


namespace CourseInfo
{
	class Course;
}


namespace Feature
{
	class Material
	{
	public:
		string inputTime;
		string uploaderTeacher;
		string linkedCourse;
	public:
		Material(){}
		static int totalMaterials;
		std::map<string, string> materials; // have to find alternative
		static vector<Material*> materialList;

		void Display();
		static void write();
		static void read();
		static void writeCount(int);
		static int readCount();

	public:
        string getInputTime() const;
        void setInputTime(string inputTime);

        string getUploaderTeacher() const;
        void setUploaderTeacher(string uploaderTeacher);

        string getLinkedCourse() const;
        void setLinkedCourse(string linkedCourse);

	};
}