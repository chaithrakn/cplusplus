#include <iostream>
#include <cstring>
using namespace std;

// Recursive
void reverse() {
	char ch;
	cin.get(ch);
	if (ch != '\n') {
		reverse();
		cout.put(ch);
	}
	cout << endl;
}

// Non-recursive
void nonRec() {
	char stack[80];
	register int top = 0;
	cin.getline(stack, 80);
	for (top = strlen(stack) - 1; top >= 0; cout.put(stack[top--]));
}

int main() {
	//reverse();
	nonRec();
}
