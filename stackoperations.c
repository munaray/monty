#include "monty.h"

/* Task 4 add stack */
/**
 * addStack - adds the top two elements of the stack.
 * @head: The stack head
 * @counter: The line number
*/
void addStack(stack_t **head, unsigned int counter)
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
		fprintf(stderr, "L%d: can't add, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		freeStack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	subs = h->n + h->next->n;
	h->next->n = subs;
	*head = h->next;
	free(h);
}

/* Task 6 subtract stack */

/**
  *subStack- substracts the top element of the stack
  *from the second top element of the stack
  * @head: The stack head
 * @counter: The line number
 */
void subStack(stack_t **head, unsigned int counter)
{
	stack_t *subs;
	int sus, nodes;

	subs = *head;
	for (nodes = 0; subs != NULL; nodes++)
		subs = subs->next;
	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		freeStack(*head);
		exit(EXIT_FAILURE);
	}
	subs = *head;
	sus = subs->next->n - subs->n;
	subs->next->n = sus;
	*head = subs->next;
	free(subs);
}

/* Task 7 divides stack */

/**
 * divStack - divides the second top two elements of
 * the stack by the top element.
 * @head: The stack head
 * @counter: The line number
*/
void divStack(stack_t **head, unsigned int counter)
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
		fprintf(stderr, "L%d: can't div, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		freeStack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(bus.file);
		free(bus.content);
		freeStack(*head);
		exit(EXIT_FAILURE);
	}
	subs = h->next->n / h->n;
	h->next->n = subs;
	*head = h->next;
	free(h);
}

/* Task 8 Multiplying Stack */

/**
 * mulStack - multiplies the second top elements of the stack
 * with the top element of the stack.
 * @head: The stack head
 * @counter: The line number
*/
void mulStack(stack_t **head, unsigned int counter)
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
		fprintf(stderr, "L%d: can't mul, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		freeStack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	subs = h->next->n * h->n;
	h->next->n = subs;
	*head = h->next;
	free(h);
}


/* Task 9 Modulus Stack */

/**
 * modStack - computes the rest of the division of the second
 * top element of the stack by the top element of the stack
 * @head: The stack head
 * @counter: The line number
*/
void modStack(stack_t **head, unsigned int counter)
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
		fprintf(stderr, "L%d: can't mod, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		freeStack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(bus.file);
		free(bus.content);
		freeStack(*head);
		exit(EXIT_FAILURE);
	}
	subs = h->next->n % h->n;
	h->next->n = subs;
	*head = h->next;
	free(h);
}
