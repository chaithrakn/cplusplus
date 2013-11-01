#include <iostream>

using namespace std;
class Date
{
	int d, m, y;
	static Date default_date;

public:
	Date (int dd=0, int mm=0, int yy=0);

	//static member function to manipulate value of default_date
	static void set_default(int dd, int mm, int yy);

	void print();
};

Date::Date(int dd, int mm, int yy)
{
	d = dd ? dd : default_date.d;
	m = mm ? mm : default_date.m;
	y = yy ? yy : default_date.y;
}

void Date::print()
{
	cout << d << " " << m << " " << y << endl;
}

//static member definition
Date Date::default_date(4,9,1985);

//static member function definition
void Date::set_default(int dd, int mm, int yy)
{
	default_date = Date(dd,mm,yy);
}

int main()
{
	Date my_bday;
	cout << "Default bday: ";
	my_bday.print();

	// Create object and invoke constructor with values
	Date new_date(1,2,1934);
	cout << "Date change: ";
	new_date.print();

	// Change default date
	Date::set_default(3,9,1985);
	Date new_default;
	new_default.print();
}
