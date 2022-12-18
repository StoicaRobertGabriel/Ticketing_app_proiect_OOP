#include "Venue.h"
#include "Zone.h"

Venue::Venue()
{
	venueName = "N/A";
	nrZones = 0;
	zone = nullptr;
}

Venue::Venue(string venueName, unsigned short nrZones, Zone* zone)
{
	this->venueName = venueName;
	if (zone != nullptr && nrZones > 0)
	{
		this->zone = new Zone[nrZones];
		for (int i = 0; i < nrZones; i++)
		{
			this->zone[i] = zone[i];
		}
		this->nrZones = nrZones;
	}
	else
	{
		this->zone = nullptr;
		this->nrZones = 0;
	}
}

Venue::Venue(const Venue& v)
{
	this->venueName = v.venueName;
	if (v.zone != nullptr && v.nrZones > 0)
	{
		this->zone = new Zone[v.nrZones];
		for (int i = 0; i < v.nrZones; i++)
		{
			this->zone[i] = v.zone[i];
		}
		this->nrZones = v.nrZones;
	}
	else
	{
		this->zone = nullptr;
		this->nrZones = 0;
	}
}

Venue::~Venue()
{
	if (this->zone != nullptr)
	{
		delete[]this->zone;
	}
}

ostream& operator<<(ostream& out, Venue v)
{
	out << "VENUE INFORMATION:" << endl;
	out << "Venue's name: " << v.venueName << endl;
	out << "Venue's number of zones: " << v.nrZones << endl;
	for (int i = 0; i < v.nrZones; i++)
	{
		Zone z;
		z = v.zone[i];
		if (i > 0)
		{
			out << endl;
		}
		out << "	-ZONE " << i + 1 << ":" << endl;
		out << "		Zone's type: " << z.getZoneType() << endl;
		out << "		Zone's number of spot rows: " << z.getNrRows() << endl;
		out << "		Zone's number of spots per row: " << z.getNrSeatsRow() << endl;
	}
	return out;
}

ofstream& operator<<(ofstream& f, Venue v)
{
	f << "VENUE INFORMATION:" << endl;
	f << "Venue's name: " << v.venueName << endl;
	f << "Venue's number of zones: " << v.nrZones << endl;
	for (int i = 0; i < v.nrZones; i++)
	{
		Zone z;
		z = v.zone[i];
		if (i > 0)
		{
			f << endl;
		}
		f << "	-ZONE " << i + 1 << ":" << endl;
		f << "		Zone's type: " << z.getZoneType() << endl;
		f << "		Zone's number of spot rows: " << z.getNrRows() << endl;
		f << "		Zone's number of spots per row: " << z.getNrSeatsRow() << endl;
	}
	return f;
}

istream& operator>>(istream& in, Venue& v)
{
	cout << "VENUE INFORMATION:" << endl;
	cout << "Venue's name: ";
	in >> ws;
	getline(in, v.venueName);
	cout << "Venue's number of zones: ";
	in >> v.nrZones;
	for (int i = 0; i < v.nrZones; i++)
	{
		if (i > 0)
		{
			cout << endl;
		}
		cout << "	-ZONE " << i + 1 << ":" << endl;
		cout << "		Zone's type: ";
		string zoneTypeString;
		in >> ws;
		getline(in, zoneTypeString);
		v.zone[i].setZoneType(zoneTypeString);
		cout << "		Zone's number of spot rows: ";
		unsigned short zoneNrRows;
		in >> ws;
		in >> zoneNrRows;
		v.zone[i].setNrRows(zoneNrRows);
		cout << "		Zone's number of spots per row: ";
		unsigned short zoneNrSeatsRow;
		in >> ws;
		in >> zoneNrSeatsRow;
		v.zone[i].setNrSeatsRow(zoneNrSeatsRow);
	}
	return in;
}