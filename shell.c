#include "shell.h"
/**
*/

int main(void)
{
char *line;
char **args;
int status;

do {
printf("$ ");
read_input(&line);
args = split_line(line);
status = execute_command(args);

free(line);
free(args);
} while (status);

return (EXIT_SUCCESS);
}
