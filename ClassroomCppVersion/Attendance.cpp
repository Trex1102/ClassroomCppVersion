
#include "Attendance.h"
using namespace  std;

int CourseInfo::attendance::totalAttendance;
vector<CourseInfo::attendance*>CourseInfo::attendance::AttendanceList;

void CourseInfo::attendance::takeAttendance()
{
	{
		//int choice;
		/*for (const auto it : course->getStudentList())
		{
			cout << "If Present input 1 otherwise input 0 " << endl;
			cout << "Student username: " << it->getUsername() << endl;
			cin >> choice;
			if (choice == 0)
			{
				dailyAttendance.insert(pair<string, string>(it->getUsername(), "Absent"));
			}
			else
			{
				dailyAttendance.insert(pair<string, string>(it->getUsername(), "Present"));
			}
		}*/
	}
}
void CourseInfo::attendance::write()
{

	//int n = userList.size();

	ofstream ouf;
	//User user;
	int size = sizeof(attendance);
	ouf.open("Attendance.DAT", ios::trunc | ios::binary);
	if (!ouf)
	{
		cout << "\nCan't open file\n";
		return;
	}
	for (unsigned j = 0; j < AttendanceList.size(); j++)
	{
		//ouf.write((char*)&User, sizeof(User));
		if (!ouf)
		{
			cout << "\nCan't write to file\n";
			return;
		}
		ouf.write((char*)(AttendanceList[j]), size);
	}

	cout << "Writing " << AttendanceList.size() << " Attendances.\n";
	writeCount(AttendanceList.size());
}
void CourseInfo::attendance::read()
{
	int cur = readCount();
	totalAttendance = cur;
	//User user;
	int size = sizeof(attendance);
	ifstream inf;
	inf.open("Attendance.DAT", ios::binary);
	if (!inf.is_open())
	{
		//cout << "\nCan't open file\n"; return;
		return;
	}
	int Total = 0; // solution 1 : debug 2: store & retrieve
	for (int j = 0;j < cur;j++)
	{
		//cout << TotalCourse << endl;
		AttendanceList.push_back(nullptr);
		AttendanceList[Total] = new attendance;
		size = sizeof(attendance);
		inf.read((char*)AttendanceList[Total], size);
		Total++;
	}
	//cout << "Reading " << TotalCourse << " users\n";
}
void CourseInfo::attendance::writeCount(int count)
{
	//int prev = readCount();
	ofstream outfile("Attendance_Count.txt", ios::trunc);
	outfile << count;
	cout << "\nFile Written\n";


}
int CourseInfo::attendance::readCount()
{
	int count;
	ifstream infile("Attendance_Count.txt");

	if (!infile.is_open())
	{
		cerr << "Could not open the file\n";
		return 0;
	}

	infile >> count;
	//cout << count << endl;
	return count;
}
