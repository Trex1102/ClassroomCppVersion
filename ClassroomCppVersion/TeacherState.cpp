﻿#include "TeacherState.h"
using namespace std;

void StateInfo::TeacherState::displayCourseState()
{
	StateInfo::courseState::displayCourseState();
	cout	<< "Commands: " << endl
			<<"To add student #addstu" << endl
			<< "To add Course Materials #addmat" << endl
			<< "To add Course Outline #addout" << endl
			<< "To add assignment #addassign" << endl
			<< "To add Short Notes #addsnotes" << endl
			<< "To see course participants type #coursepar" << endl;

}
