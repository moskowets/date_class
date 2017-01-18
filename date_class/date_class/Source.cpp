#include "Header.h"
#include "date_classes.h"


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
	setlocale(LC_ALL, "Russian");
	while (true)
	{
		try
		{
			runtime();
			system("PAUSE");
		}
		catch (const Date_Class_Error& err)
		{
			err.what(cout);
		}
	}
	return 0;
}

