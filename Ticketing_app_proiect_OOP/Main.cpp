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
	cout << "-- Welcome to the ticket app! --" << endl;
	cout << endl << "| Enter value <11> to stop" << endl;
	cout << "| Enter value <1> to add a new event" << endl;
	cout << "| Enter value <2> to look up for an event" << endl;
	cout << "| Enter value <3> to add a new venue" << endl;
	cout << "| Enter value <4> to look up for a venue" << endl;
	cout << "| Enter value <5> to buy a new ticket" << endl;
	cout << "| Enter value <6> to verify a ticket's purchase" << endl;
	bool b = 1;
	int userInput = -1;
	while (b == 1)
	{
		cout << "|_________________________________________________________________|" << endl;
		cout << "| / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / |";
		cout << endl << "> MAIN MENU";
		cout << endl << "> What do you want to do now? (enter <0> for help)";
		cout << endl << "> Your command is: ";
		cin >> userInput;
		switch (userInput)
		{
		case 0: //for help
		{
			cout << "__________________________________________________________________" << endl;
			cout << "| Enter value <11> to stop" << endl;
			cout << "| Enter value <1> to add a new event" << endl;
			cout << "| Enter value <2> to look up for an event" << endl;
			cout << "| Enter value <3> to add a new venue" << endl;
			cout << "| Enter value <4> to look up for a venue" << endl;
			cout << "| Enter value <5> to buy a new ticket" << endl;
			cout << "| Enter value <6> to verify a ticket's purchase" << endl;
			break;
		}
		case 11: //to stop
		{
			b = 0;
			break;
		}
		case 1: //to add a new event
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
				else
				{
					cout << "\n! error: file did not open !\n";
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
				else
				{
					cout << "\n! error: file did not open !\n";
				}
			}
			break;
		}
		case 2: //to look up for an event
		{
			ifstream f1;
			f1.open("events.txt", ios::in);
			if (f1.is_open())
			{
				cout << "\n-_-_-_-_-_-_file's contents_-_-_-_-_-_-\n" << endl;
				string line;
				short counter = 0;
				while (getline(f1, line))
				{
					counter++;
					if (counter == 1)
					{
						cout << "EVENT INFORMATION:" << endl;
						cout << "Event's name: " << line << endl;
					}
					else if (counter == 2)
					{
						cout << "Event's date: " << line << endl;
					}
					else if (counter == 3)
					{
						cout << "Event's duration: " << line << endl;
					}
					else if (counter == 4)
					{
						cout << "Event's type: " << line << endl;
					}
					else if (counter == 5)
					{
						cout << endl;
						counter = 0;
					}
				}
				f1.close();
				cout << "-_-_-_-_-_-_-_end of file_-_-_-_-_-_-_-\n\n" << endl;
			}
			else
			{
				cout << "\n! error: file did not open !\n";
			}
			break;
		}
		case 3: //to add a new venue
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
				else
				{
					cout << "\n! error: file did not open !\n";
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
		case 4: //look up for a venue
		{
			ifstream f1;
			f1.open("venues.txt", ios::in);
			if (f1.is_open())
			{
				cout << "\n-_-_-_-_-_-_file's contents_-_-_-_-_-_-\n" << endl;
				string line;
				short counter = 0;
				while (getline(f1, line))
				{
					counter++;
					if (counter == 1)
					{
						cout << "VENUE INFORMATION:" << endl;
						cout << "Venue's name: " << line << endl;
					}
					else if (counter == 2)
					{
						cout << "Venue's number of zones: " << line << endl;
					}
					else if (counter == 3)
					{
						if (line == "@")
						{
							cout << endl;
							counter = 0;
						}
						else
						{
							cout << "\tZone's type: " << line << endl;
						}
					}
					else if (counter == 4)
					{
						cout << "\tZone's number of rows of spots/seats: " << line << endl;
					}
					else if (counter == 5)
					{
						cout << "\tZone's number of spots/seats per row: " << line << endl;
						cout << endl;
						counter = 2;
					}
				}
				f1.close();
				cout << "-_-_-_-_-_-_-_end of file_-_-_-_-_-_-_-\n\n" << endl;
			}
			else
			{
				cout << "\n! error: file did not open !\n";
			}
			break;
		}
		case 5: //to buy a new ticket
		{
			string chosenEvent;
			string chosenVenue;
			ifstream f1;
			f1.open("events.txt", ios::in);
			if (f1.is_open())
			{
				cout << "\n-_-_-_-_-_-_available events-_-_-_-_-_-\n" << endl;
				cout << "\t0. Type '0' for help" << endl;
				string line;
				bool show = 1;
				short counter = 0;
				while (getline(f1, line))
				{
					if (show == 1)
					{
						counter++;
						cout << "\t" << counter << ". " << line << endl;
						show = 0;
					}
					if (line == "@")
					{
						show = 1;
					}
				}
				cout << endl << "-_-_-_-_-_-_-_-end of list-_-_-_-_-_-_-\n\n";
				cout << "> Choose the event for the ticket:\n>(type the number that appears before the event's name)" << endl;
				cout << "> Your desired event's number is: ";
				cin >> userInput;
				if (userInput > counter || userInput < 0)
				{
					f1.close();
					cout << endl << "! error: your input is out of range !" << endl << endl;
				}
				else if (userInput == 0)
				{
					f1.close();
				}
				else
				{
					f1.close();
					f1.open("events.txt", ios::in);
					if (f1.is_open())
					{
						show = 1;
						counter = 0;
						while (getline(f1, line))
						{
							if (show == 1)
							{
								counter++;
								show = 0;
							}
							if (line == "@")
							{
								show = 1;
							}
							if (counter == userInput)
							{
								chosenEvent = line;
								break;
							}
						}
					}
					f1.close();
					f1.open("venues.txt", ios::in);
					if (f1.is_open())
					{
						show = 1;
						counter = 0;
						cout << "\n-_-_-_-_-_-_available venues-_-_-_-_-_-\n" << endl;
						cout << "\t0. Type '0' for help" << endl;
						while (getline(f1, line))
						{
							if (show == 1)
							{
								counter++;
								cout << "\t" << counter << ". " << line << endl;
								show = 0;
							}
							if (line == "@")
							{
								show = 1;
							}
						}
						cout << endl << "-_-_-_-_-_-_-_-end of list-_-_-_-_-_-_-\n\n";
						cout << "> Choose the venue for the event:\n> (type the number that appears before the venue's name)" << endl;
						cout << "> Your desired venue's number is: ";
						cin >> userInput;
						cout << endl;
						if (userInput > counter || userInput < 0)
						{
							f1.close();
							cout << endl << "! error: your input is out of range !" << endl << endl;
						}
						else if (userInput == 0)
						{
							f1.close();
						}
						else
						{
							f1.close();
							f1.open("venues.txt", ios::in);
							if (f1.is_open())
							{
								show = 1;
								counter = 0;
								bool found = 0;
								unsigned int maxNrTickets = 0;
								unsigned short zonesNr = 0;
								while (getline(f1, line))
								{
									if (show == 1)
									{
										counter++;
										show = 0;
									}
									if (line == "@")
									{
										show = 1;
									}
									if (counter == userInput)
									{
										chosenVenue = line;
										found = 1;
										getline(f1, line);
										zonesNr = stoi(line);
										for (int i = 0; i < zonesNr; i++)
										{
											int nr = 0;
											getline(f1, line);
											getline(f1, line);
											nr += stoi(line);
											getline(f1, line);
											nr *= stoi(line);
											maxNrTickets += nr;
										}
										break;
									}
								}
							}
							f1.close();
							Ticket t;
							cin >> t;
							ifstream file;
							file.open("ticketsIDs.bin");
							if (file) //file exists
							{
								file.close();
								ofstream f("ticketsIDs.bin", ios::out | ios::app | ios::binary);
								if (f.is_open())
								{
									f << t;
									f.close();
								}
								else
								{
									cout << "\n! error: file did not open !\n";
								}
							}
							else //file does not exist
							{
								file.close();
								ofstream f("ticketsIDs.bin", ios::out | ios::binary);
								if (f.is_open())
								{
									f << t;
									f.close();
								}
								else
								{
									cout << "\n! error: file did not open !\n";
								}
							}
						}
					}
				}
			}
			break;
		}
		case 6: //to verify a ticket's purchase
		{
			string verfIDstring;
			cout << endl << "> The ticket ID you want to verify is: ";
			cin >> verfIDstring;
			const int length = verfIDstring.length();
			char* verfID = new char[length + 1];
			strcpy_s(verfID, length + 1, verfIDstring.c_str());
			ifstream f1;
			f1.open("ticketsIDs.bin", ios::in | ios::binary);
			f1.seekg(0, ios::end);
			int size = (int)f1.tellg();
			f1.seekg(0, ios::beg);
			bool uniqueID = 1;
			int lengthID = 0;
			char* compID = nullptr;
			while (f1.tellg() < size)
			{
				f1.read((char*)&lengthID, sizeof(lengthID));
				compID = new char[lengthID + 1];
				f1.read(compID, lengthID + 1);
				if (strcmp(verfID, compID) == 0)
				{
					uniqueID = 0;
				}
				lengthID = 0;
				delete[]compID;
				compID = nullptr;
			}
			if (uniqueID == 0)
			{
				cout << endl << "> The ticket is INVALID. No ticket with this ID was purchased" << endl;
			}
			else
			{
				cout << endl << "> The ticket is VALID." << endl;
			}
			f1.close();
			break;
		}
		default:
		{
			cout << "\n! error: value entered is invalid !\n" << endl;
			break;
		}
		}
	}
}