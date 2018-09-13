#pragma once
using namespace std;
class Book
{
public:
	Book();
	~Book();
private:
	string m_ISBN;
	string m_Title;
	string m_Author;
	double m_Price;
public:
	// setters
	void SetISBN(string isbn);
	void SetBookTitle(string title);
	void SetAuthor(string author);
	void SetBookPrice(double bookPrice);
	// getters
	string GetISBN() const;
	string GetBookTitle() const;
	string GetAuthor() const;
	double GetBookPrice() const;
	//helper methods

	void GetUserInput(vector<Book>& books);
	void DisplayBookDetails();
	Book(string ISBN, string title, string author, double price);
	void UpdateBook(Book& book, double price);
};

