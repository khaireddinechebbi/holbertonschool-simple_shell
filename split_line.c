#include "shell.h"
/**
 * split_line - Splits a line into tokens.
 * @line: Line to be split.
 * Return: Array of tokens.
*/

char **split_line(char *line)
{
int bufsize = LSH_TOK_BUFSIZE, position = 0;
char **tokens = malloc(bufsize * sizeof(char*));
char *token;
int len;
if (!tokens)
{
fprintf(stderr, "allocation error\n");
exit(EXIT_FAILURE);
}
token = strtok(line, " ");
while (token != NULL)
{
while (*token == ' ' || *token == '\t')
{
token++;
}
len = strlen(token);
while (len > 0 && (token[len - 1] == ' ' || token[len - 1] == '\t'))
{
token[--len] = '\0';
}
tokens[position] = token;
position++;

if (position >= bufsize)
{
bufsize += LSH_TOK_BUFSIZE;
tokens = realloc(tokens, bufsize * sizeof(char *));
if (!tokens)
{
fprintf(stderr, "allocation error\n");
exit(EXIT_FAILURE);
}
}

token = strtok(NULL, " ");
}
tokens[position] = NULL;
return (tokens);
}
