#pragma once
#include <memory>
#include <stack>
#include "State.h"
using namespace std;

namespace StateInfo
{
	typedef  unique_ptr<State> stateRef;

	class StateMachine
	{

	private:
		stack<stateRef> states; // 
		stateRef newState;
		bool isRemoving, isAdding, isReplacing;
	public:
		StateMachine(){}
		~StateMachine(){}

		void addState(stateRef newstate, bool isReplacing = true);
		void removeState();
		void processStateChanges();
		stateRef& getActiveState();

	};

}