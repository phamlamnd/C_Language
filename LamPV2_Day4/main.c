#include "Day4.h"
#include <stdio.h>

int main()
{
	struct Node *head1, *head2, *head3;
	init(&head1);
	init(&head2);
	init(&head3);
	
	insert(&head1, 5);
	insert(&head1, 4);
	insert(&head1, 3);
	insert(&head1, 2);
	insert(&head1, 1);
	
	insert(&head2, 5);
	insert(&head2, 4);
	insert(&head2, 3);
	insert(&head2, 2);
	insert(&head2, 1);
	insert(&head2, 0);
	
	print(&head1);
	printf("\n");
	print(&head2);
	printf("\n");
	printf("\nidentical = %d", isIdentical(&head1, &head2));
	
	return 0;
}
