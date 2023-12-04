#include "book.h"
#include <fstream>
Book::Book(std::string author, std::string name, unsigned year) : book_author(author), book_name(name), book_year(year)
{};

Book::Book(const Book& B) : book_author(B.book_author), book_name(B.book_name), book_year(B.book_year)
{}

Book::~Book()
{}

List::List(Book B, List* l) : book(B), link(l)
{};

string Book::getAuthor() const
{
	return book_author;
}
string Book::getName() const
{
	return book_name;
}
unsigned Book::getYear() const
{
	return book_year;
}
void Book::setAuthor(string author)
{
	book_author = author;
}
void Book::setName(string name)
{
	book_name = name;
}
void Book::setYear(unsigned year)
{
	book_year = year;
}

void Book::print() const
{
	cout << "Author: " << getAuthor()
	<< " -- Book name \"" << getName() << "\""
	<< " -- Year of publication - " << getYear();
}

void Book::WriteTo(ostream& out) const
{
	out << book_author << endl << book_name << endl << book_year << endl;
}
void Book::ReadFrom(istream& in)
{
	in.get();
	getline(in, book_author);
	getline(in, book_name);
	in >> book_year;
}

ostream& operator<< (ostream& out, Book B)
{
	B.WriteTo(out);
	return out;
}

istream& operator>> (istream& in, Book& B)
{
	B.ReadFrom(in);
	return in;
}
Book* createArr(const string& filename, size_t& arrSize)
{
	ifstream fin(filename);
	fin >> arrSize;
	Book* arr = new Book[arrSize];
	for (size_t i = 0; i < arrSize; ++i)
	{
		fin >> arr[i];
	}
	fin.close();
	return arr;
}

void printArr(Book* arr, size_t n)
{
	for (size_t i = 0; i < n; ++i)
	{
		arr[i].print();
		cout << endl;
	}
}

void showBooks(string author, Book* arr, size_t n)
{
	bool flag = false;
	while (!flag)
	{
		for (size_t i = 0; i < n; ++i)
		{
			if (arr[i].getAuthor() == author)
			{
				flag = true;
				break;
			}
		}
		if (flag) break;
		cout << "There is no author with that name\nEnter autor name again\n";
		getline(cin, author);
	}
	cout << "All " << author << "'s books:\n";
	for (size_t i = 0; i < n; ++i)
	{
		if (arr[i].getAuthor() == author)
		{
			cout << arr[i].getName() << endl;
		}
	}
}

unsigned countBooks(unsigned year, Book* arr, size_t n)
{
	unsigned counter = 0;
	for (size_t i = 0; i < n; ++i)
	{
		if (arr[i].getYear() == year) ++counter;
	}
	return counter;
}

void sortByList(Book* arr, size_t n)
{
	List* list = nullptr;
	Book temp;
	List phanthom(temp, list);
	List* curr;
	for (size_t i = 0; i < n; ++i)
	{
		curr = &phanthom;
		while (curr->link != nullptr && curr->link->book.getAuthor() < arr[i].getAuthor()) curr = curr->link;
		curr->link = new List(arr[i], curr->link);
	}
	curr = phanthom.link;
	for (size_t i = 0; i < n; ++i,curr = curr->link)
	{
		arr[i] = curr->book;
	}
	removeList(phanthom.link);

}

void removeList(List* P)
{
	while (P != nullptr)
	{
		List* victim = P;
		P = P->link;
		delete victim;
	}
}

void WriteToFile(Book* arr, size_t n, string filename)
{
	ofstream fout(filename);
	fout << n << '\n';
	for (size_t i = 0; i < n; ++i)
	{
		fout << arr[i];
	}
	fout.close();
}



