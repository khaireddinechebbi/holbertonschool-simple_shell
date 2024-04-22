#include "shell.h"


int execute_command(char **args) {
     pid_t pid;
    int status;

    pid = fork();
    if (pid < 0) {
        
        perror("fork");
        return (-1);
    }
    else if (pid == 0) {
       
        if (execve(args[0], args, NULL) == -1) {
            perror("execute_command");
            exit(EXIT_FAILURE);
        }
    }

    else {
        if (isatty(STDIN_FILENO))
        {
            waitpid(pid, &status, 0);
        }
        else
        {
            sleep(1);
            if (kill(pid, 0) == -1)
            {
                if (errno == ESRCH)
                {
                    exit(EXIT_SUCCESS);
                }
                else
                {
                    perror("kill");
                    exit(EXIT_FAILURE);
                }
            }
            
        }
    }

    return (1);
}
