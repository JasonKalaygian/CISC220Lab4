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
	//put fields here
	string firstName;
	string lastName;
	int *ratings = new int[10];
	string title;
	int year;
public:
	//put method declarations here
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
