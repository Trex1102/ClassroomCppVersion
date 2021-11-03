#include "Assignment.h"
using namespace std;

int Feature::Assignment::totalAssignment;
vector<Feature::Assignment*> Feature::Assignment::assignmentList;

void Feature::Assignment::assignUsers()
{
    for(const auto it: assignedCourse->getStudentList())
    {
        assignedUsers.push_back(it);
    }
}

void Feature::Assignment::Complete(std::string username)
{
    for (const auto it : assignedCourse->getStudentList())
    {
        if(it->getUsername() == username)
        {
            comepletedUsers.push_back(it);
        }
    }
}

void Feature::Assignment::Missed()
{
    
}

void Feature::Assignment::PublicComment(UserInfo::User &user,std::string msg)
{
    PublicComments.insert({ &user, msg });
}

void Feature::Assignment::PrivateComment(UserInfo::User &user,string msg)
{
    PrivateComments.insert({ &user,msg });
}

void Feature::Assignment::Display()
{
    cout << data << endl;
    cout << "Published: "<<publishDate <<" "<<publishTime <<endl;
    cout << "Deadline: " << deadlineDate << " " << deadlineTime << endl;
    cout << "Comments: " << endl;
    for(auto it: PublicComments)
    {
        cout << "User name: " << it.first->getUsername() << endl;
        cout << "Comment: " << it.second << endl;
    }
}















std::string Feature::Assignment::getDeadlineDate() const
{
    return deadlineDate;
}

void Feature::Assignment::setDeadlineDate(std::string deadlineDate)
{
    this->deadlineDate = deadlineDate;
}

std::string Feature::Assignment::getDeadlineTime() const
{
    return deadlineTime;
}

void Feature::Assignment::setDeadlineTime(std::string deadlineTime)
{
    this->deadlineTime = deadlineTime;
}

std::string Feature::Assignment::getData() const
{
    return data;
}

void Feature::Assignment::setData(std::string data)
{
    this->data = data;
}


CourseInfo::Course* Feature::Assignment::getAssignedCourse() const
{
    return assignedCourse;
}

void Feature::Assignment::setAssignedCourse(CourseInfo::Course* assignedCourse)
{
    this->assignedCourse = assignedCourse;
}

vector<UserInfo::User*> Feature::Assignment::getAssignedUsers() const
{
    return assignedUsers;
}

void Feature::Assignment::setAssignedUsers(vector<UserInfo::User*> assignedUsers)
{
    this->assignedUsers = assignedUsers;
}

vector<UserInfo::User*> Feature::Assignment::getComepletedUsers() const
{
    return comepletedUsers;
}

void Feature::Assignment::setComepletedUsers(vector<UserInfo::User*> comepletedUsers)
{
    this->comepletedUsers = comepletedUsers;
}


std::string Feature::Assignment::getPublishDate() const
{
    return publishDate;
}

void Feature::Assignment::setPublishDate(std::string publishDate)
{
    this->publishDate = publishDate;
}

std::string Feature::Assignment::getPublishTime() const
{
    return publishTime;
}

void Feature::Assignment::setPublishTime(std::string publishTime)
{
    this->publishTime = publishTime;
}

vector<UserInfo::User*> Feature::Assignment::getMissedUesrs() const
{
    return missedUesrs;
}

void Feature::Assignment::setMissedUesrs(vector<UserInfo::User*> missedUesrs)
{
    this->missedUesrs = missedUesrs;
}

