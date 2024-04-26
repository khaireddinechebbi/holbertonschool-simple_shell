#include "shell.h"
/**
 * main - main function.
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure.
*/

int main(void)
{
char *line = NULL;
char **args;
char *commands;

while (1)
    {
        if (isatty(STDOUT_FILENO))
        {
            printf("$ ");
            fflush(stdout);
        }
        read_input(&line);
        if (strlen(line) == 0)
        {
            free(line);
            continue;
        }

        commands = strtok(line, "\n");
        while (commands != NULL)
        {
            args = split_line(commands);
            execute_command(args);
            free(args);
            commands = strtok(NULL, "\n");
        }

        free(line);
        if (!isatty(STDOUT_FILENO))
            break;
    }
    return (EXIT_SUCCESS);
}