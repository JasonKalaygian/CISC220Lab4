/*
 * book.h
 *
 *  Created on: Sep 25, 2019
 *      Author: jayka
 */
#include <iostream>
#include <stdlib.h>
using namespace std;
#ifndef LAB4SRC_BOOK_H_
#define LAB4SRC_BOOK_H_
class Book{
	/*
	 * Fields: string first name, string last name, integer array for ratings (on the heap), string title, integer year
	 * Constructors: there are three, a blank constructor to initialize empty books, a constructor that accepts all fields
	 * except for the ratings array, and one that accepts all fields
	 * Methods: averageRating (returns double), printRating (returns none),printBookInfo (returns none), operator < (returns boolean),
	 * ~Book() is the destructor and deletes book objects
	 *
	 * The Book class creates Book objects with a title, author first and last name, publishing year and can accept or intilialize an
	 * array of ratings. Books are compared on the basis of their ratings in the operator method and the average rating, book information
	 * and book rating can be printed
	 */
	string firstName;
	string lastName;
	//initialized on the heap as instructed
	int *ratings = new int[10];
	string title;
	int year;
public:
	Book();
	Book(string bookTitle,string first, string last, int year);
	Book(string bookTitle,string first, string last, int year, int *arr);
	~Book();
	double avgRating();
	void printRating();
	void printBookInfo();
	bool operator <(Book myBook);
};




#endif /* LAB4SRC_BOOK_H_ */
