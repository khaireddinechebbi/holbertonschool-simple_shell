#include "shell.h"
/**
 * main - main function.
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure.
*/

int main(void)
{
char *line = NULL;
char **args;

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

if (strcmp(line, "exit") == 0)
{
exit(0);
break;
}

args = split_line(line);
execute_command(args);
free(line);
free(args);
if (!isatty(STDOUT_FILENO))
break;
}
return (EXIT_SUCCESS);
}
