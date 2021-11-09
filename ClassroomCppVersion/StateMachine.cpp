#include "StateMachine.h"
using namespace std;

void StateInfo::StateMachine::addState(stateRef newstate, bool isReplacing)
{
	this->isAdding = true;
	this->isReplacing = isReplacing;
	this->newState = move(newstate);
	processStateChanges();
}

void StateInfo::StateMachine::removeState()
{
	this->isRemoving = true;
	processStateChanges();
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
		states.top()->Init();
		return;
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
	}
}

StateInfo::stateRef& StateInfo::StateMachine::getActiveState()
{
	if (states.empty())
	{
		throw EmptyStack();
	}
	return states.top();
}


