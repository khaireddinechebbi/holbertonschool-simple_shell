#include "shell.h"
/**
* main - delimited string input
* Return: 0 successful
*/
int main(void)
{
size_t n = 0;
char *str = NULL;

printf("$ ");
getline(&str, &n, stdin);
printf("%s", str);
free(str);

return (0);
}