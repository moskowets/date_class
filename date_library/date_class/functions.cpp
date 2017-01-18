#include "functions.h"

namespace date_lib
{

	extern Month_listing Month_list;

	void date_error(const std::string& reason) { throw Date_Class_Error(reason); }
	void substract_month(int &month, int& year)
	{
		if (month == 1)
		{
			if (year == Date::min_year) date_error("substract_month: �� ��������� ������� �� ����, ������� ������� �� ������������ ���� � ������");
			month = 12;
			--year;
		}
		else --month;
	}
	bool leap_year(int year)
	{
		if (year % 4 != 0) return false;
		if (year % 100 == 0)
		{
			if (year % 400 == 0) return true;
			else return false;
		}
		return true;
	}
	bool is_date(int year, int mon, int day)
	{
		if (year < Date::min_year || year >  Date::max_year) return false;
		if (mon < 1 || mon > Date::month_in_year) return false;
		if (day < 1 || day > Month_list.get_duration(mon, year)) return false;
		return true;
	}
	int days_in_year(int year)
	{
		if (leap_year(year)) return 366;
		else return 365;
	}

}