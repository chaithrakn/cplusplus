#include <iostream>

int main() 
{
	typedef unsigned char uchar;
	typedef const unsigned char c_uchar;
	typedef int* pint; //pointer to integer
	typedef char** ppchar; //pointer to pointer to char
	typedef char* pchar; // pointer to array of char
	
	int* a[7]; //array of 7 pointers to int
	typedef int datatype;
	typedef datatype* sevenint[7]; //typedef of above. Use it as sevenint s = new sevenint[7] ??

	// pointer to an array of 7 pointers to int
	typedef int datatype;
	typedef datatype** seventint[7]; //array of 7 pointers to int 

	//array of 8 arrays of 7 pointers to int
	int* b[7][8];
}
