#include "Program.h"
#include "LoginSystem.h"
#include "MainMenu.h"
using namespace std;

StateInfo::Program::Program()
{
	data->currentUser = LoginInfo::loginSystem();
	  data->machine.addState(stateRef(new MainMenu(this->data)));
}
