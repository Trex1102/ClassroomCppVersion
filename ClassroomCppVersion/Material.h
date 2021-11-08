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
		//UserInfo::User* uploaderTeacher;
		//CourseInfo::Course* linkedCourse;
	public:
		static int totalMaterials;
		std::map<string, string> materials;
		static vector<Material*> materialList;
		
		/// <summary>
		/// constructor is removed as *uploaderTeacher was used.
		/// </summary>

		void Display();
		static void write();
		static void read();
		static void writeCount(int);
		static int readCount();

	public:
        string getInputTime() const;
        void setInputTime(string inputTime);

        UserInfo::User* getUploaderTeacher() const;
        void setUploaderTeacher(UserInfo::User* uploaderTeacher);

        CourseInfo::Course* getLinkedCourse() const;
        void setLinkedCourse(CourseInfo::Course* linkedCourse);

	};
}