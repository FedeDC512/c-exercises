#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
    pid_t pid;
    /* genera un nuovo processo */
    pid = fork();
    if (pid < 0)
    { /* errore */
        fprintf(stderr, "generazione del nuovo processo fallita");
        return 1;
    }
    else if (pid == 0)
    { /* processo figlio */
        execlp("/bin/ls", "ls", NULL);
    }
    else
    { /* processo genitore */
        /* il genitore attende il completamento del figlio */
        wait(NULL);
        printf("il processo figlio ha terminato");
    }
    return 0;
}