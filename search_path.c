#include "shell.h"
/**
 * 
*/

char *search_path(char *command)
{
char *path = getenv("PATH");
char *token;
char *full_path = NULL;

if (!path)
{
perror("getenv");
return (NULL);
}
token = strtok(path, ":");
while (token != NULL)
{
full_path = malloc(strlen(token) + strlen(command) + 2);
if (!full_path)
{
perror("malloc");
return (NULL);
}
strcpy(full_path, token);
strcat(full_path, "/");
strcat(full_path, command);
if (access(full_path, X_OK) == 0)
{
return (full_path);
}
free(full_path);
token = strtok(NULL, ":");
}
return (NULL);
}
