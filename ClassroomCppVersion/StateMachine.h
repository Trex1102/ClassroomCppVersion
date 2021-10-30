#pragma once
#include <memory>
#include <stack>

#include "State.h"
using namespace std;

namespace StateInfo
{
	class State;
	typedef  unique_ptr<State> stateRef; // unique pointer to state

	class StateMachine
	{

	private:
		stack<stateRef> states; // 
		stateRef newState;
		bool isRemoving, isAdding, isReplacing;
	public:
		StateMachine() = default;
		~StateMachine() = default;

		void addState(stateRef newstate, bool isReplacing = true);
		void removeState();
		void processStateChanges();
		stateRef& getActiveState();

	};

}