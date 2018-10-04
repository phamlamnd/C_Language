#include <stdio.h>
#include <conio.h>
#include "ExerciseDay3.h"

int main()
{
	struct Node *head;
	init(&head);
	
	insert(&head, 14);
	insert(&head, 30);
	insert(&head, 10);
	insert(&head, 1);	
	printList(&head);
	
	/*Test for question 1*/
	int index = 2;
	int value = getNodeFromHead(&head, index);
	printf("\nThe node at index %d is: %d", index, value);
	
	/*Test for question 2*/
	int midNode = findMiddleNode(&head);
	printf("\nMiddle of the linked list is: %d", midNode);
	
	/*Test for question 3*/
	int position = 3;
	int data = getNodeFromTail(&head, position);
	printf("\nValue at %d node from end of the linked list is:  %d", position, data);
	
	/*Test for question 4*/
	int key = 1;
	int numberKey = countNumberOfKey(&head, key);
	printf("\nNumber of occurrences of given key is: %d", numberKey);
	
	/*Test for question 5*/
	reverseLinkedList(&head);
	printf("\nReverse linked list: ");
	printList(&head);
	
	/*Test for question 6*/
	int check = isPalindrome(&head);
	if(check == 1)
	{
		printf("\nIs palindrome");
	}
	else
	{
		printf("\nNot palindrome");
	}
	
	/*Test for question 7*/
	printf("\nReverse using a recursive function: ");
	printReverse(&head);
	
	/*Free linked list*/
	freeLinkedList(&head);
	
	getch();
	return 0;
}
