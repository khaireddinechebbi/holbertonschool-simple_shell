#include "shell.h"

void execute_command(char **args) {
    pid_t pid;
    int status;
    char *envp[] = { NULL };

    pid = fork();
    if (pid == -1) {
        perror("fork");
        return;
    } else if (pid == 0) {
        char *command_path;
        if (args[0][0] == '/') {
            command_path = args[0];
        } else {
            command_path = search_path(args[0]);
        }

        if (!command_path) {
            printf("%s: command not found\n", args[0]);
            exit(EXIT_FAILURE);
        }


        execve(command_path, args, envp);
        perror("execve");
        exit(EXIT_FAILURE);
    } else {
        waitpid(pid, &status, 0);
    }
}
