#pragma once
#include <iostream>
#include <vector>
#include "Course.h"
using namespace std;
namespace UserInfo
{
	class User;
	class Teacher;
}

namespace CourseInfo
{
	class Course;
	class CourseMaterials
	{
	public:
		string inputTime;
		//string materialConcept;
		//vector<string> materialLink;
		//vector<string> materialText;
		map<string, string> materials;
		UserInfo::User* uploaderTeacher;
		CourseInfo::Course* materialCourse;
		//friend class AddMaterialState;
	public:
		static vector<CourseMaterials*> courseMaterialsList;
		explicit CourseMaterials(UserInfo::User* uploader_teacher, CourseInfo::Course* course)
			: uploaderTeacher(uploader_teacher), materialCourse(course)
		{
			inputTime = __TIME__;
			courseMaterialsList.push_back(this);
		}


	public:
        string getInputTime() const;
        void setInputTime(string inputTime);

		map<string, string> getMaterials() const;
		void setMaterials(map<string, string> materials);

        UserInfo::User* getUploaderTeacher() const;
        void setUploaderTeacher(UserInfo::User* uploaderTeacher);

        vector<CourseMaterials*> getCourseMaterialsList() const;
        void setCourseMaterialsList(vector<CourseMaterials*> courseMaterialsList);



};
}