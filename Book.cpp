/*
 * Book.cpp
 *
 *  Created on: Sep 25, 2019
 *      Author: jayka
 */
#include "book.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

Book::Book(){
	/*
	 * Parameters: None
	 * This blank constructor had to be made in order to create a Book array on the heap. When the array gets declared
	 * in the main I do not immediately assign book objects, so without a blank constructor the array would not have
	 * any means to make an empty array of blank book objects
	 */
	//all parameters are initialized to blank strings and zero
	firstName = "";
	lastName = "";
	year = 1;
	int rating[10] = {0,0,0,0,0,0,0,0,0,0};
	ratings = &rating[0];
	title = "";
}

Book::Book(string bookTitle, string first, string last, int published){
	/*
	 * Parameters: strings for bookTitle, first, last, int for published
	 * This constructor sets the firstName, lastName, bookTitle and year fields
	 * to those passed to the constructor and initializes an array of zeros for
	 * the ratings
	 */
	firstName = first;
	lastName = last;
	year = published;
	int rating[10] = {0,0,0,0,0,0,0,0,0,0};
	//RECALL: ratings is on the heap
	ratings = &rating[0];
	title = bookTitle;
}

Book::Book(string bookTitle,string first, string last, int published, int *arr){
	/*
	 * Parameters: strings for bookTitle, first, last, integer published and integer array *arr
	 * This constructor assigns the firstName, lastName, year, title, and ratings array to what is
	 * passed to this constructor.
	 */
	firstName = first;
	lastName = last;
	year = published;
	ratings = arr;
	title = bookTitle;
}

Book::~Book(){
	//Destructor, deletes book objects on the stack to prevent memory leak
	cout << "Book is destroyed" << endl;
}

double Book::avgRating(){
	/*
	 * Parameters: None
	 * Returns: double
	 * This function iterates through the ratings array for the book it is called with, and returns
	 * the avg as a double.
	 */
	double avg = 0;
	//There are always 10 ratings, no need to pass a size parameter
	for(int i = 0; i < 10; i++){
		avg = avg + this->ratings[i];
	}
	avg = avg/10;

	return avg;
}

void Book::printRating(){
	/*
	 * Parameters: None
	 * Returns: none
	 * This function is called with a given book object. The avgRating() function is called
	 * for the given book. If the average rating is zero that means the book has not been rated
	 * and a print statement informs the reader. If the average rating is non zero then the average
	 * rating is printed
	 */
	if(this->avgRating() == 0){
		cout << "This book has not been rated yet" << endl;
	}

	else{
		cout << "This book was rated: " << this->avgRating() << endl;
	}
}

void Book::printBookInfo(){
	/*
	 * Parameters: none
	 * Returns: none
	 * This function prints the author name, publishing year and average rating
	 * when called with a book object.
	 */
	cout << "Author name: " << this->firstName << " " << this->lastName << endl;
	cout << "Year Published: " << this->year << endl;
	cout << "Average Rating: ";
	this->printRating();
}

bool Book::operator <(Book myBook){
	/*
	 * Parameters: Book object myBook
	 * Returns: boolean
	 * This method overrides the operator < by directly comparing the average rating of the book
	 * that the method is called with and the book that is passed as the parameter. If the book that
	 * is called with is smaller than the book passed as a parameter then it returns true, otherwise it returns
	 * false.
	 */
	if(this->avgRating() < myBook.avgRating()){
		return true;
	}
	else{
		return false;
	}
}





