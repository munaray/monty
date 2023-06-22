#include "monty.h"

/**
* freeStack - This frees a doubly linked list
* @head: The stack head
*/
void freeStack(stack_t *head)
{
	stack_t *subs;

	subs = head;
	while (head)
	{
		subs = head->next;
		free(head);
		head = subs;
	}
}

/**
 * printTopS - prints the top
 * @head: The stack head
 * @counter: The line number
*/
void printTopS(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	bus.lifi = 0;
}

/**
 * addNode - This add node to the head of the stack
 * @head: The stack head
 * @n: The new value
*/
void addNode(stack_t **head, int n)
{

	stack_t *newNode, *subs;

	subs = *head;
	newNode = malloc(sizeof(stack_t));
	if (newNode == NULL)
	{ printf("Error\n");
		exit(0); }
	if (subs)
		subs->prev = newNode;
	newNode->n = n;
	newNode->next = *head;
	newNode->prev = NULL;
	*head = newNode;
}
