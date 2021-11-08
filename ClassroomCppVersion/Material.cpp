#include "Material.h"

vector<Feature::Material*> Feature::Material::materialList;
int Feature::Material::totalMaterials;

void Feature::Material::Display()
{
    cout << "Course Materials: " << endl;
	for(const auto it:materials)
	{
		cout << "Concept: " << it.first << endl;
		cout << "Link: " << it.second << endl;
	}
}

string Feature::Material::getInputTime() const
{
    return inputTime;
}

void Feature::Material::setInputTime(string inputTime)
{
    this->inputTime = inputTime;
}

UserInfo::User* Feature::Material::getUploaderTeacher() const
{
    //return uploaderTeacher;
}

void Feature::Material::setUploaderTeacher(UserInfo::User* uploaderTeacher)
{
    //this->uploaderTeacher = uploaderTeacher;
}

CourseInfo::Course* Feature::Material::getLinkedCourse() const
{
    //return linkedCourse;
}

void Feature::Material::setLinkedCourse(CourseInfo::Course* linkedCourse)
{
    //this->linkedCourse = linkedCourse;
}

void Feature::Material::write()
{

	//int n = userList.size();

	ofstream ouf;
	//User user;
	int size = sizeof(Material);
	ouf.open("Database0/Material.DAT", ios::trunc | ios::binary);
	if (!ouf)
	{
		//cout << "\nCan't open file\n";
		return;
	}
	for (unsigned j = 0; j < materialList.size(); j++)
	{
		//ouf.write((char*)&User, sizeof(User));
		if (!ouf)
		{
			//cout << "\nCan't write to file\n";
			return;
		}
		ouf.write((char*)(materialList[j]), size);
	}

	//cout << "Writing " << materialList.size() << " materials.\n";
	writeCount(materialList.size());
}
void Feature::Material::read()
{
	int cur = readCount();
	totalMaterials = cur;
	//User user;
	int size = sizeof(Material);
	ifstream inf;
	inf.open("Database0/Material.DAT", ios::binary);
	if (!inf.is_open())
	{
		//cout << "\nCan't open file\n"; return;
		return;
	}
	int Total = 0; // solution 1 : debug 2: store & retrieve
	for (int j = 0;j < cur;j++)
	{
		try
		{
			//cout << TotalCourse << endl;
			materialList.push_back(nullptr);
			materialList[Total] = new Material;//no cons
			size = sizeof(Material);
			inf.read((char*)materialList[Total], size);
			Total++;
		}
		catch (bad_alloc)
		{
			cout << "Can't allocate Material" << endl;
		}
	}
	//cout << "Reading " << TotalCourse << " users\n";
}
void Feature::Material::writeCount(int count)
{
	//int prev = readCount();
	ofstream outfile("Database0/Material_Count.txt", ios::trunc);
	outfile << count;
	//cout << "\nFile Written\n";


}
int Feature::Material::readCount()
{
	int count;
	ifstream infile("Database0/Material_Count.txt");

	if (!infile.is_open())
	{
		//cerr << "Could not open the file\n";
		return 0;
	}

	infile >> count;
	//cout << count << endl;
	return count;
}
