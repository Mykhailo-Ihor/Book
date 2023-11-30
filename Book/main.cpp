#include "book.h"
#include <fstream>
int main()
{
	size_t n;
	Book* Authors = createArr("Data.txt", n);
	printArr(Authors,n);
	cout << "Enter author's name:\n";
	string author;
	getline(cin, author);
	showBooks(author, Authors, n);
	cout << "Enter year of publication:\n";
	unsigned year;
	cin >> year;
	cout << "Number of books publicated in this year is " << countBooks(year, Authors, n);
	sortByList(Authors,n);
	cout << "\nCheck your files...\n";
	WriteToFile(Authors, n, "Authors.txt");
	return 0;
}