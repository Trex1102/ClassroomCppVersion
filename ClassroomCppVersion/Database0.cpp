#include "Database0.h"

void Database0::write()
{

	//int n = userList.size();

	ofstream ouf;
	//User user;
	int size = sizeof(UserInfo::User);
	ouf.open("Database0/User2.DAT", ios::trunc | ios::binary);
	if (!ouf)
	{
		//cout << "\nCan't open file\n";
		return;
	}
	for (unsigned j = 0; j < UserInfo::User::userList.size(); j++)
	{
		//ouf.write((char*)&User, sizeof(User));
		if (!ouf)
		{
			//cout << "\nCan't write to file\n";
			return;
		}
		ouf.write((char*)(UserInfo::User::userList[j]), size);
	}

	//cout << "Writing " << UserInfo::User::userList.size() << " Users.\n";
	writeCount(UserInfo::User::userList.size(), "Database0/User_Count.txt");


	//int n = userList.size();


	//User user;
	 size = sizeof(CourseInfo::Course);
	ouf.open("Database0/Course.DAT", ios::trunc | ios::binary);
	if (!ouf)
	{
		//cout << "\nCan't open file\n";
		return;
	}
	for (unsigned j = 0; j < CourseInfo::Course::courseList.size(); j++)
	{
		//ouf.write((char*)&User, sizeof(User));
		if (!ouf)
		{
			//cout << "\nCan't write to file\n";
			return;
		}
		ouf.write((char*)(CourseInfo::Course::courseList[j]), size);
	}

	cout << "Writing " << CourseInfo::Course::courseList.size() << " Courses.\n";
	writeCount(CourseInfo::Course::courseList.size(), "Database0/Course_count.txt");

}
void Database0::read()
{
	int cur = readCount("Database0/User_Count.txt");
	UserInfo::User::userID = cur;
	//User user;
	int size = sizeof(UserInfo::User);
	ifstream inf;
	inf.open("Database0/User2.DAT", ios::binary);
	if (!inf.is_open())
	{
		//cout << "\nCan't open file\n"; return;
		return;
	}
	int TotalUser = 0; // solution 1 : debug 2: store & retrieve
	for (int j = 0;j < cur;j++)
	{
		//cout << TotalUser << endl;
		UserInfo::User::userList.push_back(nullptr);
		UserInfo::User::userList[TotalUser] = new UserInfo::User;
		size = sizeof(UserInfo::User);
		inf.read((char*)UserInfo::User::userList[TotalUser], size);
		TotalUser++;
	}
	//cout << "Reading " << TotalUser << " users\n";

	cur = readCount("Database0/Course_Count.txt");
	CourseInfo::Course::totalCourse = cur;
	//User user;
	 size = sizeof(CourseInfo::Course);
	//ifstream inf;
	inf.open("Database0/Course.DAT", ios::binary);
	if (!inf.is_open())
	{
		//cout << "\nCan't open file\n"; return;
		return;
	}
	int TotalCourse = 0; // solution 1 : debug 2: store & retrieve
	for (int j = 0;j < cur;j++)
	{
		//cout << TotalCourse << endl;
		CourseInfo::Course::courseList.push_back(nullptr);
		CourseInfo::Course::courseList[TotalCourse] = new CourseInfo::Course; // new memory allocation
		size = sizeof(CourseInfo::Course);
		inf.read((char*)CourseInfo::Course::courseList[TotalCourse], size);
		TotalCourse++;
	}
}
void Database0::writeCount(int count, std::string filename)
{
	//int prev = readCount();
	ofstream outfile(filename, ios::trunc);
	outfile << count;
	//cout << "\nFile Written\n";


}
int Database0::readCount(std::string filename)
{
	int count;
	ifstream infile(filename);

	if (!infile.is_open())
	{
		//cerr << "Could not open the file\n";
		return 0;
	}

	infile >> count;
	//cout << count << endl;
	return count;
}