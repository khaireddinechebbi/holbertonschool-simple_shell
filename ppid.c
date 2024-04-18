#include "shell.h"
/**
* main - getppid
* Retuen: 0 successful
*/
int main(void)
{
pid_t parent_pid;

parent_pid = getppid();
printf("Parent PID: %d\n", parent_pid);
return (0);
}
