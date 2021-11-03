#include "Post.h"
#include<fstream>
using namespace std;
int Feature::Post::totalPosts;
vector<Feature::Post*> Feature::Post::postList;

void Feature::Post::write()
{

	//int n = userList.size();

	ofstream ouf;
	//User user;
	int size = sizeof(Post);
	ouf.open("Post.DAT", ios::trunc | ios::binary);
	if (!ouf)
	{
		cout << "\nCan't open file\n";
		return;
	}
	for (int j = 0; j < postList.size(); j++)
	{
		//ouf.write((char*)&User, sizeof(User));
		if (!ouf)
		{
			cout << "\nCan't write to file\n";
			return;
		}
		ouf.write((char*)(postList[j]), size);
	}

	cout << "Writing " << postList.size() << " posts.\n";
	write_PostCount(postList.size());
}
void Feature::Post::read()
{
	int cur = read_PostCount();
	totalPosts = cur;
	//User user;
	int size = sizeof(Post);
	ifstream inf;
	inf.open("Post.DAT", ios::binary);
	if (!inf.is_open())
	{
		//cout << "\nCan't open file\n"; return;
		return;
	}
	int TotalPost = 0; // solution 1 : debug 2: store & retrieve
	for (int j = 0;j < cur;j++)
	{
		//cout << TotalCourse << endl;
		postList.push_back(nullptr);
		postList[TotalPost] = new Post;
		size = sizeof(Post);
		inf.read((char*)postList[TotalPost], size);
		TotalPost++;
	}
	//cout << "Reading " << TotalCourse << " users\n";
}
void Feature::Post::write_PostCount(int count)
{
	//int prev = readCount();
	ofstream outfile("Post_Count.txt", ios::trunc);
	outfile << count;
	cout << "\nFile Written\n";


}
int Feature::Post::read_PostCount()
{
	int count;
	ifstream infile("Post_Count.txt");

	if (!infile.is_open())
	{
		cerr << "Could not open the file\n";
		return 0;
	}

	infile >> count;
	//cout << count << endl;
	return count;
}