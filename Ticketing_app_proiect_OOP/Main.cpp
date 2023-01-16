#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include "Event.h"
#include "Venue.h"
#include "Zone.h"
#include "Ticket.h"

using namespace std;

int main()
{
	cout << "Welcome to the ticket app!" << endl;
	cout << endl << "Enter value <0> to stop" << endl;
	cout << "Enter value <1> to add a new event" << endl;
	cout << "Enter value <2> to look up an event" << endl;
	cout << "Enter value <3> to add a new venue" << endl;
	cout << "Enter value <4> to look up a venue" << endl;
	cout << "Enter value <5> to buy a new ticket" << endl;
	cout << "Enter value <6> to verify a ticket's purchase" << endl;
	bool b = 1;
	int command = -1;
	while (b == 1)
	{
		cout << endl << "What do you want to do now? (enter <11> for help)" << endl;
		cout << endl << "Your command is: ";
		cin >> command;
		switch (command)
		{
		case 0:
		{
			b = 0;
			break;
		}
		case 11:
		{
			cout << "Enter value <0> to stop" << endl;
			cout << "Enter value <1> to add a new event" << endl;
			cout << "Enter value <2> to look up an event" << endl;
			cout << "Enter value <3> to add a new venue" << endl;
			cout << "Enter value <4> to look up a venue" << endl;
			cout << "Enter value <5> to buy a new ticket" << endl;
			cout << "Enter value <6> to verify a ticket's purchase" << endl;
			break;
		}
		case 1:
		{
			Event e;
			cin >> e;
			ifstream file;
			file.open("events.txt");
			if (file) //file exists
			{
				file.close();
				ofstream f("events.txt", ios::out | ios::app);
				if (f.is_open())
				{
					f << e;
					f.close();
				}
			}
			else //file does not exist
			{
				file.close();
				ofstream f("events.txt", ios::out);
				if (f.is_open())
				{
					f << e;
					f.close();
				}
			}
			break;
		}
		case 2:
		{
			ifstream f1;
			f1.open("events.txt", ios::in);
			if (f1.is_open())
			{
				cout << "-_-_-_-_-_-_file's contents_-_-_-_-_-_-" << endl;
				string line;
				while (getline(f1, line))
				{
					cout << line << endl;
				}
				f1.close();
				cout << "-_-_-_-_-_-_-_end of file_-_-_-_-_-_-_-" << endl;
			}
			break;
		}
		case 3:
		{
			Venue v;
			cin >> v;
			ifstream file;
			file.open("venues.txt");
			if (file)
			{
				file.close();
				ofstream f("venues.txt", ios::out | ios::app);
				if (f.is_open())
				{
					f << v;
					f.close();
				}
			}
			else
			{
				file.close();
				ofstream f("venues.txt", ios::out);
				if (f.is_open())
				{
					f << v;
					f.close();
				}
			}
			break;
		}
		case 4:
		{
			ifstream f1;
			f1.open("venues.txt", ios::in);
			if (f1.is_open())
			{
				cout << "-_-_-_-_-_-_file's contents_-_-_-_-_-_-" << endl;
				Venue v;
				f1 >> v;
				f1.close();
				cout << "-_-_-_-_-_-_-_end of file_-_-_-_-_-_-_-" << endl;
			}
			break;
		}
		case 5:
		{
			//
			break;
		}
		case 6:
		{
			//
			break;
		}
		default:
		{
			cout << "error: Entered value is invalid" << endl;
			break;
		}
		}//
	}
	Event e1;

	ofstream f("events.txt");
	f << e1;
	f.close();
}