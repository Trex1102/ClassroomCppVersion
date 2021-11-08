#include "Assignment.h"
#include<fstream>
using namespace std;

int Feature::Assignment::totalAssignment;
vector<Feature::Assignment*> Feature::Assignment::assignmentList;

void Feature::Assignment::assignUsers()
{
   
}

void Feature::Assignment::Complete(std::string username)
{
   /* for (const auto it : assignedCourse->getStudentList())
    {
        if(it->getUsername() == username)
        {
            comepletedUsers.push_back(it);
        }
    }*/
}

void Feature::Assignment::Missed()
{
    
}

void Feature::Assignment::PublicComment(UserInfo::User &user,std::string msg)
{

}

void Feature::Assignment::PrivateComment(UserInfo::User &user,string msg)
{

}

void Feature::Assignment::Display()
{
    cout << data << endl;
    cout << "Published: "<<publishDate <<" "<<publishTime <<endl;
    cout << "Deadline: " << deadlineDate << " " << deadlineTime << endl;
    cout << "Comments: " << endl;
    /*for(auto it: PublicComments)
    {
        cout << "User name: " << it.first->getUsername() << endl;
        cout << "Comment: " << it.second << endl;
    }*/
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


string Feature::Assignment::getAssignedCourse() const
{
    return assignedCourse;
}

void Feature::Assignment::setAssignedCourse(string assignedCourse)
{
	this->assignedCourse = assignedCourse;
}

void Feature::Assignment::displayAssignedUsers() const
{
    for(auto it: Database::Relations::AssignmentAssignedStudent[assignedCourse])
    {
		cout << it << endl;
    }
}

void Feature::Assignment::setAssignedUsers() const
{
	for(auto it:Database::Relations::CourseStudent[assignedCourse])
	{
		Database::Relations::AssignmentAssignedStudent[assignedCourse].push_back(it);
	}
}

void Feature::Assignment::displayCompletedUsers() const
{
    for(auto it:Database::Relations::AssignmentCompletedStudent[assignedCourse])
    {
		cout << it << endl;
    }
}

void Feature::Assignment::setCompletedUsers(string username) const
{
	Database::Relations::AssignmentCompletedStudent[assignedCourse].push_back(username);
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

void Feature::Assignment::write()
{

	//int n = userList.size();

	ofstream ouf;
	//User user;
	int size = sizeof(Assignment);
	ouf.open("Assignment.DAT", ios::trunc | ios::binary);
	if (!ouf)
	{
		cout << "\nCan't open file\n";
		return;
	}
	for (unsigned j = 0; j < assignmentList.size(); j++)
	{
		//ouf.write((char*)&User, sizeof(User));
		if (!ouf)
		{
			cout << "\nCan't write to file\n";
			return;
		}
		ouf.write((char*)(assignmentList[j]), size);
	}

	cout << "Writing " << assignmentList.size() << " Assignments.\n";
	writeCount(assignmentList.size());
}
void Feature::Assignment::read()
{
	int cur = readCount();
	totalAssignment = cur;
	//User user;
	int size = sizeof(Assignment);
	ifstream inf;
	inf.open("Assignment.DAT", ios::binary);
	if (!inf.is_open())
	{
		//cout << "\nCan't open file\n"; return;
		return;
	}
	int TotalAssignment = 0; // solution 1 : debug 2: store & retrieve
	for (int j = 0;j < cur;j++)
	{
		//cout << TotalCourse << endl;
		assignmentList.push_back(nullptr);
		assignmentList[TotalAssignment] = new Assignment;
		size = sizeof(Assignment);
		inf.read((char*)assignmentList[TotalAssignment], size);
		TotalAssignment++;
	}
	//cout << "Reading " << TotalCourse << " users\n";
}
void Feature::Assignment::writeCount(int count)
{
	//int prev = readCount();
	ofstream outfile("Assignment_count.txt", ios::trunc);
	outfile << count;
	cout << "\nFile Written\n";


}
int Feature::Assignment::readCount()
{
	int count;
	ifstream infile("Assignment_count.txt");

	if (!infile.is_open())
	{
		cerr << "Could not open the file\n";
		return 0;
	}

	infile >> count;
	//cout << count << endl;
	return count;
}
