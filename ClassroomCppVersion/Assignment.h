#pragma once
#include <string>
#include <iostream>
#include <map>
#include <vector>
#include "Course.h"
#include "User.h"
#include "Database.h"

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
		std::string assignedCourse;

	public:
		static vector<Assignment*> assignmentList;
		static int totalAssignment;
		Assignment()
		{
			publishTime = __TIME__;
			publishDate = __DATE__;
		}
		
		void assignUsers();
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

        string getAssignedCourse() const;
        void setAssignedCourse(string assignedCourse);

        void displayAssignedUsers() const;
        void setAssignedUsers()const;

        void displayCompletedUsers() const;
        void setCompletedUsers(string username) const;
		

		std::string getPublishDate() const;
		void setPublishDate(std::string publishDate);

		std::string getPublishTime() const;
		void setPublishTime(std::string publishTime);

		static void write();
		static void read();
		static void writeCount(int );
		static int readCount();

};
}