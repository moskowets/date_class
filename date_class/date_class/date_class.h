#pragma once
#include <string>
#include "date_class.h"
#include "month_listing_class.h"
#include "date_class_error.h"
#include "functions.h"

using namespace std;

enum class Month {
	jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

struct Date_struct
{
	Date_struct();
	Date_struct(int, int, int);
	int year, month, day;
};

class Date
{

public:
	Date();
	Date(int y, string m, int d);
	Date(int y, int m, int d);
	Date(int y, Month mon, int d);
	Date(int d);
	Date(const Date_struct& date);

	Date_struct get_date() const;


	static const int
		max_year{ 2100 },
		min_year{ 1970 },
		month_in_year{ 12 },
		max_days_in_month{ 31 },
		days_in_week{ 7 },
		thursday_index{ 3 };

	void add_day(int n);
	void add_year(int n);
	void add_month(int n);

	int month() const;
	int day() const;
	int year() const;
	long get_days() const;
	string get_day_of_week() const;
private:
	void base_constructor(int y, int m, int d);
	long calculate_days(int y, int m, int d);
	long days{ 0 };
	long max_days;
	static long days_t;
	static const string days_of_the_week[7];

};
