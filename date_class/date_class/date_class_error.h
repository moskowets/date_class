#pragma once
#include <string>
#include <iostream>

namespace date_lib
{

	class Date_Class_Error
	{
	public:
		Date_Class_Error(const std::string& rs);
		void what(std::ostream &out) const;
	private:
		std::string reason;
	};

}