#pragma once


class Component{


public:
	bool active = false;

	bool isActive()
	{
		return active;
	}

	bool setActive(bool b)
	{
		return active = b;
	}
};