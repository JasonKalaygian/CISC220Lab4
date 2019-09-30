/*
 * main.cpp
 *
 *  Created on: Sep 25, 2019
 *      Author: jayka
 */

#include "book.h"
#include <iostream>
#include <stdlib.h>
using namespace std;
//Declaration of findBestBook method
void findBestBook(Book *myBooks);
int main(){
	//integer arrays of ratings are made for each book prior to building the Book object
	int harryRatings[10] = {9,8,9,8,7,9,8,6,7,10};
	Book harryPotter("Harry Potter","J.K","Rowling",1997,harryRatings);
	int martianRatings[10] = {9,9,9,9,9,9,9,8,10,10};
	Book martian("The Martian","Andy","Weir",2011,martianRatings);
	int theStandRatings[10] = {6,5,6,7,6,5,4,8,6,5};
	Book theStand("The Stand","Stephen","King",1978,theStandRatings);
	int toKillAMockingBirdRatings[10] = {1,2,5,3,2,1,2,3,6,4};
	Book toKillAMockingBird("To Kill a Mockingbird","Harper","Lee",1960,toKillAMockingBirdRatings);
	int catch22Ratings[10] = {7,8,7,8,7,8,6,5,9,8};
	Book catch22("Catch 22","Joseph","Heller",1961,catch22Ratings);
	//myBooks array is created on the stack
	Book myBooks[5] = {harryPotter,martian,theStand,toKillAMockingBird,catch22};
	findBestBook(myBooks);
	int hungerGamesRatings[10] = {10,10,10,10,10,9,9,8,7,10};
	//Book object is created on the heap, is a pointer
	Book *hungerGames = new Book("Hunger Games","Suzanne","Collins",2000,hungerGamesRatings);
	hungerGames->printBookInfo();
	int kiteRunnerRatings[10] = {0,4,5,8,9,8,7,6,6,8};
	//Book object created on the heap, is a pointer
	Book *kiteRunner = new Book("Kite Runner","Khaled","Hosseini",2003,kiteRunnerRatings);
	//heapArray pointer uses the blank Book constructor to create an empty array of books on the heap
	Book *heapArray = new Book[2];
	heapArray[0] = *kiteRunner;
	heapArray[1] = *hungerGames;

	for(int i = 0; i < 2; i++){
		//Loop prints the info for both of the books in the array on the heap
		heapArray[i].printBookInfo();
	}
	return(0);
}

void findBestBook(Book *myBooks){
	/*
	 * Parameters: Book *myBooks (an array of book objects)
	 * returns: none
	 * This function iterates through an array of book objects, compares each book to the current
	 * highest rated book until it completes the array and identifies the highest rated book. That
	 * book's info is then printed with the printBookInfo method
	 */
	Book topBook = myBooks[0];
	for(int i = 1; i < 5; i++){
		if(topBook.operator <(myBooks[i])){
			topBook = myBooks[i];
		}
	}

	topBook.printBookInfo();
}


