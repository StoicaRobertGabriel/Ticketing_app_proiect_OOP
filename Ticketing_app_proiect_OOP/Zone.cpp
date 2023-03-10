#include "Zone.h"

Zone::Zone()
{
	zoneType = "any";
	nrRows = 0;
	nrSeatsRow = 0;
}

Zone::Zone(string zoneType, unsigned short nrRows, unsigned short nrSeatsRow)
{
	this->zoneType = zoneType;
	this->nrRows = nrRows;
	this->nrSeatsRow = nrSeatsRow;
}

Zone::Zone(const Zone& z)
{
	this->zoneType = z.zoneType;
	this->nrRows = z.nrRows;
	this->nrSeatsRow = z.nrSeatsRow;
}

Zone::~Zone()
{
}

string Zone::getZoneType()
{
	return zoneType;
}

unsigned short Zone::getNrRows()
{
	return nrRows;
}

unsigned short Zone::getNrSeatsRow()
{
	return nrSeatsRow;
}

void Zone::setZoneType(string zoneType)
{
	this->zoneType = zoneType;
}

void Zone::setNrRows(unsigned short nrRows)
{
	this->nrRows = nrRows;
}

void Zone::setNrSeatsRow(unsigned short nrSeatsRow)
{
	this->nrSeatsRow = nrSeatsRow;
}

Zone& Zone::operator=(const Zone& z)
{
	this->zoneType = z.zoneType;
	this->nrRows = z.nrRows;
	this->nrSeatsRow = z.nrSeatsRow;
	return *this;
}

istream& operator>>(istream& in, Zone& z)
{
	cout << "		Zone's type: ";
	in >> ws;
	getline(in, z.zoneType);
	cout << "		Zone's number of rows of spots/seats: ";
	in >> ws;
	in >> z.nrRows;
	cout << "		Zone's number of spots/seats per row: ";
	in >> ws;
	in >> z.nrSeatsRow;
	return in;
}