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
		string time, date;
		string data;
	public:
		Post()
		{
			time = __TIME__;
			date = __DATE__;
		}

		void setData(string _data)
		{
			data = move(_data);
		}

		string getData()const
		{
			return data;
		}

		void Display()
		{
			cout << "Date: " << date << endl;
			cout << "Time: " << time<<endl;
			cout << "Post: " << data<<endl;
		}
	};
}