#include "monty.h"

/**
 * printTopQ - This prints the top queue
 * @head: Store in the stack head
 * @counter: This holds the line number
*/
void printTopQ(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	bus.lifi = 1;
}

/**
 * addqueue - This add node to the tail stack
 * @n: Stores the new value
 * @head: This stores head of the stack
*/
void addQueue(stack_t **head, int n)
{
	stack_t *new_node, *subs;

	subs = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
	}
	new_node->n = n;
	new_node->next = NULL;
	if (subs)
	{
		while (subs->next)
			subs = subs->next;
	}
	if (!subs)
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		subs->next = new_node;
		new_node->prev = subs;
	}
}
