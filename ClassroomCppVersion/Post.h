#pragma once
#include <string>
#include <iostream>
#include <map>
#include <vector>

namespace Feature
{
	class Post
	{
	private:
		std::string time, date;
		std::string data; // need to be stored in file
		std::string postID;

		char a[100];
	public:
		std::string enrolledCourseCode;
		static int totalPosts;
		static std::vector<Post*> postList;
		Post()
		{
			time = __TIME__;
			date = __DATE__;
		}

		void seta()
		{
			
		}

		void setData(std::string _data)
		{
			data = _data;
		}

		std::string getData()const
		{
			return data;
		}

		void Display()
		{
			std::cout << "Date: " << date << std::endl;
			std::cout << "Time: " << time<< std::endl;
			std::cout << "Post: " << data<< std::endl;
		}
		void createPostID()
		{
			std::string a = std::to_string(totalPosts);
			postID = a;
		}

		std::string getID() const
		{
			return postID;
		}
		static void write();
		static void read();
		static void write_PostCount(int );
		static int read_PostCount();
	};
}