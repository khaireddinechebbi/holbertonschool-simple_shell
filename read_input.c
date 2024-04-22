#include "shell.h"


void read_input(char **input) {
    size_t bufsize = 0;
    ssize_t ret = getline(input, &bufsize, stdin);
    if (ret == -1) {
        if (feof(stdin)) {
            printf("\n");
            exit(EXIT_SUCCESS);
        } else {
            perror("read_input");
            exit(EXIT_FAILURE);
        }
    }
    (*input)[strcspn(*input, "\n")] = '\0';
}