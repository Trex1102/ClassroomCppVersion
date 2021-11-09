// ClassroomCppVersion.cpp : This file contains the 'main' function. Program execution begins and ends there.


#include <iostream>
#include "User.h"
#include "Course.h"
#include "Attendance.h"
#include "LoginSystem.h"
#include "StateMachine.h"
#include "Program.h"
#include "Assignment.h"
using namespace std;

int main()
{
    try 
    {
        StateInfo::Program mainProgram;
    }
    catch (StateInfo::nullProgramRef e)
    {
        cout << "Dataref faka"<<endl;
    }
    catch (StateInfo::StateMachine::EmptyStack e)
    {
        cout << "Stack Empty" << endl;
    }

}
