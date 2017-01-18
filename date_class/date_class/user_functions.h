#pragma once
#include "Header.h"
#include <vector>

#include "date_class_error.h"
#include "month_listing_class.h"
#include "date_class.h"

void calculate_holidays(int year);
bool is_workday(const Date& dt);

Date next_workday(const Date& dt);
int week_of_year(const Date& dt);

ostream& operator<<(ostream& stream, const Month& m);
ostream& operator<<(ostream& stream, const Date& date);
istream& operator >> (istream& stream, Date& new_date);
bool operator==(const Date& date1, const Date& date2);
bool operator!=(const Date& date1, const Date& date2);
