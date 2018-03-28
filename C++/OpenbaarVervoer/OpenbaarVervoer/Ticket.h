#pragma once
#include <string>
class Ticket
{
public:
	Ticket();
	~Ticket();

	virtual bool allowance() = 0;

};

