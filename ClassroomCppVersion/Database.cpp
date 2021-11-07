#include "Database.h"

void Database::writeCount(int count, string filename)
{
	ofstream outfile(filename, ios::trunc);
	outfile << count;
}

int Database::readCount(string filename)
{
	int count;
	ifstream infile(filename);

	if (!infile.is_open())
	{
		return 0;
	}

	infile >> count;
	return count;
}

int Database::Relations::CourseStudentcount;
int Database::Relations::CoursePostcount;
int Database::Relations::CourseAssignmentcount;
int Database::Relations::CourseTeachercount;
map<string, vector<string>> Database::Relations::CourseTeacher;
map<string, vector<string>>Database::Relations::CourseStudent;
map<string, vector<string>>Database::Relations::CoursePost;
map<string, vector<string>>Database::Relations::CourseAssignment;

void Database::Relations::write()
{
	string filename1 = "CourseStudentcount.txt";
	string filename2;
	ofstream ouf;
	int size = 30;
	ouf.open("Database/db2.DAT", ios::trunc | ios::binary);
	if (!ouf)
	{
		cout << "\nCan't open file\n";
		return;
	}
	int i = 0;

	for (auto it : Database::Relations::CourseStudent)
	{
		i++;
		const char* a, * b;
		a = &it.first[0];
		if (!ouf)
		{
			cout << "\nCan't write to file\n";
			return;
		}
		ouf.write((char*)(a), size);
		int j = 0;
		for (auto i : it.second)
		{
			j++;
			b = &i[0];
			ouf.write((char*)(b), size);

		}
		filename2 = "Database/" + to_string(i) + filename1;
		writeCount(j, filename2);
	}
	writeCount(i, "Database/" + filename1);


	///////////////////////////////////////////////////////

	filename1 = "CourseTeachercount.txt";
	filename2;
	size = 30;
	if (!ouf)
	{
		cout << "\nCan't open file\n";
		return;
	}
	i = 0;

	for (auto it : Database::Relations::CourseTeacher)
	{
		i++;
		const char* a, * b;
		a = &it.first[0];
		if (!ouf)
		{
			cout << "\nCan't write to file\n";
			return;
		}
		ouf.write((char*)(a), size);
		int j = 0;
		for (auto i : it.second)
		{
			j++;
			b = &i[0];
			ouf.write((char*)(b), size);

		}
		filename2 = "Database/" + to_string(i) + filename1;
		writeCount(j, filename2);
	}
	writeCount(i, "Database/" + filename1);

	///////////////////////////////////////////////////////

	filename1 = "CoursePostcount.txt";
	filename2;
	size = 30;
	if (!ouf)
	{
		cout << "\nCan't open file\n";
		return;
	}
	i = 0;

	for (auto it : Database::Relations::CoursePost)
	{
		i++;
		const char* a, * b;
		a = &it.first[0];
		if (!ouf)
		{
			cout << "\nCan't write to file\n";
			return;
		}
		ouf.write((char*)(a), size);
		int j = 0;
		for (auto i : it.second)
		{
			j++;
			b = &i[0];
			ouf.write((char*)(b), size);

		}
		filename2 = "Database/" + to_string(i) + filename1;
		writeCount(j, filename2);
	}
	writeCount(i, "Database/" + filename1);

	////////////////////////////////////////////////

	filename1 = "CourseAssignmentcount.txt";
	filename2;
	size = 30;
	if (!ouf)
	{
		cout << "\nCan't open file\n";
		return;
	}
	i = 0;

	for (auto it : Database::Relations::CourseAssignment)
	{
		i++;
		const char* a, * b;
		a = &it.first[0];
		if (!ouf)
		{
			cout << "\nCan't write to file\n";
			return;
		}
		ouf.write((char*)(a), size); // writing the key
		int j = 0;
		for (auto i : it.second)
		{
			j++;
			b = &i[0];
			ouf.write((char*)(b), size); // writing the values

		}
		filename2 = "Database/" + to_string(i) + filename1;
		writeCount(j, filename2);
	}
	writeCount(i, "Database/" + filename1);
}
void Database::Relations::read()
{
	string filename1;
	string filename2;
	int keycount;
	int count;

	filename1 = "CourseStudentcount.txt";

	int size = 30;
	char a[30], b[30];
	ifstream inf;
	inf.open("Database/db2.DAT", ios::binary);
	if (!inf.is_open())
	{
		cout << "\nCan't open file\n"; return;
		return;
	}

	keycount = readCount("Database/" + filename1);

	for (int i = 1; i <= keycount; i++)
	{
		filename2 = "Database/" + to_string(i) + filename1;
		count = readCount(filename2); // read every loop --> count of total values of that key
		inf.read((char*)a, size);
		string c(a);
		for (int j = 0; j < count; j++) {
			inf.read((char*)b, size);
			string d(b);
			Database::Relations::CourseStudent[c].push_back(d);
		}
	}

	filename1 = "CourseTeachercount.txt";
	keycount = readCount("Database/" + filename1);

	for (int i = 1; i <= keycount; i++)
	{
		filename2 = "Database/" + to_string(i) + filename1;
		count = readCount(filename2); // read every loop --> count of total values of that key
		inf.read((char*)a, size);
		string c(a);
		for (int j = 0; j < count; j++) {
			inf.read((char*)b, size);
			string d(b);
			Database::Relations::CourseTeacher[c].push_back(d);
		}
	}

	filename1 = "CoursePostcount.txt";
	keycount = readCount("Database/" + filename1);

	for (int i = 1; i <= keycount; i++)
	{
		filename2 = "Database/" + to_string(i) + filename1;
		count = readCount(filename2); // read every loop --> count of total values of that key
		inf.read((char*)a, size);
		string c(a);
		for (int j = 0; j < count; j++) {
			inf.read((char*)b, size);
			string d(b);
			Database::Relations::CoursePost[c].push_back(d);
		}
	}

	filename1 = "CourseAssignmentcount.txt";
	keycount = readCount("Database/" + filename1);

	for (int i = 1; i <= keycount; i++)
	{
		filename2 = "Database/" + to_string(i) + filename1;
		count = readCount(filename2); // read every loop --> count of total values of that key
		inf.read((char*)a, size);
		string c(a);
		for (int j = 0; j < count; j++) {
			inf.read((char*)b, size);
			string d(b);
			Database::Relations::CourseAssignment[c].push_back(d);
		}
	}
}

void Database::Relations::display()
{
	cout << "CourseStudent: \n";
	for (auto i : Database::Relations::CourseStudent) {

		for (auto it : i.second)
		{
			cout << "Key: " << i.first << endl << "Value: " << it << endl;
		}
	}
	cout << "Course Post: \n";
	for (auto i : Database::Relations::CoursePost) {

		for (auto it : i.second)
		{
			cout << "Key: " << i.first << endl << "Value: " << it << endl;
		}
	}

	cout << "Course Assignment: \n";
	for (auto i : Database::Relations::CourseAssignment) {

		for (auto it : i.second)
		{
			cout << "Key: " << i.first << endl << "Value: " << it << endl;
		}
	}

}