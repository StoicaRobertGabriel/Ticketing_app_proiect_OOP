#pragma once
#include <string>
#include "Event.h"

using namespace std;

class Ticket
{
private:
	char* ID;
	string curencyType;
	float price;
	string eventName;
	string venueName;
public:
	Ticket();
	Ticket(const char* ID, string curencyType, float price, string eventName, string venueName);
	Ticket(const Ticket& t);
	~Ticket();
	friend ofstream& operator<<(ofstream& f, Ticket t);
	friend istream& operator>>(istream& in, Ticket& t);
};

ofstream& operator<<(ofstream& f, Ticket t);
istream& operator>>(istream& in, Ticket& t);