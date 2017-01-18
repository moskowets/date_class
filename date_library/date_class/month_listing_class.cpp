#include "month_listing_class.h"

namespace date_lib
{

	//see description at 'month_listing_class.h'
	Month_listing Month_list;

	Month_listing::Month_listing() :
		size{ 12 },
		month_names{ "Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec" },
		month_durations{ 31 , 28 ,31 ,30 ,31 ,30 ,31 ,31 ,30 ,31 ,30 ,31 } {}

	// Output functions:
	std::string Month_listing::get_name(const int& number) const
	{
		return month_names[find_number_index(number)];
	}
	int Month_listing::get_number(const std::string& name) const
	{
		return find_name_index(name) + 1;
	}
	int Month_listing::get_duration(const int& number, const int& year) const
	{
		int duration = month_durations[find_number_index(number)];
		if (duration == 28 && leap_year(year)) ++duration;
		return duration;
	}
	int Month_listing::get_duration(const std::string& name, const int& year) const
	{
		int duration = month_durations[find_name_index(name)];
		if (duration == 28 && leap_year(year)) ++duration;
		return duration;
	}
	// Output functions end.

	// Class implementation functions:
	int Month_listing::find_name_index(const std::string& name) const
	{
		for (int i = 0; i < size; ++i)
		{
			if (month_names[i] == name) return i;
		}
		date_error("Month_listing::get_number: Cant find month name: " + name);
		return 0;
	}
	int Month_listing::find_number_index(const int& number) const
	{
		if (number < 1 || number>12) date_error("Month_listing::get_name: Cant find month number: " + std::to_string(number));
		return number - 1;
	}
	// Class implementation functions end.

}