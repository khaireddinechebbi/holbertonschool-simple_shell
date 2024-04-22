#include "shell.h"
/**
*/
void handle_signal(int signum) {
    if (signum == SIGINT) {
        printf("\n");
        read_input(NULL);
    }
}
