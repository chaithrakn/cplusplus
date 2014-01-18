#include <stack>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

struct tupleNode {
	int x;
	int y;
};

int main() {
	int count;
	cout << "Enter number of tuples \n";
	cin >> count;

	tupleNode set1[count];
	cout << "Enter your tuples\n"; 
	for (int i = 0; i <= count; i++) {
		cin << set1[i].x << set1[i].y ;
	}
	
}
