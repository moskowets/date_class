#pragma once
#include "Header.h"

class Date_Class_Error
{
public:
	Date_Class_Error(const string& rs);
	void what(ostream &out) const;
private:
	string reason;
};

