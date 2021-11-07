#include "Program.h"
#include "LoginSystem.h"
#include "MainMenu.h"
using namespace std;

StateInfo::Program::Program()
{
	//cout << UserInfo::User::userList.size() << endl;
	//try
	//{
		data->currentUser = LoginInfo::loginSystem();
		data->machine.addState(stateRef(new MainMenu(this->data)), false);
	//}
	//catch (UserInfo::User::Empty)
	//{
		//cout << "Excepition: No user yet!";
	//}
	
}
