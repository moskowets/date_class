#include "user_functions.h"

extern Month_listing Month_list;

ostream& operator<<(ostream& stream, const Month& m)
{
	return stream << Month_list.get_name(int(m));
}

ostream& operator<<(ostream& stream, const Date& date)
{
	Date_struct ds = date.get_date();
	return stream << Month_list.get_name(ds.month) << ' ' << ds.day << ',' << ds.year;
}

istream& operator >> (istream& stream, Date& new_date)
{
	Date_struct ds;
	char ch1, ch2, ch3, ch4;
	stream >> ch1 >> ds.day >> ch2 >> ds.month >> ch3 >> ds.year >> ch4;
	if (!stream) return stream;
	if (ch1 != '{' || ch2 != '.' || ch3 != '.' || ch4 != '}')
	{
		stream.clear(ios_base::failbit);
		return stream;
	}
	new_date = Date{ ds };
	return stream;
}

bool operator==(const Date& date1, const Date& date2)
{
	return date1.get_days() == date2.get_days();
}

bool operator!=(const Date& date1, const Date& date2)
{
	return !(date1 == date2);
}


vector <Date> Holydays;


void calculate_holidays(int year)
{
	//в данных двух векторах перечислены праздники, которые не меняют свой день в году
	static const vector <int> month_h	{ 1,	1,	3,	5,	5,	5,	6,	8,	10 };
	static const vector <int> days_h	{ 1,	7,	8,	1,	2,	9,	28,	24,	14 };
	
	if (month_h.size() != days_h.size()) date_error("calculate_holidays: длинаы векторов (месяц, день) табличных праздников должны быть равны");

	vector <Date> Holydays_raw;

	for (int i = 0;i < month_h.size();++i)
	{
		Holydays_raw.push_back(Date(year, month_h[i], days_h[i]));
	}
	//считаем пасху
	Date ostern;
	int ost_a, ost_b, ost_c, ost_d, ost_e, ost_f;
	ost_a = year % 19;
	ost_b = year % 4;
	ost_c = year % 7;
	ost_d = (19 * ost_a + 15) % 30;
	ost_e = (2 * ost_b + 4 * ost_c + 6 * ost_d + 6) % 7;
	ost_f = ost_d + ost_e;
	if (ost_f <= 9) ostern = Date{ year,  3 , 22 + ost_f };
	else ostern = Date{ year,  4 , ost_f - 9 };
	//пересчитываем на новый стиль
	ostern.add_day(13);

	Date trinity{ ostern };
	//пасха + 49 дней = троица
	trinity.add_day(49);
	Holydays_raw.push_back(ostern);
	Holydays_raw.push_back(trinity);
	
	Holydays.clear();
	string dow;
	for (int i = 0;i < Holydays_raw.size();++i)
	{
		dow = Holydays_raw[i].get_day_of_week();
		if (dow == "Sat" || dow == "Sun") Holydays.push_back(next_workday(Holydays_raw[i]));
		else Holydays.push_back(Holydays_raw[i]);
	}	
}

bool is_workday(const Date & dt)
{
	int year = dt.year();
	if (Holydays.size() == 0) calculate_holidays(year);
	if (year != Holydays[0].year()) calculate_holidays(year);
	string dow = dt.get_day_of_week();
	if (dow == "Sat" || dow == "Sun") return false;
	for (int i = 0;i < Holydays.size();++i)
	{
		if (Holydays[i] == dt) return false;
	}
	return true;	
}

Date next_workday(const Date& dt)
{
	Date nd = dt;
	string dow;
	do
	{
		nd.add_day(1);
		dow = nd.get_day_of_week();
	} while (dow == "Sat" || dow == "Sun");
	return nd;
}

int week_of_year(const Date& dt)
{
	int year = dt.year();
	Date nd{ year, 1, 1 };
	while (nd.get_day_of_week() != "Mon")
	{
		if (dt == nd)
		{
			if (year == Date::min_year) return 0;
			else return week_of_year(Date{ year - 1, 12, 31 });
		}
		nd.add_day(1);
	}
	return (dt.get_days() - nd.get_days()) / Date::days_in_week + 1;
}

