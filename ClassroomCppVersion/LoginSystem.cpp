#include "LoginSystem.h"

UserInfo::User LoginInfo::loginSystem()
{
	string choice;
	string username,password;
	cout << "Welcome to Classroom CPP beta" << endl;
	while (true) {
		cout << "If you have existing account type #signin otherwise to create new account type #signup" << endl;
		cin >> choice;
		if (choice == "#signin")
		{
			cout << "Total Users: " << UserInfo::User::userID << endl;
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
			UserInfo::User	user;
			UserInfo::User::createUser(user);
			return user;
		}
	}
}
