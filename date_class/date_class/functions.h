#pragma once
#include "Header.h"

#include "date_class_error.h"
#include "month_listing_class.h"
#include "date_class.h"


void date_error(const string& reason);
bool lapy_year(int year);
bool is_date(int, int, int);
int days_in_year(int year);
void substract_month(int &month, int& year);

