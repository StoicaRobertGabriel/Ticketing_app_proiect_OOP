#include "Event.h"

using namespace std;

Event::Event()
{
	eventName = "no name";
	eventDate = "no date";
	eventDuration = "0 hours / 0 minutes";
	eventType = "any";
}

Event::Event(string eventName, string eventDate, string eventDuration, string eventType)
{
	this->eventName = eventName;
	this->eventDate = eventDate;
	this->eventDuration = eventDuration;
	this->eventType = eventType;
}

Event::Event(const Event& e)
{
	this->eventName = e.eventName;
	this->eventDate = e.eventDate;
	this->eventDuration = e.eventDuration;
	this->eventType = e.eventType;
}

Event::~Event()
{
}

string Event::getEventName()
{
	return eventName;
}

ostream& operator<<(ostream& out, Event e) //show to console
{
	out << "EVENT INFORMATION:" << endl;
	out << "Event's name: " << e.eventName << endl;
	out << "Event's date: " << e.eventDate << endl;
	out << "Event's duration: " << e.eventDuration << endl;
	out << "Event's type: " << e.eventType << endl;
	out << endl;
	return out;
}

ofstream& operator<<(ofstream& f, Event e) //write to file
{
	//f << "EVENT INFORMATION:" << endl;
	//f << "Event's name: "
	f << e.eventName << endl;
	//f << "Event's date: "
	f << e.eventDate << endl;
	//f << "Event's duration: "
	f << e.eventDuration << endl;
	//f << "Event's type: "
	f << e.eventType << endl;
	f << "@" << endl;
	return f;
}

istream& operator>>(istream& in, Event& e) //write in console
{
	cout << "EVENT INFORMATION:" << endl;
	cout << "Event's name: ";
	in >> ws;
	getline(in, e.eventName);
	cout << "Event's date: ";
	in >> ws;
	getline(in, e.eventDate);
	cout << "Event's duration: ";
	in >> ws;
	getline(in, e.eventDuration);
	cout << "Event's type: ";
	in >> ws;
	getline(in, e.eventType);
	return in;
}