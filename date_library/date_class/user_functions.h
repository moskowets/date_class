#pragma once
#include <string>
#include <iostream>
#include <vector>

#include "date_class_error.h"
#include "month_listing_class.h"
#include "date_class.h"

namespace date_lib
{

	/*
		Calculates holidays (ukrainian, including Easter and Trinity) for this 'year'
		and stores it in 'vector<Date> Holydays'.
		This function will be automaticly called if you call 'is_workday()' function
		and there are no records with current date's year in 'vector<Date> Holydays'.

	*/
	void calculate_holidays(int year);
	bool is_workday(const Date& dt);

	Date next_workday(const Date& dt);
	/*
		Returns number of week (from year beginning) of current date.
		The week before first Monday is related to previos year.
		Example:
		1 Jan 2016 if Friday and it is 52 week of 2015;
		4 Jan 2016 if Monday and it is  1 week of 2016;
		But one exeption: if it is going about the minimum year,
		then:
		1 Jan 1970 if Thursday and it is 0 week of 1970;
		5 Jan 1970 if Monday   and it is 1 week of 1970;
	*/
	int week_of_year(const Date& dt);

	std::ostream& operator<<(std::ostream& stream, const Month& m);
	std::ostream& operator<<(std::ostream& stream, const Date& date);

	// input format is '{YYYY, MM, DD}' where all numbers have int type 
	std::istream& operator >> (std::istream& stream, Date& new_date);
	bool operator==(const Date& date1, const Date& date2);
	bool operator!=(const Date& date1, const Date& date2);

	void wait_until_keyword(const std::string& key_word, std::ostream& out, std::istream& in);

}