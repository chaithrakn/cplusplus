#include "library.h"

using namespace std;

list<Author> catalog['Z'+1];
list<Patron> people['Z'+1];

ostream& Author::printAuthor(ostream& out) const {
	out << name << endl;
	list<Book>::const_iterator ref = books.begin();
	for(; ref != books.end(); ref++) {
		out << *ref;
	}
	return out;
}

ostream& Book::printBook(ostream& out) const {
	out << title << endl;
	if (patron != 0) {
		out << "checked out by:" << patron->name << endl;
	}
	return out;
}

ostream& Patron::printPatron(ostream& out) const {
	out << name << endl;
	if (!books.empty()) {
		out << "has following books:\n";
		list<CheckedOutBook>::const_iterator bk = books.begin();
		for(; bk != books.end(); bk++) {
			out << " *" << bk->author->name << ", " << bk->book->title << endl;
		}
	} else out << "has no books\n";
	return out;	 
}

// overload << operator to output a list
/* template <class T> 
ostream& operator<< (ostream& out, const list<T>& lst) {
//	list<T>::const_iterator ref = lst.begin();
	for (list<T>::const_iterator ref = lst.begin(); ref != lst.end(); ref++) {
		out << *ref;
	}
	
	return out;
} */

void status()
{
	register int i;
	cout << "Library has following books: \n \n";
	for (i = 'A'; i <= 'Z'; i++) {
		if (!catalog[i].empty()) {
			cout << catalog[i];
		}
	}
	cout << "Following people are using the library: \n \n";
	for (i = 'A'; i <= 'Z'; i++) {
		if (!people[i].empty()) {
			cout << people[i];
		}
	}
}

// generic function to read an input from user.
char* getString(char *msg)
{
	char s[82], i, *dest;
	cout << msg;
	cin.get(s,80);
	while (cin.get(s,81) && s[81] != '\n'); // discard overflowing chars
	dest = new char[strlen(s) + 1];
	for (i = 0; i <= strlen(s); i++) {
		dest[i] = toupper(s[i]);
	}
	return dest;
}

void includeBook()
{
// create Book,create Author
Author newAuthor;
Book newBook;

// get author and book name
newAuthor.name = getString("Enter author name:\n");
newBook.title = getString("Enter book title:\n");

// get first char of author.
// If the author already exists, no need to update catalog. Add the new book to the book list pointed to by author
// If author does not exists in list, add new book to author's book list

list<Author>::iterator oldAuthor = find(catalog[newAuthor.name[0]].begin(), catalog[newAuthor.name[0]].end(), newAuthor);
// catalog[newAuthor.name[0]] : returns the index of the first char of author's name in catalog.
// catalog[newAuthor.name[0]].begin() : returns the iterator to the beginning of the list of Authors pointed to by this index in catalog.

if (oldAuthor == catalog[newAuthor.name[0]].end()) { 
// We reached end() of author list without finding newAuthor. i.e. author does not exist in catalog.
	newAuthor.books.push_front(newBook);  // add newBook to newAuthor's book list
	catalog[newAuthor.name[0]].push_front(newAuthor); // add newAuthor to catalog
} else {
// add newBook to the end of already existing Author in catalog.
	(*oldAuthor).books.push_front(newBook);
}
}

void checkOutBook()
{
// Get patron, books and authors
Patron patron;
Book book;
Author author;
list<Author>::iterator authorRef;
list<Book>::iterator bookRef;

patron.name = getString("Enter patron's name: \n");

while(true) {
	author.name = getString("Enter author name:\n");
	authorRef = find(catalog[author.name[0]].begin(), catalog[author.name[0]].end(), author);
	if (authorRef == catalog[author.name[0]].end()) {
		cout << "Author not found\n";
	} else break;
}

while(true) {
        book.title = getString("Enter book title:\n");
        bookRef = find((*authorRef).books.begin(), (*authorRef).books.end(), book);
        if (bookRef == (*authorRef).books.end()) {
                cout << "Book not found\n";
        } else break;
}

CheckedOutBook cbk(authorRef, bookRef);

list<Patron>::iterator patronRef;
// find patron in people. If not found, add new patron to people. Else, update existing patron with new CheckedOutBook.
patronRef = find(people[patron.name[0]].begin(), people[patron.name[0]].end(),patron);

if (patronRef == people[patron.name[0]].end()) {
// new patron
	patron.books.push_front(cbk);
	people[patron.name[0]].push_front(patron);
	(*bookRef).patron = &*people[patron.name[0]].begin();
} else {
	(*patronRef).books.push_back(cbk);
	(*bookRef).patron = &*patronRef; //why &*
}
}

void returnBook()
{
// update patron in Book
// Get patron, books and authors
Patron patron;
Book book;
Author author;
list<Author>::iterator authorRef;
list<Book>::iterator bookRef;
list<Patron>::iterator patronRef;

while(true) {
        patron.name = getString("Enter patron's name:\n");
        patronRef = find(people[patron.name[0]].begin(), people[patron.name[0]].end(), patron);
        if (patronRef == people[patron.name[0]].end()) {
                cout << "Patron not found\n";
        } else break;
}

while(true) {
        author.name = getString("Enter author name:\n");
        authorRef = find(catalog[author.name[0]].begin(), catalog[author.name[0]].end(), author);
        if (authorRef == catalog[author.name[0]].end()) {
                cout << "Author not found\n";
        } else break;
}

while(true) {
        book.title = getString("Enter book title:\n");
        bookRef = find((*authorRef).books.begin(), (*authorRef).books.end(), book);
        if (bookRef == (*authorRef).books.end()) {
                cout << "Book not found\n";
        } else break;
}


// update CheckedOutBook
CheckedOutBook cbk(authorRef, bookRef);
(*bookRef).patron = 0;
(*patronRef).books.remove(cbk);

}

int menu() {
	int option;
	cout << "\n Enter one of the following options (enter number):\n" <<
		"1. Include a book in catalog \n" <<
		"2. Return a book\n" << "3. Checkout a book\n" <<
		"4. Status\n" << "5. Exit\n"
		"Your option?\n";
	cin >> option;
	cin.get();
	return option;
}

int main() {
	while (true) {
		switch(menu()) {
			case 1: includeBook(); break;
			case 2: returnBook(); break;
			case 3: checkOutBook(); break;
			case 4: status(); break;
			case 5: return 0; break;
			default: cout << "Wrong option, try again: ";
		}
	}
}
