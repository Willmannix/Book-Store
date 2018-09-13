

#include "stdafx.h"
#include "Book.h"

using namespace std;

void DisplayMenu();
int Menu();
void DisplayBooks();
void Quit();
int SearchBook(vector<Book>& booklist);
void UpdateBook(vector<Book>& booklist);
void DeleteBook(vector<Book>& booklist);
bool BookFound(string isbn);
bool BookListEmpty();
void SortBookList();
bool SortBookOrder(Book& book1, Book& book2);

bool quitFlag = false;
bool empty = false;
vector<Book> bookList;

int _tmain(int argc, _TCHAR* argv[])
{
	
	DisplayMenu();
	
	return 0;
}


void DisplayMenu()
{
	Book myNewBook;
	do
	{
		system("cls");
		switch (Menu())
		{
		case 1:
			system("cls");
			myNewBook.GetUserInput(bookList);
			break;
		case 2:
			DisplayBooks();
			break;
		case 3:
			SearchBook(bookList);
			cin.get(); cin.get();
			break;
		case 4:
			UpdateBook(bookList);
			break;
		case 5:
			DeleteBook(bookList);
			break;
		case 6:
			Quit();
			break;
		}

	} while (!quitFlag);
}

int Menu()
{
	int option;
	cout << "\n\n\t1. Add book\n"
		<< "\t2. Display all books\n"
		<< "\t3. Search by ISBN\n"
		<< "\t4. Update book by ISBN\n"
		<< "\t5. Delete book details by ISBN\n"
		<< "\t6. Quit\n"
		<< "\n\tYour option: ";
		
	cin >> option;

	return option;
}

void DisplayBooks()
{
	
	
	cout << "\n";
	if (BookListEmpty())
		cout << "\n\n\tThere are no books to display.";
	else
	{
		
		//sort(bookList.begin(), bookList.end(), SortBookOrder);
		SortBookList();
		for each (Book book in bookList)
		{
			cout << endl;
			book.DisplayBookDetails();
			
		}
	}
	
	
	cin.get(); cin.get();
	
}

bool SortBookOrder(Book& book1, Book& book2)
{
	return book1.GetISBN() < book2.GetISBN();
}

void SortBookList()
{
	for each (Book book in bookList)
	{
		for (vector<Book>::size_type j = 1; j < bookList.size(); j++)
		{
			Book book1 = bookList[j - 1];
			Book book2 = bookList[j];
			string isbn1 = book1.GetISBN();
			string isbn2 = book2.GetISBN();

			if (isbn2.compare(isbn1) < 0)
			{
				Book newBook;
				newBook = book2;
				bookList[j] = book1;
				bookList[j - 1] = newBook;

			}
			
		}
	}

}

int SearchBook(vector<Book>& booklist)
{
	int pos=0;
	string isbn;
	if (BookListEmpty())
		cout << "\n\n\tThere are no books to display.";
	else
	{
		cout << "\n\tEnter ISBN of the book: ";
		cin >> isbn;
		cout << endl;
		
		if (!BookFound(isbn))
			cout << "\n\tThere is no such a book.";
		else
		{
			for each (Book book in booklist)
			{
				if (book.GetISBN() == isbn)
				{
					book.DisplayBookDetails();


					break;
				}
				pos++;
			}


		}

		
	}
	return pos;
}

void UpdateBook(vector<Book>& booklist)
{
	string isbn;
	if (BookListEmpty())
	{
		cout << "\n\n\tThere are no books.";
		cin.get(); cin.get();
	}
	else
	{
		cout << "\n\n\tEnter ISBN of the book: ";
		cin >> isbn;
		cout << endl;

		if (!BookFound(isbn))
		{
			cout << "\n\tThere is no such a book.";
			cin.get(); cin.get();
		}
		
		else
		{
			for (size_t i = 0; i < booklist.size(); i++)
			{
				if (booklist[i].GetISBN() == isbn)
				{
					booklist[i].DisplayBookDetails();
					cout << "\n\tIs this correct book? (y/n) : ";
					char input;
					cin >> input;
					if (input == 'Y' || input == 'y')
					{
						double price;
						cout << "\tEnter new Price : ";
						cin >> price;
						booklist[i].UpdateBook(booklist[i], price);
						cout << "\tSAVED!!";
						cin.get(); cin.get();
					}
					else
						DisplayMenu();
				}
			}
		}
		
	}
	
}

void DeleteBook(vector<Book>& booklist)
{
	
	if (BookListEmpty())
	{
		cout << "\n\n\tThere are no books.";
		cin.get(); cin.get();
	}
	else
	{
		int pos = SearchBook(booklist);
		cout << "\n\tIs this correct book? (y/n) : ";
		char input;
		cin >> input;
		if (input == 'Y' || input == 'y')
		{
			booklist[pos] = booklist[booklist.size() - 1];
			booklist.pop_back();
			cout << "\n\tDeleted!";
			cin.get(); cin.get();
		}
	}
	
}


void Quit()
{
	quitFlag = true;
}
bool BookListEmpty()
{
	string empty = false;
	system("cls");
	if (bookList.empty())
		return true;
	return false;
}
bool BookFound(string isbn)
{
	bool found = false;
	for each (Book book in bookList)
	{
		if (book.GetISBN() == isbn)
			found = true;
	}
	return found;
}
