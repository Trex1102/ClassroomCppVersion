#include "Material.h"

vector<Feature::Material*> Feature::Material::materialList;
int Feature::Material::totalMaterials;

void Feature::Material::Display()
{
    cout << "Course Materials: " << endl;
	for(const auto it:materials)
	{
		cout << "Concept: " << it.first << endl;
		cout << "Link: " << it.second << endl;
	}
}

string Feature::Material::getInputTime() const
{
    return inputTime;
}

void Feature::Material::setInputTime(string inputTime)
{
    this->inputTime = inputTime;
}

UserInfo::User* Feature::Material::getUploaderTeacher() const
{
    return uploaderTeacher;
}

void Feature::Material::setUploaderTeacher(UserInfo::User* uploaderTeacher)
{
    this->uploaderTeacher = uploaderTeacher;
}

CourseInfo::Course* Feature::Material::getLinkedCourse() const
{
    return linkedCourse;
}

void Feature::Material::setLinkedCourse(CourseInfo::Course* linkedCourse)
{
    this->linkedCourse = linkedCourse;
}

