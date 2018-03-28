#pragma once
#include "Ticket.h"
class TicketWithAllowance :
	public Ticket
{
public:
	TicketWithAllowance();
	~TicketWithAllowance();

	bool allowance();
};
