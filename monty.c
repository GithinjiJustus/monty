#include "monty.h"

/* Define the global variable */
global_var var_global;

/**
 * main - Entry point for the Monty program
 * @ac: Number of arguments
 * @av: Array of arguments
 * Return: 0 on success, EXIT_FAILURE on failure
 */
int main(int ac, char **av)
{
    stack_t *stack;

    stack = NULL;

    /* Check for the correct number of arguments */
    if (ac != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    /* Read and process Monty bytecodes from the specified file */
    if (!read_file(av[1], &stack))
    {
        fprintf(stderr, "Error reading file: %s\n", av[1]);
        free_dlistint(stack);
        exit(EXIT_FAILURE);
    }

    /* Remember to free allocated memory */
    free_dlistint(stack);

    return (0);
}
