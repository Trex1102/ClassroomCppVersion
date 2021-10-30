/*#pragma once
#include <memory>
#include <stack>
#include "State.h"
using namespace std;

namespace StateInfo
{
	class StateMachine
	{
	private:
		stack<State*> states; 
		State* newState = nullptr;
		bool isRemoving, isAdding, isReplacing;
	public:
		StateMachine() = default;
		~StateMachine() = default;

		void addState(State* newstate, bool isReplacing = true);
		void removeState();
		void processStateChanges();
		State* getActiveState();

	};

}*/