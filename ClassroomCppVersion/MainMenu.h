#pragma once
#include <string>
#include <iostream>
#include <map>
#include <vector>
#include "CourseMaterials.h"
#include "Attendance.h"
#include "State.h"
#include "Program.h"
using namespace std;

namespace StateInfo
{
	class MainMenu:public State
	{
	private:
		ProgramDataRef data;
		
	public:

		MainMenu(ProgramDataRef data);

		void Init() override;
		void HandleInput() override;
		void Pause() override;
		void Resume() override;
		void Display() override;

		//~MainMenu () override = default;
	};
}
