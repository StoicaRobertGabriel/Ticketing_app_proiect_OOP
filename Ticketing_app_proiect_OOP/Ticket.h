#pragma once
#include <string>
#include "Event.h"

using namespace std;

class Ticket
{
private:
	const char* ID;
	unsigned short price;
	string curencyType;
	Event event;
public:
	Ticket();
	Ticket(char* ID, unsigned short price, string curencyType, Event event);
	Ticket(const Ticket& t);
	~Ticket();
};