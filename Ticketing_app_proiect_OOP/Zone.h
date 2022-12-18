#pragma once
#include <string>

using namespace std;

class Zone
{
private:
	string zoneType;
	unsigned short nrRows;
	unsigned short nrSeatsRow;
public:
	Zone();
	Zone(string zoneType, unsigned short nrRows, unsigned short nrSeatsRow);
	Zone(const Zone& z);
	~Zone();
	string getZoneType();
	unsigned short getNrRows();
	unsigned short getNrSeatsRow();
	void setZoneType(string zoneType);
	void setNrRows(unsigned short nrRows);
	void setNrSeatsRow(unsigned short nrSeatsRow);
	Zone& operator=(const Zone& z);
};

