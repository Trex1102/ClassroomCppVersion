#pragma once
#include <string>
#include <iostream>
#include <map>
#include <vector>
#include "Attendance.h"
#include "State.h"
#include "Program.h"
#include "LoginSystem.h"
#include "Database.h"

namespace StateInfo
{
	class AddPostState :public State
	{
	private:
		ProgramDataRef data;

	public:

		AddPostState(ProgramDataRef data);

		void Init() override;
		void HandleInput() override;
		void Pause() override;
		void Resume() override;
		void Display() override;
	};
}