#pragma once
#include <string>
#include <iostream>
using namespace std;
class Book
{
private:
	string book_author;
	string book_name;
	unsigned book_year;
public:
	Book(string author = "", string name = "", unsigned year = 0);
	Book(const Book& B);
	~Book();
	string getAuthor() const;
	string getName() const;
	unsigned getYear() const;
	void setAuthor(string author);
	void setName(string name);
	void setYear(unsigned year);
	void print();
	void WriteTo(ostream& out) const;
	void ReadFrom(istream& in);
};

struct List
{
	Book book;
	List* link;
	List(Book B, List* l = nullptr);
};
ostream& operator<< (ostream& out, Book B);
istream& operator>> (istream& in, Book& B);
Book* createArr(const string& filename, size_t& arrSize);
void printArr(Book* arr, size_t n);
void showBooks(string author, Book* arr, size_t n);
unsigned countBooks(unsigned year, Book* arr, size_t n);
void sortByList(Book* arr, size_t n);
void removeList(List* P);
void WriteToFile(Book* arr, size_t n, string filename);