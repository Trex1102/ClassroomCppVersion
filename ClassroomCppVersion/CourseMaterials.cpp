#include "CourseMaterials.h"
#include <string>
#include <vector>

vector<CourseInfo::CourseMaterials*>CourseInfo::CourseMaterials::courseMaterialsList;

std::string CourseInfo::CourseMaterials::getInputTime() const
{
    return inputTime;
}

void CourseInfo::CourseMaterials::setInputTime(string inputTime)
{
    this->inputTime = inputTime;
}

UserInfo::User* CourseInfo::CourseMaterials::getUploaderTeacher() const
{
    return uploaderTeacher;
}

void CourseInfo::CourseMaterials::setUploaderTeacher(UserInfo::User* uploaderTeacher)
{
    this->uploaderTeacher = uploaderTeacher;
}

vector<CourseInfo::CourseMaterials*> CourseInfo::CourseMaterials::getCourseMaterialsList() const
{
    return courseMaterialsList;
}

void CourseInfo::CourseMaterials::setCourseMaterialsList(vector<CourseMaterials*> courseMaterialsList)
{
    this->courseMaterialsList = courseMaterialsList;
}


map<string,string> CourseInfo::CourseMaterials::getMaterials() const
{
    return materials;
}

void CourseInfo::CourseMaterials::setMaterials(map<string,string> materials)
{
    this->materials = materials;
}

