#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>

// Count all occurences of a character in a string - 3.8.1

using namespace std;
int count (const string& s, char c) 
{
	int n=0;
	string::const_iterator i = find(s.begin(),s.end(),c); //finds first occurence of c in s

	while(i != s.end()) {
		++n;
		i = find(i+1, s.end(), c); // finds next occurence of c in the rest of s
	}
	return n;
}

int main()
{
	string m = "Mary had a little lamb";
	cout << count(m, 'a') << endl;
}
