#include "date_class.h"

extern Month_listing Month_list;

long Date::get_days() const
{
	return days;
}

void Date::base_constructor(int y, int m, int d)
{
	if (!is_date(y, m, d)) date_error("Date::base_constructor: Неверная дата: " + to_string(d) + "." + to_string(m) + "." + to_string(y));
	days = calculate_days(y, m, d);
	max_days = calculate_days(max_year, month_in_year, max_days_in_month);
}

string Date::get_day_of_week() const
{
	return days_of_the_week[(days + thursday_index) % days_in_week];
}
const string Date::days_of_the_week[] = { "Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun" };
long Date::days_t{ 0 };

long Date::calculate_days(int y, int m, int d)
{
	long days_temp = 0;
	int current_year = min_year;
	while (current_year != y)
	{
		days_temp += days_in_year(current_year);
		++current_year;
	}
	for (int month_numb = 1; month_numb < m; ++month_numb)
	{
		days_temp += Month_list.get_duration(month_numb, y);
	}
	days_temp += d - 1;
	return days_temp;
}

Date::Date(const Date_struct& date)
{
	base_constructor(date.year, date.month, date.day);
}


Date::Date()
{
	max_days = calculate_days(max_year, month_in_year, max_days_in_month);
}

Date::Date(int y, string mon, int d)
{
	int m = Month_list.get_number(mon);
	base_constructor(y, m, d);
}
Date::Date(int y, int m, int d)
{
	base_constructor(y, m, d);
}

Date::Date(int y, Month mon, int d)
{
	int m = int(mon);
	base_constructor(y, m, d);
}
Date::Date(int d)
{
	if (d < 0) date_error("Date::Date: Невозможно инициализировать объект Date отрицательным числом");
	max_days = calculate_days(max_year, month_in_year, max_days_in_month);
	if (d > max_days) date_error("Date::Date: Невозможно инициализировать объект Date числом, которое характеризует дату больше максимальной");
	days = d;
}

Date_struct Date::get_date() const
{
	Date_struct date;
	long days_temp = days;
	while (days_temp - days_in_year(date.year) >= 0)
	{
		days_temp = days_temp - days_in_year(date.year);
		++date.year;
	}
	while (days_temp - Month_list.get_duration(date.month, date.year) >= 0)
	{
		days_temp = days_temp - Month_list.get_duration(date.month, date.year);
		++date.month;
	}
	date.day += days_temp;
	return date;
}

int Date::year() const
{
	int year = min_year;
	days_t = days;
	while (days_t - days_in_year(year) >= 0)
	{
		days_t = days_t - days_in_year(year);
		++year;
	}
	return year;
}

int Date::month() const
{
	int year_t = year();
	int month{ 1 };
	while (days_t - Month_list.get_duration(month, year_t) >= 0)
	{
		days_t = days_t - Month_list.get_duration(month, year_t);
		++month;
	}
	return month;
}

int Date::day() const
{
	month();
	int day{ 1 };
	day += days_t;
	return day;
}

void Date::add_day(int n)
{
	if (days + n < 0) date_error("add_day: Вы пытаетесь вычесть такое количество дней, что дата будет меньше минимальной");
	if (n > max_days - days) date_error("add_day: Вы пытаетесь добавить такое количество дней, что дата будет больше максимальной");
	days += n;
}



void Date::add_year(int n)
{
	int year_current = year();
	if (n > 0)
	{
		if (n > max_year - year_current) date_error("Date::add_year: Вы пытаетесь добавить такое количество лет, которое больше максимальной даты");
		for (int i = 0; i < n; ++i)
		{
			days += days_in_year(year());
		}
	}
	else
	{
		if (year_current + n < min_year) date_error("Date::add_year: Вы пытаетесь вычесть такое количество лет, которое меньше минимальной даты");
		for (int i = 0; i < -n; ++i)
		{
			days -= days_in_year(year() - 1);
		}
	}
}

void Date::add_month(int n)
{
	Date_struct current_date = get_date();
	if (n > 0)
	{
		for (int i = 0; i < n; ++i)
		{
			long days_to_add = Month_list.get_duration(current_date.month, current_date.year);
			if (days_to_add > max_days - days) date_error("Date::add_month: Вы пытаетесь добавить такое количество месяцев, которое больше максимальной даты");
			days += days_to_add;
			current_date = get_date();
		}
	}
	else
	{
		for (int i = 0; i < -n; ++i)
		{
			substract_month(current_date.month, current_date.year);
			long days_to_substract = Month_list.get_duration(current_date.month, current_date.year);
			if (days < days_to_substract) date_error("Date::add_month: Вы пытаетесь вычесть такое количество месяцев, которое меньше минимальной даты");
			days -= days_to_substract;
			current_date = get_date();
		}
	}
}

Date_struct::Date_struct() : year{ Date::min_year }, day{ 1 }, month{ 1 } {}
Date_struct::Date_struct(int y, int m, int d) : year{ y }, day{ m }, month{ d } {}