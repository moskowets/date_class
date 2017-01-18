#pragma once
#include <string>

#include "date_class_error.h"
#include "date_class.h"

namespace date_lib
{

	/*
		This class contains all information about months.
		It can convert month string (example "Feb") to month number (example 2) vice versa.
		It can return month duration by given information (month number or month string and year number).
		There is only one 'Month_listing' class object called 'Month_list';
	*/
	class Month_listing
	{
	public:
		Month_listing();
		std::string get_name(const int& number) const;
		int get_number(const std::string& name) const;
		int get_duration(const int& number, const int& year) const;
		int get_duration(const std::string& name, const int& year) const;
	private:
		int find_name_index(const std::string& name) const;
		int find_number_index(const int& number) const;
		const std::string month_names[12];
		const int month_durations[12];
		const int size;
	};

}