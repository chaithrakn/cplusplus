#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main()
{
	list<int> lst1; //empty list

	list<int> lst2(3, 7); // lst2 = (7 7 7)

	for (int j = 1; j <= 5; j++)
		lst1.push_back(j); // addToTail. lst1 = (1 2 3 4 5)

	list<int>::iterator i1 = lst1.begin(), i2 = i1, i3; //i1 points to head of lst1

	i2++; i2++; i2++; //i2 points to element 4 in lst1?

	cout << "i2:" << *i2 << endl; 
	
	// Lets print lst1
	for (i3 = i2; i3 != lst1.end(); i3++)
		cout << *i3; // Note how *i3 is used

	cout << endl;

	list<int> lst3(++i1, i2); // Note: i1 and i2 are iterators as opposed to int above for lst2
				  // lst3 = (2 3) between ranges first and last.
	for (i3 = lst3.begin(); i3 != lst3.end(); ++i3)
                cout << *i3;

	cout << endl;

	list<int> lst4(lst1); // copy constructor. lst4 = (1 2 3 4 5)

	// lst2 = (7 7 7)
	i1 = lst4.begin();
	lst4.splice(++i1, lst2); // inserts lst2 at position ++i1 in lst4.
	// lst4 = (1 7 7 7 2 3 4 5) - i1 is still pointing to 2

	for (i3 = lst4.begin(); i3 != lst4.end(); ++i3)
                cout << *i3;

        cout << endl;

	cout << "i1:" << *i1 << endl;

	lst2 = lst1; // lst2 = (1 2 3 4 5)
	i2 = lst2.begin();
	lst4.splice(i1, lst2, ++i2); // lst2 = (1 3 4 5) - remove from lst2 element referenced by ++i2
					// insert the removed element in lst4 at position before i1
					// i1 points to 2 in lst4
					// lst4 = (1 7 7 7 2 2 3 4 5)

	lst4.remove(1);
	lst4.sort();
	lst4.unique(); // lst4 = (2 3 4 5)

	lst1.merge(lst2); // lst1 = (1 1 2 3 3 4 4 5 5) - merges in sorted order
			  // also lst2 is empty. merge() removes all elements from lst2 and inserts them in lst1.

	lst3.reverse(); // lst3 = (3 2)
	
	lst4.reverse(); // lst4 = (5 4 3 2)
	lst3.merge(lst4, greater<int>()); //merge in descending order
					  // lst4 = (5 4 3 3 2 2)


	for (i3 = lst4.begin(); i3 != lst4.end(); ++i3)
                cout << *i3;
}
