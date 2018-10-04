#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
using namespace std;

/*Declare struct of node*/
struct Node
{
	int data;
	struct Node *next;
};

/*Declare function*/
void init(struct Node **head);
void insert(struct Node **head, int key);
void print(struct Node **head);
void freeList(struct Node **head);
int getNodeFromHead(struct Node **head, int index); //Question 1
int findMiddleNode(struct Node **head);				//Question 2
int getNodeFromTail(struct Node **head, int index);	//Question 3
int countNumberOfKey(struct Node **head, int key);	//Question 4
void reverseLinkedList(struct Node **head);			//Question 5
int isPalindrome(struct Node **head);				//Question 6
void printReverse(struct Node **head);				//Question 7

#endif