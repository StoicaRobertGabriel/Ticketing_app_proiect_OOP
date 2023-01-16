#include "Ticket.h"

Ticket::Ticket()
{
	ID = nullptr;
	curencyType = "n/a";
	price = 0.0;
	eventName = "no event";
	venueName = "no venue";
}

Ticket::Ticket(const char* ID, string curencyType, float price, string eventName, string venueName)
{
	if (ID != nullptr)
	{
		this->ID = new char[strlen(ID) + 1];
		strcpy_s(this->ID, strlen(ID) + 1, ID);
	}
	else
	{
		this->ID = nullptr;
	}
	this->curencyType = curencyType;
	this->price = price;
	this->eventName = eventName;
	this->venueName = venueName;
}

Ticket::Ticket(const Ticket& t)
{
	if (t.ID != nullptr)
	{
		ID = new char[strlen(t.ID) + 1];
		strcpy_s(ID, strlen(t.ID) + 1, t.ID);
	}
	else
	{
		ID = nullptr;
	}
	curencyType = t.curencyType;
	price = t.price;
	eventName = t.eventName;
	venueName = t.venueName;
}

Ticket::~Ticket()
{
	if (this->ID != nullptr)
	{
		delete[]this->ID;
	}
}

ofstream& operator<<(ofstream& f, Ticket t) //write to file
{
	float IDlength = strlen(t.ID);
	f.write((char*)&IDlength, sizeof(IDlength));
	f.write((char*)&t.ID, strlen(t.ID) + 1);
	return f;
}

istream& operator>>(istream& in, Ticket& t) //write in console
{
	cout << "TICKET INFORMATION:" << endl;
	delete[]t.ID;
	t.ID = nullptr;
	srand((unsigned)time(NULL));
	int randomIDint = rand();
	string temp_str = to_string(randomIDint);
	char const* number_array = temp_str.c_str();
	t.ID = new char[strlen(number_array) + 1];
	strcpy_s(t.ID, strlen(number_array) + 1, number_array);
	cout << "Ticket's ID: " << t.ID << endl;
	cout << "What curency is the ticket's price in? (ex: USD, euros, bananas)" << endl;
	cout << "Your input: ";
	in >> ws;
	getline(in, t.curencyType);
	cout << "What is the price of the ticket?" << endl;
	cout << "Your input: ";
	in >> ws;
	in >> t.price;
	return in;
}