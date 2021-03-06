#pragma once
#include <string>
#include <iostream>
#include <map>
#include <vector>
//#include "CourseMaterials.h"
#include "Attendance.h"
#include "State.h"
#include "Program.h"
#include "LoginSystem.h"

namespace StateInfo
{
	class seepostState :public State
	{
	private:
		ProgramDataRef data;

	public:

		seepostState(ProgramDataRef data);

		void Init() override;
		void HandleInput() override;
		void Pause() override;
		void Resume() override;
		void Display() override;
	};
}