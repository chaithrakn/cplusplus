/* Stack implemented as a linked list */

#include <list>

template <class T>
class genStack
{
public:
	genStack() {

	}

	void clear() {
		S.clear();
	}

	T pop () {
		T ret = S.back(); 
		S.pop_back();
		return ret;
	}

	T topEl() {
		return S.front();
	}

	void push (const T &el) {
		S.push_front(el);
	}

	bool isEmpty() {
		return S.empty();
	}	

private:
	list<T> S;
};
