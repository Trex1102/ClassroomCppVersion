#pragma once
#include <string>
#include <iostream>
#include <map>
#include <vector>

#include "Attendance.h"
#include "State.h"
#include "Program.h"
#include "LoginSystem.h"
#include "seepostState.h"
using namespace std;

namespace StateInfo
{
	class StudentState :public State
	{
	private:
		ProgramDataRef data;

	public:

		StudentState(ProgramDataRef data);

		void Init() override;
		void HandleInput() override;
		void Pause() override;
		void Resume() override;
		void Display() override;
	};
}