#pragma once
#include "Header.h"

#include "date_class_error.h"
#include "date_class.h"

class Month_listing
{
public:
	Month_listing();
	string get_name(const int& number) const;
	int get_number(const string& name) const;
	int get_duration(const int& number, const int& year) const;
	int get_duration(const string& name, const int& year) const;
private:
	int find_name_index(const string& name) const;
	int find_number_index(const int& number) const;
	const string month_names[12];
	const int month_durations[12];
	const int size;
};

