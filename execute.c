#include "shell.h"
/**
 * execute_command - Executes a command.
 * @args: Command and its arguments.
*/
void execute_command(char **args)
{
pid_t pid;
int status;
char *envp[] = { NULL };

if (strcmp(args[0], "exit") == 0)
{
if (args[1] != NULL)
{
printf("hsh: 1: exit: Illegal number: %s\n", args[1]);
return;
}
free(args);
exit(EXIT_SUCCESS);
}

pid = fork();
if (pid == -1)
{
perror("fork");
return;
}
else if (pid == 0)
{
char *command_path;
if (args[0][0] == '/')
{
command_path = args[0];
}
else
{
command_path = search_path(args[0]);
}

if (!command_path)
{
printf("%s: command not found\n", args[0]);
exit(EXIT_FAILURE);
}
execve(command_path, args, envp);
perror("execve");
exit(EXIT_FAILURE);
}
else
{
waitpid(pid, &status, 0);
}
}
