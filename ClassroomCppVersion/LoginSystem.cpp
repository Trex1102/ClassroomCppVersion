#include "LoginSystem.h"

UserInfo::User LoginInfo::loginSystem()
{
	Database::Relations::read();
	//Database::Relations::display();
	//Database::input();
	//Database::Relations::write();


	//////////

	//Database0::read();
	UserInfo::User::read();
	CourseInfo::Course::read();
	Feature::Assignment::read();
	Feature::Post::read();
	Feature::Material::read();
	CourseInfo::attendance::read();
	//cout<<"Count: "<<UserInfo::User::readCount() << endl;
	string choice;
	string username,password;

	/*for (auto it : UserInfo::User::userList)
	{
		cout << "UserName: " << it->getUsername() << endl;
	}*/

	cout << "Welcome to Classroom CPP beta" << endl;
	while (true) {
		cout << "If you have existing account type #signin otherwise to create new account type #signup" << endl;
		cin >> choice;
		if (choice == "#signin")
		{
			//cout << "Total Users: " << UserInfo::User::userID << endl;
			cout << "Total Users: " << UserInfo::User::userList.size() << endl;
			cout << "Username: ";
			cin >> username;
			cout << "Password: ";
			cin >> password;
			for (auto it : UserInfo::User::userList)
			{
				cout << "UserName: " << it->getUsername() << endl;
				if (it->getUsername() == username)
				{
					if (it->getPassword() == password)
					{
						cout << "Login Successful" << endl;
						return *it;
					}
				}
			}

			cout << "Username or Password is incorrect" << endl;
			cout << "Try again? - #yes" << " Exit - #exit" << endl;
			cin >> choice;
			if (choice == "#yes") continue;
			else
			{
				//Database0::write();
				UserInfo::User::write();
				CourseInfo::Course::write();
				Feature::Assignment::write();
				Feature::Post::write();

				Feature::Material::write();
				CourseInfo::attendance::write();
				exit(0);
			}
		}
		else
		{
			auto user = new UserInfo::User;
			UserInfo::User::createUser(*user);
			UserInfo::User::userID++;
			UserInfo::User::userList.push_back(user);
			//UserInfo::User::write(); // write after exit
			return *user;
		}
	}
}
