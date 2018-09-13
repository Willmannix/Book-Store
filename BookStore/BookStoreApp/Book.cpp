#include "stdafx.h"
#include "Book.h"


Book::Book()
	: m_Price(0)
	, m_ISBN("")
	, m_Author("")
	, m_Title("")
	


{
}


Book::~Book()
{
}


void Book::SetISBN(string isbn)
{
	m_ISBN = isbn;
}


void Book::SetBookTitle(string title)
{
	m_Title = title;
}


void Book::SetAuthor(string author)
{
	m_Author = author;
}


void Book::SetBookPrice(double bookPrice)
{
	m_Price = bookPrice;
}


string Book::GetISBN() const
{
	return m_ISBN;
}


string Book::GetBookTitle() const
{
	return m_Title;
}


string Book::GetAuthor() const
{
	return m_Author;
}


double Book::GetBookPrice() const
{
	return m_Price;
}


void Book::GetUserInput(vector<Book>& books) 
{
	string isbn, title, author;
	double price;

	cout << "\n\n\tPlease eneter book ISBN : ";
	cin >> isbn;
	cout << "\tPlease enter book title : ";
	cin >> title;
	cout << "\tPlease enter book author: ";
	cin >> author;
	cout << "\tPlease enter book price : ";
	cin >> price;
	system("cls");
	Book newBook(isbn, title, author, price);
	books.push_back(newBook);

	cout << "\n\n\t SAVED!";
	cin.get();
	cin.get();

}


void Book::DisplayBookDetails()
{
	cout << "\t" <<    "Book ISBN  :" << setw(15) << GetISBN()
	<< "\n" << "\t" << "Book Title :" << setw(15) << GetBookTitle()
	<< "\n" << "\t" << "Book Author:" << setw(15) << GetAuthor()
	<< "\n" << "\t" << "Book Price :" << setw(15) << GetBookPrice() << "\n";
}


Book::Book(string ISBN, string title, string author, double price)
	: m_ISBN(ISBN)
	, m_Title(title)
	, m_Author(author)
	, m_Price(price)
{
}


void Book::UpdateBook(Book& book, double price)
{


	book.SetBookPrice(price);
	
}
