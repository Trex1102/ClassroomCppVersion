#pragma once
#include <string>
#include <iostream>
#include <map>
#include <vector>
#include "CourseMaterials.h"
#include "Attendance.h"
#include "State.h"
#include "Program.h"
#include "DummyState.h"
using namespace std;

namespace StateInfo
{
	class MainMenu:public State
	{
	private:
		shared_ptr<UserInfo::User>currentUser = make_shared<UserInfo::User>();
		
	public:
		
		MainMenu(shared_ptr<UserInfo::User> currentUser);
		void Init() override;
		void HandleInput() override;
		void Pause() override;
		void Resume() override;
		void Display() override;
		
	};
}
