#pragma once
#include <string>

#include "date_class_error.h"
#include "month_listing_class.h"
#include "date_class.h"

namespace date_lib
{

	void date_error(const std::string& reason);

	//returns true if 'year' is leap year
	bool leap_year(int year);

	/*
		returns true:
			if 'year' is between min_year and max_year (see date_class.h)
			if month is between 1 and 12
			if days number is valid (for example for Februar it is between 1 and 28 (or 29 in leap year))
	*/
	bool is_date(int year, int month, int day);

	//returns 366 if 'year' is leap, otherwise 365
	int days_in_year(int year);

	//--year, month = 12 if month == 1, otherwise just --month
	void substract_month(int &month, int& year);

}