#include <iostream>
#include "lab07_library.hpp"


using namespace std;

Library::Library() {}

//Constructors

Library::Library(vector<Book> new_books) :
books(new_books){	
}

void Library::print()
{
	for (int i = 0; i < books.size(); i++)
	{
		cout << "Book number " << i << ":\n";
		books.at(i).print();
		cout << endl;
	}
}

bool Library::insert_book(string new_title, string new_authors, string new_dop)
{
	bool match = false;
	Book new_book(new_title, new_authors, new_dop);
	
	for (int i = 0; i < books.size(); i++)
	{
		if (new_title == books.at(i).get_title())
		{
			if (new_authors == books.at(i).get_authors())
			{
				if (new_dop == books.at(i).get_dop())
				{
					match = true;
				}
			}
		}
	}
	if (match)
		return false;
	else
	{
		books.push_back(new_book);
		return true;
	}
}

bool Library::insert_book(Book new_book)
{
	bool match = false;
	
	for (int i = 0; i < books.size(); i++)
	{
		if (new_book.get_title() == books.at(i).get_title())
		{
			if (new_book.get_authors() == books.at(i).get_authors())
			{
				if (new_book.get_dop() == books.at(i).get_dop())
				{
					match = true;
				}
			}
		}
	}
	
	if (match)
		return false;
	else
	{
		books.push_back(new_book);
		return true;
	}
}

bool Library::remove_book(string cur_title, string cur_authors, string cur_dop)
{
	bool match = false;
	int counter = 0;
	Book new_book(cur_title, cur_authors, cur_dop);
	
	for (int i = 0; i < books.size(); i++)
	{
		if (cur_title == books.at(i).get_title())
		{
			if (cur_authors == books.at(i).get_authors())
			{
				if (cur_dop == books.at(i).get_dop())
				{
					match = true;
				}
			}
		}
		counter = i;
	}
	
	if (match)
	{
		books.erase(books.begin() + counter);
		return true;
	}
	else
	{
		return false;
	}
}

bool Library::remove_book(Book cur_book)
{
	bool match = false;
	int counter = 0;
	
	for (int i = 0; i < books.size(); i++)
	{
		if (cur_book.get_title() == books.at(i).get_title())
		{
			if (cur_book.get_authors() == books.at(i).get_authors())
			{
				if (cur_book.get_dop() == books.at(i).get_dop())
				{
					match = true;
				}
			}
		}
		counter = i;
	}
	
	if (match)
	{
		books.erase(books.begin() + counter);
		return true;
	}
	else
	{
		return false;
	}
}
