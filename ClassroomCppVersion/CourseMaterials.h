#pragma once
#include <iostream>
using namespace std;
namespace UserInfo
{
	class Teacher;
}

namespace CourseInfo
{
	class CourseMaterials
	{
	public:
		string inputTime;
		string materialConcept;
		string materialLink;
		string materialText;
		UserInfo::Teacher* uploaderTeacher;

	public:
		explicit CourseMaterials(UserInfo::Teacher* uploader_teacher)
			: uploaderTeacher(uploader_teacher)
		{
		}
	};
}