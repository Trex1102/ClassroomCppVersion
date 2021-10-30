#pragma once
#include "User.h"
#include "StateMachine.h"

namespace StateInfo
{

	class State
	{
	public:
		virtual void Init() = 0; // take essentials inputs of that state && show
		virtual void HandleInput() = 0; // handel inputfor different methods
		virtual void Pause()  = 0; // save essential datas
		virtual void Resume()  = 0; // load essesntial datas
		virtual void Display() = 0;
		//virtual ~State() = 0;
	};
}
