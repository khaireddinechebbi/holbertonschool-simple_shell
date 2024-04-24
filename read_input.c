#include "shell.h"
/**
 * 
*/

void read_input(char **input)
{
size_t bufsize = 0;
ssize_t ret = getline(input, &bufsize, stdin);
size_t len = strlen(*input);
if (ret == -1)
{
if (feof(stdin))
{
printf("\n");
exit(EXIT_SUCCESS);
}
else
{
perror("read_input");
exit(EXIT_FAILURE);
}
}
if ((*input)[len - 1] == '\n')
(*input)[len - 1] = '\0';
}