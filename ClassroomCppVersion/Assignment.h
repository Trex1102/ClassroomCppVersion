#pragma once
#include <string>
#include <iostream>
#include <map>
#include <vector>
#include "Course.h"
#include "User.h"
namespace CourseInfo
{
	class Course;
}
namespace UserInfo
{
	class User;
}

namespace Feature
{
	class Assignment
	{
	private:
		std::string deadlineDate;
		std::string deadlineTime;
		std::string publishDate;
		std::string publishTime;
		std::string data;
		std::map<UserInfo::User*,std::string> PrivateComments;
		//std::string assignmentID;

		CourseInfo::Course* assignedCourse;
		vector<UserInfo::User*> assignedUsers;
		vector<UserInfo::User*> comepletedUsers;
		vector<UserInfo::User*> missedUesrs;
	public:
		static vector<Assignment*> assignmentList;
		static int totalAssignment;
		std::map<UserInfo::User*,std::string> PublicComments;
		explicit Assignment(CourseInfo::Course* assigned_course)
			: assignedCourse(assigned_course)
		{
		}


		void assignUsers();
		//void createID();
		void Complete(std::string username);
		void Missed();
		void PublicComment(UserInfo::User &user,std::string msg);
		void PrivateComment(UserInfo::User &user,string msg);
		void Display();


	public:
        std::string getDeadlineDate() const;
        void setDeadlineDate(std::string deadlineDate);

        std::string getDeadlineTime() const;
        void setDeadlineTime(std::string deadlineTime);

        std::string getData() const;
        void setData(std::string data);

        CourseInfo::Course* getAssignedCourse() const;
        void setAssignedCourse(CourseInfo::Course* assignedCourse);

        vector<UserInfo::User*> getAssignedUsers() const;
        void setAssignedUsers(vector<UserInfo::User*> assignedUsers);

        vector<UserInfo::User*> getComepletedUsers() const;
        void setComepletedUsers(vector<UserInfo::User*> comepletedUsers);

		std::string getPublishDate() const;
		void setPublishDate(std::string publishDate);

		std::string getPublishTime() const;
		void setPublishTime(std::string publishTime);

		vector<UserInfo::User*> getMissedUesrs() const;
		void setMissedUesrs(vector<UserInfo::User*> missedUesrs);


};
}