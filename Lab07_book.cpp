#include <iostream>
#include "lab07_book.hpp"

using namespace std;

Book::Book() : title("n/a"), 
               authors("n/a"), 
			   date_of_publication("n/a") {
}	

// code for the three parametric constructors

Book::Book (string new_title, string new_authors) :
	title(new_title), authors(new_authors), date_of_publication("n/a")
{
}
Book::Book (string new_title, string new_authors, string new_dop) :
	title(new_title), 
    authors(new_authors), 
	date_of_publication(new_dop)
{
}
string Book::get_title() {
	return title;
}

string Book::get_authors() {
	return authors;
}

string Book::get_dop() {
	return date_of_publication;
}

void Book::print() {
	cout << "The title of the book is: " << title << endl;
	cout << "The author of the book is: " << authors << endl;
	cout << "The date of publication of the book is: " << date_of_publication << endl;
}	
