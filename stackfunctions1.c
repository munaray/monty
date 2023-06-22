#include "monty.h"
void pushStack(stack_t **head, unsigned int counter);
void pallStack(stack_t **head, unsigned int counter);
void pintStack(stack_t **head, unsigned int counter);
void popStack(stack_t **head, unsigned int counter);
void swapStack(stack_t **head, unsigned int counter);

/* Task 0 push, pall stack */
/**
 * pushStack - To push an element to the stack
 * @head: The stack head
 * @counter: The line number
*/
void pushStack(stack_t **head, unsigned int counter)
{
	int i, j = 0, flag = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			j++;
		for (; bus.arg[j] != '\0'; j++)
		{
			if (bus.arg[j] > 57 || bus.arg[j] < 48)
				flag = 1; }
		if (flag == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(bus.file);
			free(bus.content);
			freeStack(*head);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(bus.file);
		free(bus.content);
		freeStack(*head);
		exit(EXIT_FAILURE); }
	i = atoi(bus.arg);
	if (bus.lifi == 0)
		addNode(head, i);
	else
		addQueue(head, i);
}


/**
 * pallStack - To prints the values on the stack
 * @head: The stack head
 * @counter: void
*/
void pallStack(stack_t **head, unsigned int counter)
{
	stack_t *h;
	(void)counter;

	h = *head;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}


/* Task 1 pint stack */
/**
 * pintStack - prints value at the top of the stack
 * @head: The stack head
 * @counter: The line number
*/
void pintStack(stack_t **head, unsigned int counter)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
		fclose(bus.file);
		free(bus.content);
		freeStack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}

/* Task 2 pop stack */

/**
 * popStack - To remove the top element of
 * the stack
 * @head: The stack head
 * @counter: The line number
*/
void popStack(stack_t **head, unsigned int counter)
{
	stack_t *h;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
		fclose(bus.file);
		free(bus.content);
		freeStack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	*head = h->next;
	free(h);
}

/* Task 3 swap stack */
/**
 * swapStack - To swap the top two elements of the stack.
 * @head: The stack head
 * @counter: The line number
*/
void swapStack(stack_t **head, unsigned int counter)
{
	stack_t *h;
	int len = 0, subs;

	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		freeStack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	subs = h->n;
	h->n = h->next->n;
	h->next->n = subs;
}
