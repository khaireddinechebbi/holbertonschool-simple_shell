#include "shell.h"
/**
*/

int main(void)
{
char *line = NULL;
char **args;

while (1)
{
printf("$ ");
read_input(&line);

if (line == NULL) {
printf("\n");
exit(EXIT_SUCCESS);
}

if (strlen(line) == 0)
{
free(line);
continue;
}

args = split_line(line);
execute_command(args);

free(line);
free(args);
}


return (EXIT_SUCCESS);
}
