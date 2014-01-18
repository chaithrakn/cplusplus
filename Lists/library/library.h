#include <iostream>
#include <list>
#include <cstring>
#include <algorithm>

using namespace std;

class Patron; //forward decalration: because this class is referenced by the classes defined before Patron class.

// why is == public and << private in all classes?

class Book {
public:
	Book() {
		patron = 0;
	}
	bool operator== (const Book &bk) const {
		return strcmp(bk.title, title) == 0;
	}
private:
	char *title;
	Patron *patron;

	// Use a user-defined function to overload operator <<
	ostream& printBook(ostream&) const;
	friend ostream& operator<< (ostream &out, const Book &bk) {
		return bk.printBook(out);
	}

	friend class CheckedOutBook;
	friend class Patron;

	// friend functions defined outside all classes.
	friend void includeBook();
	friend void checkOutBook();
	friend void returnBook();
};

class Author {
public:
	Author() { }
	bool operator== (const Author &ar) {
		return strcmp(ar.name,name) == 0;
	}
private:
	char *name;
	list<Book> books;

	// Overload << to print author
	ostream& printAuthor(ostream&) const;
	friend ostream& operator<< (ostream& out, const Author &ar) {
		return ar.printAuthor(out);
	}
	
	friend class CheckedOutBook;
        friend class Patron;

        // friend functions defined outside all classes.
        friend void includeBook();
        friend void checkOutBook();
        friend void returnBook();

};

class CheckedOutBook {
public:
	CheckedOutBook(list<Author>::iterator ar=0,
			list<Book>::iterator bk=0) {
		author = ar;
		book = bk;
	}
	bool operator== (const CheckedOutBook& cbk) const {
		return (strcmp(cbk.author->name,author->name) == 0 && 
			strcmp(cbk.book->title,book->title) == 0);
	}
private:
	list<Author>::iterator author;
	list<Book>::iterator book;

	friend void checkOutBook();
	friend void returnBook();
	friend class Patron;
};

class Patron {
public:
	Patron() { }
	bool operator== (const Patron &pt) const {
		return strcmp(pt.name,name) == 0;
	}
private:
	char *name;
	list<CheckedOutBook> books;
	
	ostream& printPatron(ostream&) const;
	friend ostream& operator<< (ostream& out, const Patron &pt) {
		return pt.printPatron(out);
	}
	
	friend void checkOutBook();
	friend void returnBook();
	friend class Book;
};

template <typename T>
ostream& operator<< (ostream& out, const list<T>& lst) {
//      list<T>::const_iterator ref = lst.begin();
        for (typename list<T>::const_iterator ref = lst.begin(); ref != lst.end(); ref++) {
                out << *ref;
        }

        return out;
}

