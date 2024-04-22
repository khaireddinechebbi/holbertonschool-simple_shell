#include "shell.h"


void execute_command(char **args) {
    pid_t pid;
    int status;
    char *command_path = search_path(args[0]);
    
    if (!command_path) {
        printf("%s: command not found\n", args[0]);
        return;
    }

    pid = fork();
    if (pid == -1) {
        
        perror("fork");
        return;
    }
    else if (pid == 0) {
       
        execve(command_path, args, NULL);
        perror("execve");
        exit(EXIT_FAILURE);
        }
    else {

        waitpid(pid, &status, 0);
        free(command_path);
    }
}

