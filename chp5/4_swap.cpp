#include <iostream>

using namespace std;

void swap_pointers(int *a, int *b) 
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void swap_ref(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

// wrong - version that does not work
void swap_value(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;
}

void swap(int& a, int& b)
{
	a = a+b;
	b = a-b;
	a = a-b;
}

int main()
{
	int a = 4, b = 5;
	swap_pointers(&a,&b);
	cout << a << " " << b << endl;
	
	int x = 1, y = 2;
	swap_ref(x,y);
	cout << x << " " << y << endl;

	int c=7, d=8;
	swap_value(c,d);
	cout << c << " " << d << endl;

	swap(c,d);
	cout << c << " " << d << endl;
}
