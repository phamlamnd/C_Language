#ifndef _DAY4_H_
#define _DAY4_H_

struct Node{
	int data;
	struct Node *next;
};

void init(struct Node **head);
void insert(struct Node **head, int key);
void print(struct Node **head);
void freeList(struct Node **head);
void moveLastToFront(struct Node **head);												/*Question 1*/
void pairwipeSwap(struct Node **head);													/*Question 2*/
void intersectionSorted(struct Node **head1, struct Node **head2, struct Node **head3);	/*Question 3*/
void deleteAlternateNodes(struct Node **head);											/*Question 4*/
void alternatingSplit(struct Node **head1, struct Node **head2, struct Node **head3);	/*Question 5*/
int isIdentical(struct Node **head1, struct Node **head2);								/*Question 6*/

#endif
