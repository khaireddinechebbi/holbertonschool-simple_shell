#include "shell.h"
/**
*/
char *search_path(char *command) {
    char *path = getenv("PATH");
    char *token;
    if (!path) {
        perror("get_path");
        exit(EXIT_FAILURE);
    }
    token = strtok(path, ":");
    while (token != NULL) {
        char *full_path = malloc(MAX_COMMAND_LENGTH);
        snprintf(full_path, MAX_COMMAND_LENGTH, "%s/%s", token, command);
        if (access(full_path, X_OK) == 0) {
            return (full_path);
        }
        free(full_path);
        token = strtok(NULL, ":");
    }
    return (NULL);
}
