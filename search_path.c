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
        char *full_path = malloc(strlen(token) + strlen(command) + 2);
        if (!full_path) {
            fprintf(stderr, "allocation error\n");
            exit(EXIT_FAILURE);
        }
        strcpy(full_path, token);
        strcat(full_path, "/");
        strcat(full_path, command);
        if (access(full_path, X_OK) == 0) {
            return (full_path);
        }
        free(full_path);
        token = strtok(NULL, ":");
    }
    return (NULL);
}
