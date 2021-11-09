#pragma once
#include <string>
#include <iostream>
#include <map>
#include <vector>
#include "Attendance.h"
#include "State.h"
#include "Program.h"
#include "LoginSystem.h"

namespace StateInfo
{
	class AddAssignmentState :public State
	{
	private:
		ProgramDataRef data;

	public:

		AddAssignmentState(ProgramDataRef data);

		void Init() override;
		void HandleInput() override;
		void Pause() override;
		void Resume() override;
		void Display() override;
	};
}