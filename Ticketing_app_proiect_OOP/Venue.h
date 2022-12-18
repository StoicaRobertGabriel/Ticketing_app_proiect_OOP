#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Zone.h"

using namespace std;

class Venue
{
private:
	string venueName;
	unsigned short nrZones;
	Zone* zone;
public:
	Venue();
	Venue(string venueName, unsigned short nrZones, Zone* zone);
	Venue(const Venue& v);
	~Venue();
	friend ostream& operator<<(ostream& out, Venue v);
	friend ofstream& operator<<(ofstream& f, Venue v);
	friend istream& operator>>(istream& in, Venue& v);
};

ostream& operator<<(ostream& out, Venue v);
ofstream& operator<<(ofstream& f, Venue v);
istream& operator>>(istream& in, Venue& v);
