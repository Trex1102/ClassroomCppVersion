#include "StateMachine.h"
using namespace std;

void StateInfo::StateMachine::addState(stateRef newstate, bool isReplacing)
{
	this->isAdding = true;
	this->isReplacing = isReplacing;
	this->newState = move(newstate);
}

void StateInfo::StateMachine::removeState()
{
	this->isRemoving = true;
}

void StateInfo::StateMachine::processStateChanges()
{
	if(isRemoving && !states.empty())
	{
		states.top()->Pause();
		states.pop();
		if(!states.empty())
		{
			states.top()->Resume();
		}
		isRemoving = false;
	}

	if(isAdding)
	{
		if(!states.empty())
		{
			if(isReplacing)
			{
				states.top()->Pause();
				states.pop();
			}
			else
			{
				states.top()->Pause();
			}
		}
		states.push(move(newState));
		isAdding = false;
		states.top()->Init();
		states.top()->Display();
	}
}

StateInfo::stateRef& StateInfo::StateMachine::getActiveState()
{
	return states.top();
}


