#pragma once
#include "Ticket.h"
class TicketNoAllowance :
	public Ticket
{
public:
	TicketNoAllowance();
	~TicketNoAllowance();

	bool allowance();
};

