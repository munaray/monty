#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct bus_s - variables -args, file, line content
 * @arg: value
 * @file: pointer to monty file
 * @content: line content
 * @lifi: flag change stack <-> queue
 * Description: carries values through the program
 */
typedef struct bus_s
{
	char *arg;
	FILE *file;
	char *content;
	int lifi;
}  bus_t;
extern bus_t bus;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
/* stackfunctions1 */
void pushStack(stack_t **head, unsigned int counter);
void pallStack(stack_t **head, unsigned int counter);
void pintStack(stack_t **head, unsigned int counter);
void popStack(stack_t **head, unsigned int counter);
void swapStack(stack_t **head, unsigned int counter);

/* stackfunctions2 */
void doNothing(stack_t **head, unsigned int counter);
void pcharStack(stack_t **head, unsigned int counter);
void pstrStack(stack_t **head, unsigned int counter);
void rotlStack(stack_t **head, __attribute__((unused)) unsigned int counter);
void rotrStack(stack_t **head, __attribute__((unused)) unsigned int counter);

/* stackfunctions3 */
void freeStack(stack_t *head);
void printTopS(stack_t **head, unsigned int counter);
void addNode(stack_t **head, int n);

/* stackoperations */
void addStack(stack_t **head, unsigned int counter);
void subStack(stack_t **head, unsigned int counter);
void divStack(stack_t **head, unsigned int counter);
void mulStack(stack_t **head, unsigned int counter);
void modStack(stack_t **head, unsigned int counter);

/* queuefunctions */
void printTopQ(stack_t **head, unsigned int counter);
void addQueue(stack_t **head, int n);

/* executehandler */
int execute(char *content, stack_t **stack, unsigned int counter, FILE *file);
#endif
