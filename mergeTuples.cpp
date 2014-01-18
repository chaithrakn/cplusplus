#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct {
	int x;
	int y;
} tupleNode;

bool compare(tupleNode a, tupleNode b) {
        return (a.x <  b.x);
}

void mergeTuples(vector<tupleNode> t) {
	stack<tupleNode> myS;

        sort(t.begin(), t.end(), compare);

	myS.push(t[0]);
	for (int i = 1; i < t.size(); i++) {
		tupleNode top = myS.top();
		if (top.y < t[i].x) {
            		myS.push(t[i]);
        	} else if (top.y < t[i].y) {
            		top.y = t[i].y;
            		myS.pop();
            		myS.push(top);
        	}
    	}

	cout << "Merged set: \n";
	while (!myS.empty()) {
        	tupleNode t = myS.top();
        	cout << "[" << t.x << "," << t.y << "]";
        	myS.pop();
    	}
	cout << endl;
}

void print(vector<tupleNode> t) {
	cout << "Your set: " << endl;
	for (int i = 0; i < t.size(); i++) {
		cout << "[" << t[i].x << "," << t[i].y << "]";
	}
	cout << endl;
}

int main() {
	tupleNode example1[] = {{3,5}, {3,9}, {2,8}, {6,20}};
	vector<tupleNode> tuples1(example1, example1+4);
	print(tuples1);
	mergeTuples(tuples1);

	tupleNode example2[] = {{20, 30}, {9, 15}, {6,7}, {1,9}, {3,19}};
	vector<tupleNode> tuples2(example2, example2+5);	
	print(tuples2);
	mergeTuples(tuples2);
}
