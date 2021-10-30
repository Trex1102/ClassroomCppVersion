#pragma once
#include <map>
#include <iostream>
#include <cassert>
#include "State.h"
#include "User.h"
#include "StateMachine.h"
#include "Course.h"
using namespace std;

namespace StateInfo
{
    struct ProgramData
    {
        StateMachine machine;
        UserInfo::User currentUser;
        CourseInfo::Course currentCourse;
    };

    typedef shared_ptr<StateInfo::ProgramData> ProgramDataRef;

    class Program
    {
    public:
        Program();

    private:
        ProgramDataRef data = make_shared<ProgramData>();
    };
}