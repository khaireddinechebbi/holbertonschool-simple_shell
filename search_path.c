#include "shell.h"
/**
 * search_path - Searches for the full path of a command in the PATH environment variable.
 * @command: Command to search the full path for.
 * Return: Full path of the command if found, otherwise NULL.
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
