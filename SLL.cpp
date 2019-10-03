/*
 * SLL.cpp
 *
 *  Created on: Sep 22, 2019
 *      Author: roel
 */
#include <stdlib.h>
#include <iostream>
using namespace std;
#include "SLL.hpp"

SLL::SLL(){
	/*
	 * Parameters: none
	 * Returns: none
	 * Description: this method is a constructor for the SLL class. The constructor creates an object and initializes first and
	 * last to NULL and makes the size 0;
	 */
	first = NULL;
	last = NULL;
	size = 0;
}

SLL::~SLL(){
	/*
	 * Parameters: none
	 * Returns: none
	 * Description: this method is a deconstructor. this method automatically deletes the SLL object that was created after
	 * it was used completely.
	 */
	cout <<"deleted each node in 11" << endl;
}

void SLL::printSLL(){
	/*
	 * Parameters: none
	 * Returns: none
	 * Description: this method prints out the current linked list by showing the rating, then the comments.
	 */
	SNode *tmp = first;
	while (tmp != NULL) {
		tmp->printNode();
		tmp = tmp->next;
	}
	cout << endl;
}

void SLL::insertInOrder(int r, string s){
	/*
	 * Parameters: Integer, String
	 * Returns: none
	 * Description: this method organizes the current linked list by organizing the list by the node's integer value. the node
	 * with the lowest integer value is placed in the front of the linked list and the  node with the greatest integer value is
	 * placed at the end of the linked list. if there is no node in the linked list, the node is placed at the front of the
	 * linked list.
	 */
	if(first == NULL){
		addFirst(r,s);
	}
	else if(r < first->rating){
		addAtFront(r,s);
	}
	else if(r > last->rating){
		push(r,s);
	}
	else{
		SNode *tmp = first;
		SNode *insert = new SNode(r,s);
		for(int i = 0; i < size; i++) {
			if(tmp->rating < r && tmp->next->rating > r){
				insert->next = tmp->next;
				tmp->next = insert;
				break;
			}
			if(insert->rating == tmp->next->rating){
				insert->next = tmp->next;
				tmp->next = insert;
				break;
			}
			tmp = tmp->next;
		}
		size++;
	}
}

void SLL::push(int r, string s){
	/*
	 * Parameters : Integer, String
	 * Returns: none
	 * Description: this method creates a new node object that hold the Integer and String value in the object and adds that
	 * node to the end of the linked list. the size is incremented when the node is added to the linked list.
	 */
	SNode *p = new SNode(r,s);
	last -> next = p;
	last = p;
	size++;
}

void SLL::addAtFront(int r, string s){
	/*
	 * Parameters: Integer, String
	 * Returns: none
	 * Description: this method creates a new node object that takes in the methods parameter values and places the new node at the
	 * front of the list. this method also increases the size of the linked list when the object is added to the linked list.
	 */
	SNode *newNode = new SNode(r,s);
	newNode->next = first;
	first = newNode;
	size++;
}
void SLL::addFirst(int r, string s){
	/*
	 * Parameters: Integer, String
	 * Returns: none
	 * Description: this method adds the first node to the linked list by assigning the fist and last value to the new node.
	 * this method also increases the size of the linked list by 1 when the node is created.
	 */
	size++;
	first = new SNode(r,s);
	last = first;
}

int SLL::pop(){
	/*
	 * Parameters: none
	 * Returns : none
	 * Description: this method 'pops' off the last node in the linked list. in order to delete the last node you must
	 * traverse through the linked list and delete the second to last node's next value(the address of the last node in the linked list
	 */
	int hold;
    SNode *currNode = first;
    while (currNode->next->next != NULL)
    {
     currNode = currNode->next;
    }
    hold = currNode->next->rating;
    delete currNode->next;
    currNode->next = NULL;
    size--;
	return hold;

}

double SLL::getAve(){
	/*
	 * Parameters:none
	 * Returns: Double
	 * Description: this method traverses through the list and calculates the average rating that is in the linked list. this
	 * average rating is a Double and is returned to the method.
	 */
	SNode *temp = first;
	double avg =0;

	while(temp->next != NULL){
		avg += temp->rating;
		temp = temp->next;
	}
	avg += temp->rating;
	avg /= size;
	return avg;
}
/*
int main() {
	int r[10] = {9,8,4,5,11,10,3,6,8,2};
	string s[10] = {"really good!","loved it","mediocre", "okay, not great","best book ever!", "awesome!",
			"boring","not bad","definitely worth reading", "terrible!"};
	SLL *list = new SLL();
	for (int i = 0; i < 10; i++) {
		list->insertInOrder(r[i],s[i]);
		list->printSLL();
	}

	cout << "Ave: "<< list->getAve() << endl;
	cout << "Popping " << list->pop() << endl;
	list->printSLL();
	cout << "Popping " << list->pop() << endl;
	list->printSLL();
	delete list;
	return 0;

}
*/
