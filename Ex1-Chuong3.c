#include <stdio.h>
#include <stdlib.h>

typedef struct LinkNode
{
	// Define useful field of LinkNode
	int data;
	struct LinkNode * next;
}LinkNode;

LinkNode * getLinkNode(int data)
{
	// Create 
	LinkNode * ref = (LinkNode * ) malloc(sizeof(LinkNode));
	if (ref == NULL)
	{
		// fail 
		return NULL;
	}
	ref->data = data;
	ref->next = NULL;
	return ref;
}
typedef struct SingleLL
{
	struct LinkNode * head;
	struct LinkNode * tail;
}SingleLL;

SingleLL * getSingleLL()
{
	// Create dynamic memory of SingleLL
	SingleLL * ref = (SingleLL * ) malloc(sizeof(SingleLL));
	if (ref == NULL)
	{
		// Failed to create memory 
		return NULL;
	}
	// Set initial value
	ref->head = NULL;
	ref->tail = NULL;
	return ref;
}
void insert(SingleLL * ref, int data)
{
	LinkNode * node = getLinkNode(data);
	if (ref->head == NULL)
	{
		// Add first node
		ref->head = node;
	}
	else
	{
		// Add node at the end position
		ref->tail->next = node;
	}
	// New last node
	ref->tail = node;
}
// Display linked list element
void display(SingleLL * ref)
{
	if (ref->head == NULL)
	{
		return;
	}
	LinkNode * temp = ref->head;
	// iterating linked list elements
	while (temp != NULL)
	{
		printf(" %d ?", temp->data);
		// Visit to next node
		temp = temp->next;
	}
	printf(" NULL\n");
}
// Delete all even key nodes in linked list
void deleteEvenNodes(SingleLL * ref)
{
	// Define some auxiliary variables
	LinkNode * current = ref->head;
	LinkNode * auxiliary = NULL;
	LinkNode * back = NULL;
	// iterating linked list elements
	while (current != NULL)
	{
		if (current->data % 2 == 0)
		{
			// When get even node
			auxiliary = current;
		}
		else
		{
			back = current;
		}
		// Visit to next node
		current = current->next;
		if (auxiliary != NULL)
		{
			// When Deleted node exists
			if (ref->tail == auxiliary)
			{
				// Case A
				// When remove last node
				ref->tail = back;
			}
			if (back == NULL)
			{
				// Case B
				// When front node is even node
				// head visit to next node
				ref->head = current;
			}
			else
			{
				// Case C
				// Deleted node are exist in intermediate or 
				// last position of linked list.
				// Before delete node, 
				// there left node is connecting to 
				// next upcoming node.
				back->next = current;
			}
			// Unlink deleted node 
			auxiliary->next = NULL;
          	free(auxiliary);
			// free node
			auxiliary = NULL;
		}
	}
}
int main()
{
	SingleLL * sll = getSingleLL();
	// Add linked list node
	insert(sll, 2);
	insert(sll, 1);
	insert(sll, 5);
	insert(sll, 8);
	insert(sll, 7);
	insert(sll, 7);
	insert(sll, 4);
	insert(sll, 6);
	insert(sll, 10);
	// Before effect
	printf(" Before delete even key nodes\n");
	display(sll);
	// Perform delete operation
	deleteEvenNodes(sll);
	// After effect
	printf(" After delete even key nodes\n");
	display(sll);
} 
