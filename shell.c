#include "shell.h"
/**
*/

int main(void)
{
char *line;
char **args;

signal(SIGINT, handle_signal);
while (1) {
printf("$ ");
read_input(&line);
args = split_line(line);
execute_command(args);

free(line);
free(args);
}


return (EXIT_SUCCESS);
}
