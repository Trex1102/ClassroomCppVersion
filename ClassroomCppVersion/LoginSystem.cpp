#include "LoginSystem.h"
#include <fstream>

long byteNum(int num)
{
	return sizeof(UserInfo::User) * num;
}
UserInfo::User LoginInfo::loginSystem()
{
	cout << UserInfo::User::TotalUser << endl;
	string choice;
	int ch;
	string username,password;
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
			UserInfo::User user;
			int pos;
			ifstream infile;
			infile.open("User.DAT", ios::binary);
			infile.seekg(0);
			//User user;
			while (!infile.eof())
			{
				pos = infile.tellg();
				infile.read((char*)&user, sizeof(user));
				if (user.getUsername() == username)
				{
					if (user.getPassword() == password)
					{
						cout << "Login Successfull" << endl;
						infile.seekg(pos);
						return user;
					}
					else
					{
						cout << "Password doesn't match" << endl;

						cout << "Try again? - #1.yes" << " Exit - #2.exit" << endl;
						cin >> ch;
						if (ch == 1) continue;
						else
						{
							exit(0);
						}
					}
					}
				}
				/*
				else
				{
					cout << "No user found" << endl;
				}
				cout << "Username or Password is incorrect" << endl;*/
				
			//UserInfo::User::FindUser(username, password);
			/*int number = 0;
			fstream datafile;
			datafile.open("User.DAT", ios::in | ios::binary);

			cout << "Total Users: " << UserInfo::User::TotalUser << endl;
			cout << "Username: ";
			cin >> username;
			cout << "Password: ";
			cin >> password;
			UserInfo::User user;
			while (!datafile.eof())
			{
				datafile.seekg(byteNum(number), ios::beg);
				datafile.read(reinterpret_cast<char*>(&user), sizeof(user));
				if (user.getUsername() == username)
				{
					if (user.getPassword() == password)
					{
						cout << "Login Successful" << endl;
						return user;
					}

				}

				number++;

			}
			datafile.close();*/
			/*for (const auto it : UserInfo::User::userList)
			{
				if (it->getUsername() == username)
				{
					if (it->getPassword() == password)
					{
						cout << "Login Successful" << endl;
						return *it;
					}
				}
			}*/
			
		}
		else
		{
			int n;
			UserInfo::User	user;
			UserInfo::User::createUser(user);
			user.User_diskout();
			n = UserInfo::User::User_diskcount();
			cout << n << endl;
			cout << UserInfo::User::TotalUser << endl;
			for (int j = 0;j < n;j++)
			{
				cout << "\nUser " << j << " ";
				user.User_diskin(j);
				user.displayInfo();
			}
			cout << endl;
			//user.User_diskin(n-1);
			//user.displayInfo();
			return user;
		}
	}
	
}
