#pragma once
#include "Event.h"

class Object {
public:
	Object(void);
	virtual ~Object(void);
	virtual void Show() = 0;
	virtual void Input() = 0;
	virtual void HandleEvent(TEvent& event) = 0;
};
