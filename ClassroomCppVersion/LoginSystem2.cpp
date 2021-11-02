#include "LoginSystem.h"
#include <fstream>

UserInfo::User LoginInfo::loginSystem2()
{
	UserInfo::User::read();
	string choice;
	int ch;
	string username, password;
	cout << "Welcome to Classroom CPP beta" << endl;
	while (true) {
		cout << "If you have existing account type #signin otherwise to create new account type #signup" << endl;
		cin >> choice;
		if (choice == "#signin")
		{
			cout << "Total Users: " << UserInfo::User::TotalUser << endl;
			cout << "Username: ";
			cin >> username;
			cout << "Password: ";
			cin >> password;
			for (const auto it : UserInfo::User::userList)
			{
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
				exit(0);
			}
		}
		else
		{
			int n;
			auto user=new UserInfo::User;
			UserInfo::User::createUser(*user);
			UserInfo::User::userList.push_back(user);
			cout << "\n1.Exit?" << endl;
			int c;cin >> c;
			if (c == 1)
			{
				UserInfo::User::write();
				
				//UserInfo::User::display();
				return *user;
			}

		    //return user;
		}
	}

}
