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
    /*struct ProgramData
    {
        StateMachine machine;
        UserInfo::User currentUser;
    };

    typedef shared_ptr<StateInfo::ProgramData> ProgramDataRef; // making shared pointer of the data*/

    struct ProgData
    {
        UserInfo::User currentUser;
    };
    typedef shared_ptr<ProgData> ProgDataRef;

    class Program
    {
    public:
        Program(ProgDataRef data);

    private:
        ProgDataRef data; //

    };
}