#include <iostream>
#include "lab07_library.hpp"


using namespace std;

bool test_book_insertion() {
	
	//Making a book and library instance
	Book book;
	Book book2("Title", "Author");
	Book book3("Title", "Author", "DOP");
	Library test_library;
	
	//inserting the books in the library (using all parameter options)
	test_library.insert_book(book);
	test_library.insert_book(book2);
	test_library.insert_book(book3);
	
	//trying to insert the same book twice
	test_library.insert_book(book3);

	//outputting all of the books
	test_library.print();
	return true;
}

bool test_book_removal() {
	
	//Making a book and library instance
	Book book;
	Book book2("Title", "Author");
	Library test_library;
	
	//inserting books to remove
	test_library.insert_book(book);
	test_library.insert_book(book2);
	test_library.insert_book("Title", "Author", "DOP");
	
	//remove certain books
	test_library.remove_book(book);
	test_library.remove_book("Title", "Author", "DOP");
	
	//try removing something that is not in the library
	test_library.remove_book("Archan", "Patel", "DOP");
	test_library.print();
	return true;
}

bool run() {
	
	//result of test
	bool test_results = true;
	
	//run insertion and removal
	test_results = test_results && test_book_insertion();
	test_results = test_results && test_book_removal();
	
	return test_results;
}

int main() {	
	cout << (run() ? "All tests passed." : "Some tests failed.");
			
	return 0;
}
