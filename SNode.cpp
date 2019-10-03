/*
 * SNode.cpp
 *
 *  Created on: Sep 22, 2019
 *      Author: roel
 */
#include <stdlib.h>
#include <iostream>
#include "SNode.hpp"
using namespace std;

SNode::SNode(){
	/*
	 * Parameters: none
	 * Returns: none
	 * Description: this is a constructor for the SNode class. when this constructor is called, is first asks for the rating value, then
	 * assigns the input value to the rating variable(Integer). then it then asks for the comments, then assigns that input value
	 * to the the comments variable(string). once both inputs have been completed, the next is set to NULL.
	 */
	int x;
	cout << "what is your rating?" << endl;
	cin >> x;
	rating = x;
	cout << "what are your comments?" << endl;
	cin >> comments;
	next = NULL;
}
SNode::SNode(int i, string s){
	/*
	 * Parameters: Integer, String
	 * Returns: None
	 * Description: this is a constructor for the SNode class. this constructor assigns the rating variable to the Integer value, i,
	 * in the parameter, and assigns the comments variable to the String value, s, in the parameter. the next variable is also
	 * Initialized to NULL.
	 */
	rating = i;
	comments = s;
	next = NULL;
}

SNode::~SNode() {
	/*
	 * Parameters: none
	 * Returns: none
	 * Description: this is a deconstructor for the SNode class. this method automatically deletes the SNode object after is is done
	 * being completely used. this destructor is called inside the pop() funtion when you delete the last node in linked list and prints out
	 * the rating and comments of the last node in the linked list.
	 */

	cout<<this->rating<<endl;
	cout << "removing " << this->rating << ", " << this->comments << endl;
	cout << "deleting " << this->rating << ", " << this ->comments << endl;
}

void SNode::printNode(){
	/*
	 * Parameters: none
	 * Returns: none
	 * Description: this method prints out the rating and comment value of the node object that is created;
	 */
	cout <<"rating: " << rating << ", comments: " << comments <<  endl;
}

