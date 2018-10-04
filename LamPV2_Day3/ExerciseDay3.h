#ifndef _EXERCISE_DAY3_H_
#define _EXERCISE_DAY3_H_
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

/*Declare node struct*/
struct Node
{
	int data;
	struct Node *next;
};

/*Declare function*/
void init(struct Node **head);						/*Init a Linked List*/
void insert(struct Node **head, int key);			/*Insert a new node into Linked List*/
void printList(struct Node **head);					/*Print Linked List from head node*/
void freeLinkedList(struct Node **head);			/*Delete Linked List and free memory*/
int getNodeFromHead(struct Node **head, int index); /*Question 1*/
int findMiddleNode(struct Node **head);				/*Question 2*/
int getNodeFromTail(struct Node **head, int index);	/*Question 3*/
int countNumberOfKey(struct Node **head, int key);	/*Question 4*/
void reverseLinkedList(struct Node **head);			/*Question 5*/
int isPalindrome(struct Node **head);				/*Question 6*/
void printReverse(struct Node **head);				/*Question 7*/

#endif /*end of file*/
