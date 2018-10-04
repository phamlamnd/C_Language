/*Define function already declare in header file ExerciseDay3.h*/

#include "ExerciseDay3.h"

/*Init a Linked List*/
void init(struct Node **head)
{
	*head = NULL;
}

/*Insert a new node into Linked List*/
void insert(struct Node **head, int key)
{
	struct Node *p = (struct Node*)malloc(sizeof(struct Node));
	p->data = key;
	p->next = NULL;
	if (*head == NULL)
	{
		*head = p;
	}
	else
	{
		p->next = *head;
		*head = p;
	}
}

/*Print Linked List from head node*/
void printList(struct Node **head)
{
	struct Node* p;
	for (p = *head; p != NULL; p = p->next)
	{
		printf("%d ", p->data);
	}
}

/*Delete Linked List and free memory*/
void freeLinkedList(struct Node **head)
{
	struct Node *p = *head;
	struct Node *tmp;
	while (p != NULL)
	{
		tmp = p->next;
		free(p);
		p = tmp;
	}
	*head = NULL;
}


/*Question 1: Write a function to get Nth node in a Linked List:
Write a GetNth() function that takes a linked list 
and an integer index and returns the data value stored in the node at that index position.*/
int getNodeFromHead(struct Node **head, int index)
{
	int i;
	struct Node *p;
	for (i = 0, p = *head; p != NULL; i++, p = p->next)
	{
		if (i == index)
		{
			return p->data;
		}
	}
}

/*Question 2: Find the middle of a given linked list:
Given a singly linked list, find middle of the linked list.*/
int findMiddleNode(struct Node **head)
{
	struct Node* p = *head;
	int size = 0;
	while (p != NULL)
	{
		p = p->next;
		size++;
	}

	int i = 0;
	p = *head;
	while (i != size/2)
	{
		p = p->next;
		i++;
	}
	return p->data;
}

/*Question 3: Program for n’th node from the end of a Linked List
Given a Linked List and a number n, write a function that returns 
the value at the n’th node from end of the Linked List.*/
int getNodeFromTail(struct Node **head, int index)
{
	struct Node *p = *head;
	int size = 0;
	while (p != NULL)
	{
		p = p->next;
		size++;
	}

	int i = 0;
	p = *head;
	while (i != (size - index))
	{
		i++;
		p = p->next;
	}
	return p->data;
}

/*Question 4: Write a function that counts the number of times a given int occurs in a Linked List
Given a singly linked list and a key, count number of occurrences of given key in linked list.*/
int countNumberOfKey(struct Node **head, int key)
{
	struct Node *p;
	int count = 0;
	for (p = *head; p != NULL; p = p->next)
	{
		if (key == p->data)
		{
			count++;
		}
	}
	return count;
}

/*Question 5: Reverse a linked list
Given pointer to the head node of a linked list, the task is to reverse the linked list. 
We need to reverse the list by changing links between nodes.*/
void reverseLinkedList(struct Node **head)
{
	struct Node *p = *head;
	struct Node *prev = NULL;
	struct Node *tmp;
	while (p != NULL)
	{
		tmp = p->next;
		p->next = prev;
		prev = p;
		p = tmp;
	}
	*head = prev;
}

/*Question 6: Function to check if a singly linked list is palindrome
Given a singly linked list of characters, 
write a function that returns true if the given list is palindrome, else false.*/
int isPalindrome(struct Node **head)
{
	struct Node *left = *head;
	struct Node *right = NULL;
	struct Node *p;
	while (left != right)
	{
		p = left;
		while (p->next != right)
		{
			p = p->next;
		}
		if (left->data != p->data)
		{
			return 0;
		}
		left = left->next;
		right = p;
	}
	return 1;
}


/*Question 7: Print reverse of a Linked List without actually reversing:
Given a linked list, print reverse of it using a recursive function.*/
void printReverse(struct Node **head)
{
	if (*head == NULL) return;
	printReverse(&((*head)->next));
	printf("%d ", (*head)->data);
}
