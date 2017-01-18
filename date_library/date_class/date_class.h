#pragma once
#include <string>
#include "date_class.h"
#include "month_listing_class.h"
#include "date_class_error.h"
#include "functions.h"

namespace date_lib
{

	enum class Month {
		jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
	};


	struct Date_struct
	{
		Date_struct();
		Date_struct(int, int, int);
		int year, month, day;
	};

	/*
		Date stored as one integer value called 'days' and represents the
		number of days that have elapsed from minimum date value.
		For example if you set minimum date 'days' will be equal to zero.

		The date can be constructed:
		- with default date value = minimum date value
		- by specifying the number of days that have elapsed from minimum date value
		- by specifying date in such format: year, month, day
				month can be represented by: month number (1-12), enumeration or string (example "Oct")
	*/
	class Date
	{

	public:
		Date();
		Date(int y, std::string m, int d);
		Date(int y, int m, int d);
		Date(int y, Month mon, int d);
		Date(int d);
		Date(const Date_struct& date);

		Date_struct get_date() const;

		/*
			Here you can specify minimum date value by changing:
			min_year{ 1970 }
			day_of_week_of_minday_index{ 3 } -	why the value is 3?
												because 1.Jan.1970 was
												Thursday (Monday = 0, Sunday = 6)
			You can also change maximum date by changing max_year.
			The value 2100 says that maximum date is 31.Dec.2100.
		*/
		static const int
			max_year{ 2100 },
			min_year{ 1970 },
			month_in_year{ 12 },
			max_days_in_month{ 31 },
			days_in_week{ 7 },
			day_of_week_of_minday_index{ 3 };

		void add_day(int n);
		void add_year(int n);
		void add_month(int n);

		int month() const;
		int day() const;
		int year() const;

		//returns days variable. It needed for operator overloading.
		long get_days() const;

		//returns the name of day of week
		std::string get_day_of_week() const;
	private:
		void base_constructor(int y, int m, int d);
		long calculate_days(int y, int m, int d);

		//the value where is date stored
		long days{ 0 };

		//the value calculated by constructor and represents the days number between maximum and minimum date 
		long max_days;

		//just temporary variable for year(), month(), and day() calculation
		static long days_t;

		static const std::string days_of_the_week[7];

	};

}