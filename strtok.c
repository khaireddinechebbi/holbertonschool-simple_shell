#include "shell.h"
/**
* main - extract tokens from strings
* Return: 0 successful
*/
int main(void)
{
char *str = "this is cool";
char *stc = malloc(sizeof(char) * strlen(str));
char delim[5] = " ";
char *trunks;

strcpy(stc, str);
trunks = strtok(stc, delim);

while (trunks != NULL)
{
printf("%s\n", trunks);
trunks = strtok(NULL, delim);
}
return (0);
}
