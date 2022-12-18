#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Event
{
private:
	string eventName;
	string eventDate;
	string eventDuration;
	string eventType;
public:
	Event();
	Event(string eventName, string eventDate, string duartion, string eventType);
	Event(const Event& e);
	~Event();
	string getEventName();
	friend ostream& operator<<(ostream& out, Event e);
	friend ofstream& operator<<(ofstream& f, Event e);
	friend istream& operator>>(istream& in, Event& e);
};

ostream& operator<<(ostream& out, Event e);
ofstream& operator<<(ofstream& f, Event e);
istream& operator>>(istream& in, Event& e);
