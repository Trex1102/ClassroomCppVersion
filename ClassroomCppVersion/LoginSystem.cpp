#include "LoginSystem.h"

UserInfo::User* currentUser;
void LoginInfo::loginSystem()
{
	int choice;
	string username,password;
	cout << "Welcome to Classroom CPP Version beta 1.00001" << endl;
	while (true) {
		cout << "If you have existing account press 1 otherwise to create new account press 2" << endl;
		cin >> choice;
		if (choice == 1)
		{
			cout << "Username: ";
			cin >> username;
			cout << "Password: ";
			cin >> password;
			for (auto it : UserInfo::User::userList)
			{
				if (it->getName() == username)
				{
					if (it->getPassword() == password)
					{
						cout << "Login Successful" << endl;
						currentUser = it;
						return; // do next things
					}
				}
			}
			cout << "Username or Password is incorrect" << endl;
			cout << "Try again? - Press 1" << " Exit - Press 2" << endl;
			cin >> choice;
			if (choice == 1) continue;
			else break; // exit the program
		}
		else
		{
			cout << "Creating Account" << endl;
			cout << "Input Username: " << endl;
			cin >> username;
			cout << "Password: " << endl;
			cin >> password;
		}
	}
}
