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

ostream& operator<<(ostream& out, Venue v) //show to console
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
		out << "		Zone's number of rows of spots/seats: " << z.getNrRows() << endl;
		out << "		Zone's number of spots/seats per row: " << z.getNrSeatsRow() << endl;
	}
	return out;
}

ofstream& operator<<(ofstream& f, Venue v) //write to file
{
	//f << "VENUE INFORMATION:" << endl;
	//f << "Venue's name: "
	f << v.venueName << endl;
	//f << "Venue's number of zones: "
	f << v.nrZones << endl;
	for (int i = 0; i < v.nrZones; i++)
	{
		Zone z;
		z = v.zone[i];
		/*if (i > 0)
		{
			f << endl;
		}*/
		//f << "	-ZONE " << i + 1 << ":" << endl;
		//f << "		Zone's type: "
		f << z.getZoneType() << endl;
		//f << "		Zone's number of rows of spots/seats: "
		f << z.getNrRows() << endl;
		//f << "		Zone's number of spots/seats per row: "
		f << z.getNrSeatsRow() << endl;
	}
	f << "@" << endl; //end of the venue entry
	return f;
}

istream& operator>>(istream& in, Venue& v) //write in console
{
	cout << "VENUE INFORMATION:" << endl;
	cout << "Venue's name: ";
	in >> ws;
	getline(in, v.venueName);
	cout << "Venue's number of zones: ";
	in >> v.nrZones;
	//if (v.zone != nullptr && v.nrZones > 0)
	//{
	delete[]v.zone;
	v.zone = nullptr;
	v.zone = new Zone[v.nrZones];
	for (int i = 0; i < v.nrZones; i++)
	{
		if (i > 0)
		{
			cout << endl;
		}
		cout << "	-ZONE " << i + 1 << ":" << endl;
		Zone z;
		in >> z;
		v.zone[i] = z;
	}
	//}
	
	
	return in;
}