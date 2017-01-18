/*
	Read README.md first!	
*/

#include "date_library.h"

using std::cout;
using std::cin;

using date_lib::Date;
using date_lib::Date_Class_Error;
using date_lib::is_workday;
using date_lib::wait_until_keyword;

/*
	This is simple code, that prints out holidays in Ukraine between start and end dates.
	The main functionality of this programm providing by the functions that declarated in 'user_functions.h' and by class 'Date'.
*/
void runtime()
{
	Date start{ 2017,1,1 };
	Date end{ 2018,1,1 };
	while (start != end)
	{
		if (!is_workday(start)) cout << start << '\t' << start.get_day_of_week() << '\n';
		start.add_day(1);
	}
}

int main()
{	
	try
	{
		runtime();
	}
	catch (const Date_Class_Error& err)
	{
		err.what(cout);
	}
	wait_until_keyword("exit", cout, cin);
	return 0;
}

