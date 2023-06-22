#include "monty.h"
/**
* execute - The executes the opcode
* @stack: head linked list - stack
* @counter:  The line counter
* @file: This point to monty file
* @content: line content
* Return: 1 on success
*/
int execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t opst[] = {
				{"push", pushStack}, {"pall", pallStack}, {"pint", pintStack},
				{"pop", popStack},
				{"swap", swapStack},
				{"add", addStack},
				{"nop", doNothing},
				{"sub", subStack},
				{"div", divStack},
				{"mul", mulStack},
				{"mod", modStack},
				{"pchar", pcharStack},
				{"pstr", pstrStack},
				{"rotl", rotlStack},
				{"rotr", rotrStack},
				{"queue", printTopQ},
				{"stack", printTopS},
				{NULL, NULL}
				};
	unsigned int i = 0;
	char *op;

	op = strtok(content, " \n\t");
	/* Implementing the comments */
	if (op && op[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{	opst[i].f(stack, counter);
			return (0);
		}
		i++;
	}
	if (op && opst[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
		fclose(file);
		free(content);
		freeStack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}
