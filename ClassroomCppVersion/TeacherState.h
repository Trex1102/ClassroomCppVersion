#pragma once
#include <string>
#include <iostream>
#include <map>
#include <vector>
#include "AddMaterialState.h"
#include "Material.h"
#include "Attendance.h"
#include "State.h"
#include "Program.h"
#include "LoginSystem.h"
#include "AddStudentState.h"
#include "AddPostState.h"
#include "AddAssignmentState.h"
using namespace std;

namespace StateInfo
{
	class TeacherState :public State
	{
	private:
		ProgramDataRef data;

	public:

		TeacherState(ProgramDataRef data);

		void Init() override;
		void HandleInput() override;
		void Pause() override;
		void Resume() override;
		void Display() override;
	};
}