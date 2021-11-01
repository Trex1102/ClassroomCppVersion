/*#pragma once
#include <string>
#include <iostream>
#include <map>
#include <vector>
#include "CourseMaterials.h"
#include "Attendance.h"
#include "State.h"
#include "Program.h"
#include "LoginSystem.h"
using namespace std;
namespace CourseInfo
{
	class CourseMaterials;
}

namespace StateInfo
{

	class AddMaterialState: public State
	{
	private:
		ProgramDataRef data;
		CourseInfo::CourseMaterials* coursematerials;
	public:

		AddMaterialState(ProgramDataRef data);

		void Init() override;
		void HandleInput() override;
		void Pause() override;
		void Resume() override;
		void Display() override;


	};
}*/