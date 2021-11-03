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
		std::string data;
	public:
		static int totalPosts;
		static std::vector<Post*> postList;
		Post()
		{
			time = __TIME__;
			date = __DATE__;
		}

		void setData(std::string _data)
		{
			data = move(_data);
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
	};
}