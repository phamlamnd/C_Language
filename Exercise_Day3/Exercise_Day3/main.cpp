#include <iostream>
#include "LinkedList.h"
using namespace std;

int main()
{
	struct Node *head;
	init(&head);
	insert(&head, 5);
	insert(&head, 30);
	insert(&head, 3);
	insert(&head, 5);
	//insert(&head, 5);
	print(&head);
	cout << endl;
	cout << isPalindrome(&head);
	system("pause");
}