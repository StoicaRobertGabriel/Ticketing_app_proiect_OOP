#include "Ticket.h"

Ticket::Ticket() :ID(nullptr)
{
	price = 0;
	curencyType = "RON";
	//event = 0;
}

Ticket::Ticket(char* ID, unsigned short price, string curencyType, Event event)
{
	this->price = price;
	this->curencyType = curencyType;
	//this->event=event;
	//algorit ID
}