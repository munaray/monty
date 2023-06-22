#include "monty.h"

void doNothing(stack_t **head, unsigned int counter);
void pcharStack(stack_t **head, unsigned int counter);
void pstrStack(stack_t **head, unsigned int counter);
void rotlStack(stack_t **head, __attribute__((unused)) unsigned int counter);
void rotrStack(stack_t **head, __attribute__((unused)) unsigned int counter);

/* Task 5 implementing do Nothing */
/**
  *doNothing - does not do anything
  * @head: The stack head
  * @counter: The line number
 */
void doNothing(stack_t **head, unsigned int counter)
{
	(void) counter;
	(void) head;
}

/* Task 11 implementing the pchar */

/**
 * pcharStack - prints the char at the top of the stack,
 * followed by a new line
 * @head: The stack head
 * @counter: The line number
*/
void pcharStack(stack_t **head, unsigned int counter)
{
	stack_t *h;

	h = *head;
	if (!h)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", counter);
		fclose(bus.file);
		free(bus.content);
		freeStack(*head);
		exit(EXIT_FAILURE);
	}
	if (h->n > 127 || h->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", counter);
		fclose(bus.file);
		free(bus.content);
		freeStack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", h->n);
}

/* Task 12 prints stack strings */

/**
 * pstrStack - prints the string starting at the top of the stack,
 * followed by a new line.
 * @head: The stack head
 * @counter: The line number
*/
void pstrStack(stack_t **head, unsigned int counter)
{
	stack_t *h;
	(void)counter;

	h = *head;
	while (h)
	{
		if (h->n > 127 || h->n <= 0)
		{
			break;
		}
		printf("%c", h->n);
		h = h->next;
	}
	printf("\n");
}

/* Task 13 rotates stack to the top */

/**
  *rotlStack- rotates the stack to the top
  * @head: The stack head
  * @counter: The line number
 */
void rotlStack(stack_t **head,  __attribute__((unused)) unsigned int counter)
{
	stack_t *tmp = *head, *subs;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	subs = (*head)->next;
	subs->prev = NULL;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = *head;
	(*head)->next = NULL;
	(*head)->prev = tmp;
	(*head) = subs;
}

/* Task 14 rotates stack to the bottom */

/**
  *rotrStack- rotates the stack to the bottom
  * @head: The stack head
  * @counter: The line number
 */
void rotrStack(stack_t **head, __attribute__((unused)) unsigned int counter)
{
	stack_t *subs;

	subs = *head;
	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	while (subs->next)
	{
		subs = subs->next;
	}
	subs->next = *head;
	subs->prev->next = NULL;
	subs->prev = NULL;
	(*head)->prev = subs;
	(*head) = subs;
}
