#pragma once
#include <iostream>
#include <map>
#include <fstream>
#include <vector>
#include <string>
#include "User.h"
#include "Course.h"
using namespace std;
namespace Database0
{
	void writeCount(int count, std::string filename);
	int readCount(std::string filename);
	static void read();
	static void write();
	static void display();

}
