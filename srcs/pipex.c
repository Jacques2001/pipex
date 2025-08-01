#include "../libs/pipex.h"

int main(void)
{
    char *argv[] = {"/bin/ls", "-l", NULL};
    char *envp[] = {NULL};

    execve("/bin/ls", argv, envp);

    return 0; // Jamais atteint si execve réussit
}
