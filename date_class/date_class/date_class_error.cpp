#include "date_class_error.h"

Date_Class_Error::Date_Class_Error(const string& rs) :reason(rs) {}

void Date_Class_Error::what(ostream &out) const
{
	out << '\n' << "Îøèáêà: " << reason << '\n';
}