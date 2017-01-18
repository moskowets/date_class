#include "date_class_error.h"

namespace date_lib
{

	Date_Class_Error::Date_Class_Error(const std::string& rs) :reason(rs) {}

	void Date_Class_Error::what(std::ostream &out) const { out << '\n' << "Îøèáêà: " << reason << '\n'; }

}