#include "Day4.h"
#include <stdio.h>
#include <stdlib.h>

void init(struct Node **head)
{
	*head = NULL;
}

void insert(struct Node **head, int key)
{
	struct Node *p = (struct Node*)malloc(sizeof(struct Node));
	p->data = key;
	p->next = NULL;
	if(*head == NULL)
	{
		*head = p;
	}
	else
	{
		p->next = *head;
		*head = p;
	}
}

void print(struct Node **head)
{
	struct Node *p;
	for(p = *head; p != NULL; p = p->next)
	{
		printf("%d ", p->data);
	}
}

void freeList(struct Node **head)
{
	if(*head == NULL)
	{
		return;
	}
	struct Node *p, *tmp;
	for(p = *head; p != NULL;)
	{
		tmp = p->next;
		free(p);
		p = tmp;
	}
	*head = NULL;
}

/*Question 1:*/
void moveLastToFront(struct Node **head)
{
	if(*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	struct Node *p = *head;
	while(p->next->next != NULL)
	{
		p = p->next;
	}
	p->next->next = *head;
	*head = p->next;
	p->next = NULL;
	
	/*struct Node *p = *head;
	while(p->next->next != NULL)
	{
		p = p->next;
	}
	struct Node *headnext = (*head)->next;
	struct Node *tailprev = p;
	struct Node *tail = p->next;
	tailprev->next = *head;
	tailprev->next->next = NULL;
	tail->next = headnext;
	(*head) = tail;*/
}

/*Question 2*/
void pairwipeSwap(struct Node **head)
{
	if((*head) == NULL || (*head)->next == NULL)
	{
		return;	
	}	
	struct Node *p = *head;
	struct Node *nextnode = NULL;
	(*head) = p->next;
	while(p != NULL && p->next != NULL)
	{
		struct Node *nextpair = p->next->next;
		 p->next->next = p;
		if(nextnode != NULL)
		{
			nextnode->next = p->next;
		}
		p->next = nextpair;
		nextnode = p;
		p = nextpair;
	}
}										

/*Question 3*/
void intersectionSorted(struct Node **head1, struct Node **head2, struct Node **head3)
{
	struct Node *p1 = *head1;
	struct Node *p2 = *head2;
	while(p1 != NULL && p2 != NULL)
	{
		if((p1->data) < (p2->data))
		{
			p1 = p1->next;
		}
		else if((p1->data) > (p2->data))
		{
			p2 = p2->next;
		}
		else //p1->data == p2->data
		{
			insert(head3, p1->data);
			p1 = p1->next;
			p2 = p2->next;
		}
	}
}

/*Question 4*/
void deleteAlternateNodes(struct Node **head)
{
	if(*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	struct Node *p = *head;
	while(p != NULL && p->next != NULL)
	{
		struct Node *tmp = p->next->next;
		free(p->next);
		p->next = tmp;
		p = tmp;
	}	
}

/*Question 5*/
void alternatingSplit(struct Node **head1, struct Node **head2, struct Node **head3)
{
	
}

/*Question 6*/
int isIdentical(struct Node **head1, struct Node **head2)
{
	if(*head1 == NULL && *head2 == NULL)
	{
		return 1;
	}
	if((*head1 == NULL && *head2 != NULL) || (*head1 != NULL && *head2 == NULL))
	{
		return 0;
	}
	else //*head1 != NULL && *head2 != NULL
	{
		struct Node *p1 = *head1;
		struct Node *p2 = *head2;
		while(p1 != NULL && p2 != NULL)
		{
			if(p1->data != p2->data)
			{
				return 0;
			}
			p1 = p1->next;
			p2 = p2->next;
		}
		if((p1 == NULL && p2 != NULL) || (p1 != NULL && p2 == NULL))
		{
			return 0;
		}
	}
	return 1;
}
